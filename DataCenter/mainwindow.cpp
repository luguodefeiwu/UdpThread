#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    jsonSocket = new QUdpSocket(this);
    sendSocket = new QUdpSocket(this);
    fileName = "config.dat";
    this->setWindowTitle("数据中心");

    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//系统初始化
void MainWindow::initialize()
{
    //读取配置文件，初始化主系统
    mainData = readMainStructFromFile(fileName);
    ui->lineEdit_ListenPort->setText(QString::number(mainData.listenPort));
    ui->lineEdit_TargetIP->setText(mainData.targetIP);
    ui->lineEdit_TargetPort->setText(QString::number(mainData.targetPort));

    //配置接收Json文件的方法
    if (jsonSocket->bind(mainData.listenPort))
    {
        qDebug() << "绑定成功：" << mainData.listenPort;
        connect(jsonSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    }
    else
    {
        qDebug() << "绑定失败";
    }

    ui->mainTabWidget->setVisible(false);
    setWindowState(Qt::WindowMaximized);

    //初始化缓冲区大小
    recvBufferLength = 0;
    QList<systemDataSetting> dataList = readSystemDataFromSettings(getSettingsFilePath());
    for (const systemDataSetting &data : dataList)
    {
        int currentLength = calculateAlignenSize(data.recvDataType);
        recvBufferLength += currentLength;
    }
    recvBuffer.resize(recvBufferLength);
    recvBuffer.fill(0);

    offset = 0;                                                                         //初始偏移量为0
    qDebug() << "****** 初始化mainWindow recvBuffer 长度为： " << recvBufferLength;
    for (const systemDataSetting &data : dataList)
    {
        qDebug() << "System Name:" << data.systemName;
        qDebug() << "Local Port:" << data.localPort;
        qDebug() << "Target IP:" << data.targetIP;
        qDebug() << "Target Port:" << data.targetPort;
        qDebug() << "Recv Data Names:" << data.recvDataName;
        qDebug() << "Recv Data Types:" << data.recvDataType;
        qDebug() << "Send Data Names:" << data.sendDataName;
        qDebug() << "Send Data Sources:" << data.sendDataSource;
        qDebug() << "Send Data:" << data.sendData;

        int currentlength = calculateAlignenSize(data.recvDataType);
        currentBuffer = recvBuffer.data() + offset;
        createNewSystem(currentBuffer, offset, currentlength, data);
        offset += currentlength;
    }
}

void MainWindow::createNewSystem(char *buffer,int startAddress, int len, systemDataSetting data)
{
    qDebug() << "****** 初始化showNewSystem ******";
    ShowSystem *newSystem = new ShowSystem(buffer, len, data, this);
    newSystem->setStartAddress(startAddress);

    int current = ui->mainTabWidget->addTab(newSystem, data.systemName);
    ui->mainTabWidget->setCurrentIndex(current);
    ui->mainTabWidget->setVisible(true);

    connect(newSystem, SIGNAL(haveRecvData(bool)), this, SLOT(showNewData(bool)));
    connect(newSystem, SIGNAL(closeCurrentTab(ShowSystem*)), this, SLOT(closeTab(ShowSystem*)));
}

void MainWindow::setSendData()
{
    sendRecvBuffer();

    int systemCount = ui->mainTabWidget->count();

    // 用哈希表替代 QStringList
    QHash<QString, int> systemNameMap;
    for (int i = 0; i < systemCount; ++i) {
        systemNameMap[ui->mainTabWidget->tabText(i)] = i;
    }
    qDebug() << systemNameMap.keys();

    for (int i = 0; i < systemCount; ++i)
    {
        ShowSystem *currentSystem = getWidgetFromTab<ShowSystem>(ui->mainTabWidget, i);
        QStringList sendDataType;
        for (int j = 0; j < currentSystem->getDB().sendDataName.count(); ++j)
        {
            QString sendDataSource = currentSystem->getDB().sendDataSource.at(j);
            if (!systemNameMap.contains(sendDataSource)) {
                qDebug() << "数据源不存在";
                continue;
            }

            int systemNum = systemNameMap[sendDataSource];
            ShowSystem *dataSourceSystem = getWidgetFromTab<ShowSystem>(ui->mainTabWidget, systemNum);

            QString dataName = currentSystem->getDB().sendData.at(j);
            int dataIndex = dataSourceSystem->getDB().recvDataName.indexOf(dataName);
            if (dataIndex < 0) {
                qDebug() << "数据名不存在";
                continue;
            }
            qDebug() << "数据下标 " << dataIndex;

            QString dataType = dataSourceSystem->getDB().recvDataType.at(dataIndex);
            sendDataType << dataType;
            int dataAddress = dataSourceSystem->getStartAddress() + calculateAlignenSize(dataSourceSystem->getDB().recvDataType.mid(0, dataIndex));
            qDebug() << "dataAddress:" << dataAddress << " dataType:" << dataType << " dataLength:" << getTypeSize(dataType);

            sendBuffer.append(recvBuffer.mid(dataAddress, getTypeSize(dataType)));
        }

        qDebug() << "sendBuffer.length : " << sendBuffer.length();

        currentSystem->setSendData(sendBuffer, sendDataType);
        sendBuffer.clear();
    }
}

void MainWindow::sendRecvBuffer()
{
    sendSocket->writeDatagram(recvBuffer, QHostAddress(mainData.targetIP), mainData.targetPort);
}

//重启
void MainWindow::restart()
{
    qDebug() << "restart()";

    int systemCount = ui->mainTabWidget->count();
    QHash<QString, int> systemNameMap;
    for (int i = 0; i < systemCount; ++i) {
        systemNameMap[ui->mainTabWidget->tabText(i)] = i;
    }
    for (int i = 0; i < systemCount; i++)
    {
        ShowSystem *currentSystem = getWidgetFromTab<ShowSystem>(ui->mainTabWidget, i);
        qDebug() << currentSystem->getDB().systemName << "Close";
        currentSystem->closeAllThread();
    }

    // 获取当前应用程序的路径
    QString applicationPath = QCoreApplication::applicationFilePath();

    // 获取当前应用程序的工作目录
    QString workingDirectory = QDir::currentPath();

    // 构建命令行参数
    QStringList arguments = QCoreApplication::arguments();

    // 启动新进程
    QProcess *process = new QProcess();
    process->setWorkingDirectory(workingDirectory);
    process->startDetached(applicationPath, arguments);

    // 退出当前应用程序
    QCoreApplication::quit();
}

void MainWindow::on_action_Exit_triggered()
{
    QApplication::quit();//关闭整个应用程序
}

//创建新的系统
void MainWindow::on_action_CreateSystem_triggered()
{
    dialog = new EditSystem(this);

    int flag = dialog->exec();

    if (flag == QDialog::Accepted)
    {
        //向配置文件地址 写入用户编写的系统配置
        writeSystemDataToSettings(getSettingsFilePath(), dialog->getSystemDataSetting());

        QMessageBox::information(this, "提醒", "添加系统重启后生效");

        return ;
    }

    delete dialog;
}

//获取当前页面数量
void MainWindow::on_mainTabWidget_currentChanged(int index)
{
    qDebug() << "当前页面索引" << index;

    bool en = ui->mainTabWidget->count() > 0;
    ui->mainTabWidget->setVisible(en);
}

//展现新数据
void MainWindow::showNewData(bool flag)
{
    if (flag)
    {
         setSendData();
    }
}

void MainWindow::closeTab(ShowSystem *system)
{
    int index = ui->mainTabWidget->indexOf(system);

    if (index != -1)
    {
        qDebug() << "closeTab Index:" << index;
        QWidget* tab = ui->mainTabWidget->widget(index);
        ui->mainTabWidget->removeTab(index);
        qDebug() << "移除页面： " << index;
        tab->close();
    }
}

void MainWindow::processPendingDatagrams()
{
    if (jsonSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(jsonSocket->pendingDatagramSize());
        jsonSocket->readDatagram(datagram.data(), datagram.size());

        qDebug() << "Received datagram: " << datagram;

        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram, &parseError);

        if (parseError.error != QJsonParseError::NoError)
        {
            qWarning() << "Failed to parse JSON: " << parseError.errorString();
            return ;
        }

        qDebug() << "Parsed JSON: " << jsonDoc.toJson(QJsonDocument::Indented);
        saveJsonToFile(jsonDoc);
        qDebug() << "接收到数据看板数据";
        restart();
    }
}

void MainWindow::on_pushBtn_Listen_clicked()
{
    quint16 listenPort = ui->lineEdit_ListenPort->text().toUInt();
    QString targetIP = ui->lineEdit_TargetIP->text();
    quint16 targetPort = ui->lineEdit_TargetPort->text().toUInt();

    mainData.listenPort = listenPort;
    mainData.targetIP = targetIP;
    mainData.targetPort = targetPort;

    if (writeMainStructToFile(mainData, "config.dat"))
    {
        QMessageBox::information(this, "提示", "data written to file successfully");
    }
    else
    {
        QMessageBox::information(this, "提示", "failed to write data to file");
    }
}
