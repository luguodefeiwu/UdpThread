#ifndef EDITSYSTEM_H
#define EDITSYSTEM_H

#include <QMessageBox>
#include <QDialog>
#include <QTableWidget>
#include "database.h"

namespace Ui {
class EditSystem;
}

class EditSystem : public QDialog
{
    Q_OBJECT
public:
    explicit EditSystem(QWidget *parent = 0);
    ~EditSystem();
    systemDataSetting getSystemDataSetting();
    void reviseSetting(systemDataSetting setting);

private slots:
    void on_pushBtn_AddRecv_clicked();

    void on_pushBtn_DeleteRecv_clicked();

    void on_pushBtn_AddSend_clicked();

    void on_pushBtn_DeleteSend_clicked();

    void on_pushBtn_Confirm_clicked();

    void on_pushBtn_Cancel_clicked();

    void on_comboBox_SourceSystem_currentIndexChanged(const QString &arg1);

private:
    void createRecvRow(QString name, QString type);
    void createSendRow(QString name, QString source, QString Data);
    void initialize();

private:
    Ui::EditSystem *ui;
    systemDataSetting db;
    int recvRows;
    int sendRows;
    QTableWidgetItem *item;
    QTableWidgetItem *headItem;
};

#endif // EDITSYSTEM_H
