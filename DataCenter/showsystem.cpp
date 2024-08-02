#include "showsystem.h"
#include "ui_showsystem.h"

ShowSystem::ShowSystem(char* buffer, int length, systemDataSetting setting, QWidget *parent) :
    recvBuffer(buffer),
    recvBufferLength(length),
    db(setting),
    QMainWindow(parent),
    ui(new Ui::ShowSystem)
{
    ui->setupUi(this);

    initialize();                   //初始化UI页面
    setSystemData();                //初始化系统各项数据
    initializeNet();
}

ShowSystem::~ShowSystem()
{
    closeAllThread();
    delete ui;
}

//初始化UI是否可编辑 初始化表格列数和表头
void ShowSystem::initialize()
{
    ui->lineEdit_ListenPort->setEnabled(false);
    ui->lineEdit_TargetIP->setEnabled(false);
    ui->lineEdit_TargetPort->setEnabled(false);

    ui->tableWidget_Recv->setColumnCount(2);
    ui->tableWidget_Send->setColumnCount(3);

    headItem = new QTableWidgetItem("数据类型");
    ui->tableWidget_Recv->setHorizontalHeaderItem(0, headItem);
    headItem = new QTableWidgetItem("当前数据");
    ui->tableWidget_Recv->setHorizontalHeaderItem(1, headItem);

    headItem = new QTableWidgetItem("数据来源");
    ui->tableWidget_Send->setHorizontalHeaderItem(0, headItem);
    headItem = new QTableWidgetItem("数据原名");
    ui->tableWidget_Send->setHorizontalHeaderItem(1, headItem);
    headItem = new QTableWidgetItem("当前数据");
    ui->tableWidget_Send->setHorizontalHeaderItem(2, headItem);
}

//初始化系统配置数据
void ShowSystem::setSystemData()
{
    ui->lineEdit_ListenPort->setText(QString::number(db.localPort));
    ui->lineEdit_TargetIP->setText(db.targetIP);
    ui->lineEdit_TargetPort->setText(QString::number(db.targetPort));

    int recvDataNum = db.recvDataName.count();
    int sendDataNum = db.sendDataName.count();
    ui->tableWidget_Recv->setRowCount(recvDataNum);
    ui->tableWidget_Send->setRowCount(sendDataNum);

    for (int i = 0; i < recvDataNum; i++)
    {
        headItem = new QTableWidgetItem(db.recvDataName.at(i));
        ui->tableWidget_Recv->setVerticalHeaderItem(i, headItem);

        item = new QTableWidgetItem(db.recvDataType.at(i));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_Recv->setItem(i, 0, item);
    }

    for (int i = 0; i < sendDataNum; i++)
    {
        headItem = new QTableWidgetItem(db.sendDataName.at(i));
        ui->tableWidget_Send->setVerticalHeaderItem(i, headItem);

        item = new QTableWidgetItem(db.sendDataSource.at(i));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_Send->setItem(i, 0, item);

        item = new QTableWidgetItem(db.sendData.at(i));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget_Send->setItem(i, 1, item);
    }
}

//初始化网络配置
void ShowSystem::initializeNet()
{
    recvThread = new UdpRecvThread(db.localPort , recvBuffer, recvBufferLength, this);
    recvThread->start();
    connect(recvThread, SIGNAL(haveRecvData(bool)), this, SLOT(showRecvData(bool)));    //接收到数据显示
    connect(this, &ShowSystem::dataProcessed, this, &ShowSystem::updateTableWidget);    //接收到数据时更新表格

    sendThread = new UdpSendThread(db.targetIP, db.targetPort, this);
    sendThread->setSendBuffer(sendBuffer);
    sendThread->setFlag(true);
    sendThread->start();
}

//获取发送数据信息和数据类型
void ShowSystem::setSendData(QByteArray buffer, QStringList dataType)
{
    sendBuffer = buffer;
    emit dataProcessed(sendBuffer, dataType);
}

void ShowSystem::setStartAddress(int address)
{
    startAddress = address;
}

int ShowSystem::getRecvDatalength()
{
    return recvBufferLength;
}

int ShowSystem::getStartAddress()
{
    return startAddress;
}

systemDataSetting ShowSystem::getDB()
{
    return db;
}

void ShowSystem::closeAllThread()
{
    recvThread->stop();
    sendThread->stop();
}

//修改系统
void ShowSystem::on_pushBtn_ReviseSystem_clicked()
{
    EditSystem *dialog = new EditSystem(this);
    dialog->reviseSetting(db);

    int flag = dialog->exec();
    if (flag == QDialog::Accepted)
    {
        //更新配置文件中对应的数据
        updateSystemDataInSettings(getSettingsFilePath(), dialog->getSystemDataSetting());
        //设置成修改后的数据
        QMessageBox::information(this, "提示", "系统修改后重启才能生效");
        //发出文件被修改的信号
        emit reviseSetting(true);
    }
    delete dialog;
}

//删除当前系统
void ShowSystem::on_pushButton_clicked()
{
    DialogTip *tip = new DialogTip(this);
    int flag = tip->exec();

    if (flag == QDialog::Accepted)
    {
        deleteSystemDataByName(getSettingsFilePath(), db.systemName);
        QMessageBox::information(this, "提示", "请手动删除各个系统对应的数据后重启系统");
        emit reviseSetting(true);
        emit closeCurrentTab(this);
    }
    delete tip;
}

//打印buffer 发送有数据的信号
void ShowSystem::showRecvData(bool flag)
{
    QByteArray thisbuffer(recvBuffer, recvBufferLength);

    if (!thisbuffer.isEmpty())
    {
        qDebug() << "****** 处理showSystem槽函数数据 ******";

        list = processData(thisbuffer, db.recvDataType);

        for (int i = 0; i < list.length(); i++)
        {
            item = new QTableWidgetItem(list.at(i).toString());
            ui->tableWidget_Recv->setItem(i, 1, item);
        }
    }
    emit haveRecvData(flag);
}

//更新表格数据
void ShowSystem::updateTableWidget(QByteArray sendBuffer, QStringList dataType)
{
    sendThread->setSendBuffer(sendBuffer);
    QList<QVariant> sendDataList = processData(sendBuffer, dataType);

    for (int i = 0; i < sendDataList.length(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(sendDataList.at(i).toString());
        ui->tableWidget_Send->setItem(i, 2, item);
    }
}
