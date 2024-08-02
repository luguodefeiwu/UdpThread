#include "editsystem.h"
#include "ui_editsystem.h"

EditSystem::EditSystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSystem)
{
    ui->setupUi(this);
    initialize();
}

EditSystem::~EditSystem()
{
    delete ui;
}

systemDataSetting EditSystem::getSystemDataSetting()
{
    return db;
}

//修改系统
void EditSystem::reviseSetting(systemDataSetting setting)
{
    db = setting;

    //初始化系统
    ui->lineEdit_SystemName->setText(db.systemName);
    ui->lineEdit_ListenPort->setText(QString::number(db.localPort));
    ui->lineEdit_TargetIP->setText(db.targetIP);
    ui->lineEdit_TargetPort->setText(QString::number(db.targetPort));

    ui->tableWidget_Recv->setRowCount(db.recvDataName.count());
    ui->tableWidget_Send->setRowCount(db.sendDataName.count());

    for (int i = 0; i < db.recvDataName.count(); i++)
    {
        createRecvRow(db.recvDataName.at(i), db.recvDataType.at(i));
        recvRows++;
    }

    for (int i = 0; i < db.sendDataName.count(); i++)
    {
        createSendRow(db.sendDataName.at(i), db.sendDataSource.at(i), db.sendData.at(i));
        sendRows++;
    }

    ui->lineEdit_SystemName->setEnabled(false);
}

//初始化
void EditSystem::initialize()
{
    recvRows = 0;
    sendRows = 0;

    //初始化接收数据的表格
    ui->tableWidget_Recv->setColumnCount(2);
    headItem = new QTableWidgetItem("参数名");
    ui->tableWidget_Recv->setHorizontalHeaderItem(0, headItem);
    headItem = new QTableWidgetItem("参数类型");
    ui->tableWidget_Recv->setHorizontalHeaderItem(1, headItem);

    //初始化发送数据的表格
    ui->tableWidget_Send->setColumnCount(3);
    headItem = new QTableWidgetItem("参数名");
    ui->tableWidget_Send->setHorizontalHeaderItem(0, headItem);
    headItem = new QTableWidgetItem("来源系统");
    ui->tableWidget_Send->setHorizontalHeaderItem(1, headItem);
    headItem = new QTableWidgetItem("对应数据");
    ui->tableWidget_Send->setHorizontalHeaderItem(2, headItem);

    //初始化数据源
    QStringList dataSource;
    QList<systemDataSetting> dataList = readSystemDataFromSettings(getSettingsFilePath());
    for (const systemDataSetting &data : dataList)
        dataSource << data.systemName;

    ui->comboBox_SourceSystem->clear();
    ui->comboBox_SourceSystem->addItems(dataSource);
}

//添加新的接收数据
void EditSystem::on_pushBtn_AddRecv_clicked()
{
    //获取当前参数名和所有的参数名 用于判断参数名是否为空或者重复
    QString recvDataName = ui->lineEdit_RecvName->text();
    QStringList recvDataNamList;
    for (int i = 0; i < ui->tableWidget_Recv->rowCount(); i++)
        recvDataNamList << ui->tableWidget_Recv->item(i, 0)->text();

    if (recvDataName.isEmpty() || recvDataNamList.contains(recvDataName))
    {
        QMessageBox::warning(this, "警告", "当前参数名为空或重复！");
        return ;
    }
    else
    {
        QString recvName = ui->lineEdit_RecvName->text();
        QString recvType = ui->comboBox_RecvType->currentText();

        int rows = ui->tableWidget_Recv->rowCount();
        ui->tableWidget_Recv->setRowCount(rows + 1);

//        //将用户编辑的数据填入db
//        db.recvDataName << recvName;
//        db.recvDataType << recvType;

        createRecvRow(recvName, recvType);
        recvRows ++;
    }
}

//创建接收数据的表格
void EditSystem::createRecvRow(QString name, QString type)
{
    item = new QTableWidgetItem(name);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_Recv->setItem(recvRows, 0, item);

    item = new QTableWidgetItem(type);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_Recv->setItem(recvRows, 1, item);
}

//创建发送数据的表格
void EditSystem::createSendRow(QString name, QString source, QString Data)
{
    item = new QTableWidgetItem(name);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_Send->setItem(sendRows, 0, item);

    item = new QTableWidgetItem(source);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_Send->setItem(sendRows, 1, item);

    item = new QTableWidgetItem(Data);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    ui->tableWidget_Send->setItem(sendRows, 2, item);
}

//删除当前选中的接收数据
void EditSystem::on_pushBtn_DeleteRecv_clicked()
{
    if (recvRows <= 0)
    {
        QMessageBox::warning(this, "警告", "当前无可删除参数！");
        return ;
    }
    else
    {
        ui->tableWidget_Recv->removeRow(ui->tableWidget_Recv->currentRow());
        recvRows --;
    }
}

//添加发送参数
void EditSystem::on_pushBtn_AddSend_clicked()
{
    QString sendDataName = ui->lineEdit_SendName->text();
    QStringList sendDataNameList;
    for (int i = 0; i < ui->tableWidget_Send->rowCount(); i++)
        sendDataNameList << ui->tableWidget_Send->item(i,0)->text();

    if (sendDataName.isEmpty() || sendDataNameList.contains(sendDataName))
    {
        QMessageBox::warning(this, "警告", "参数名为空或重复！");
        return;
    }
    else
    {
        QString sendName = ui->lineEdit_SendName->text();
        QString sendSource = ui->comboBox_SourceSystem->currentText();
        QString sendData = ui->comboBox_SourceData->currentText();

        int rows = ui->tableWidget_Send->rowCount();
        ui->tableWidget_Send->setRowCount(rows + 1);

//        //将用户编辑的数据填入db
//        db.sendDataName << sendName;
//        db.sendDataSource << sendSource;
//        db.sendData << sendData;

        createSendRow(sendName, sendSource, sendData);
        sendRows ++;
    }
}

//删除选中的发送参数
void EditSystem::on_pushBtn_DeleteSend_clicked()
{
    if(sendRows <= 0)
    {
        QMessageBox::warning(this, "警告", "当前无可删除参数！");
        return ;
    }
    else
    {
        ui->tableWidget_Send->removeRow(ui->tableWidget_Send->currentRow());
        sendRows--;
    }
}

//确定按钮
void EditSystem::on_pushBtn_Confirm_clicked()
{
    if (ui->lineEdit_SystemName->text().isEmpty() ||
            ui->lineEdit_ListenPort->text().isEmpty() ||
            ui->lineEdit_TargetIP->text().isEmpty() ||
            ui->lineEdit_TargetPort->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "系统配置存在空字符串！");
        return ;
    }
    else
    {
        QMessageBox::information(this, "提示",
                                "系统名：" + ui->lineEdit_SystemName->text() +
                                "\n本地端口：" + ui->lineEdit_ListenPort->text() +
                                "\n目标地址：" + ui->lineEdit_TargetIP->text() +
                                "\n目标端口：" + ui->lineEdit_TargetPort->text());

        db.systemName = ui->lineEdit_SystemName->text();
        db.localPort = ui->lineEdit_ListenPort->text().toUInt();
        db.targetIP = ui->lineEdit_TargetIP->text();
        db.targetPort = ui->lineEdit_TargetPort->text().toUInt();

        //将之前的数据清空
        db.recvDataName.clear();
        db.recvDataType.clear();
        db.sendDataName.clear();
        db.sendDataSource.clear();
        db.sendData.clear();

        //遍历表格中的数据填入db
        for (int i = 0; i < ui->tableWidget_Recv->rowCount(); i++)
            db.recvDataName << ui->tableWidget_Recv->item(i, 0)->text();

        for (int i = 0; i < ui->tableWidget_Recv->rowCount(); i++)
            db.recvDataType << ui->tableWidget_Recv->item(i, 1)->text();

        for (int i = 0; i < ui->tableWidget_Send->rowCount(); i++)
            db.sendDataName << ui->tableWidget_Send->item(i, 0)->text();

        for (int i = 0; i < ui->tableWidget_Send->rowCount(); i++)
            db.sendDataSource << ui->tableWidget_Send->item(i, 1)->text();

        for (int i = 0; i < ui->tableWidget_Send->rowCount(); i++)
            db.sendData << ui->tableWidget_Send->item(i, 2)->text();
    }



    this->accept();
}

//取消按钮
void EditSystem::on_pushBtn_Cancel_clicked()
{
    this->reject();
}

void EditSystem::on_comboBox_SourceSystem_currentIndexChanged(const QString &arg1)
{
    systemDataSetting currentSystemSetting = searchSystemDataSetting(arg1);

    ui->comboBox_SourceData->clear();
    ui->comboBox_SourceData->addItems(currentSystemSetting.recvDataName);
}
