/********************************************************************************
** Form generated from reading UI file 'editsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSYSTEM_H
#define UI_EDITSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditSystem
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_SystemName;
    QLineEdit *lineEdit_SystemName;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_ListenPort;
    QLineEdit *lineEdit_ListenPort;
    QLabel *label_TargetIP;
    QLineEdit *lineEdit_TargetIP;
    QLabel *label_TargetPort;
    QLineEdit *lineEdit_TargetPort;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_RecvName;
    QLineEdit *lineEdit_RecvName;
    QLabel *label_RecvType;
    QComboBox *comboBox_RecvType;
    QPushButton *pushBtn_AddRecv;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushBtn_DeleteRecv;
    QTableWidget *tableWidget_Recv;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_SendName;
    QLineEdit *lineEdit_SendName;
    QLabel *label_SourceSystem;
    QComboBox *comboBox_SourceSystem;
    QLabel *label_SourceData;
    QComboBox *comboBox_SourceData;
    QPushButton *pushBtn_AddSend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushBtn_DeleteSend;
    QTableWidget *tableWidget_Send;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushBtn_Confirm;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushBtn_Cancel;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *EditSystem)
    {
        if (EditSystem->objectName().isEmpty())
            EditSystem->setObjectName(QStringLiteral("EditSystem"));
        EditSystem->resize(1000, 689);
        horizontalLayout = new QHBoxLayout(EditSystem);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(EditSystem);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(220, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_SystemName = new QLabel(groupBox);
        label_SystemName->setObjectName(QStringLiteral("label_SystemName"));

        gridLayout_2->addWidget(label_SystemName, 0, 0, 1, 1);

        lineEdit_SystemName = new QLineEdit(groupBox);
        lineEdit_SystemName->setObjectName(QStringLiteral("lineEdit_SystemName"));

        gridLayout_2->addWidget(lineEdit_SystemName, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 246, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ListenPort = new QLabel(groupBox_2);
        label_ListenPort->setObjectName(QStringLiteral("label_ListenPort"));

        gridLayout->addWidget(label_ListenPort, 0, 0, 1, 1);

        lineEdit_ListenPort = new QLineEdit(groupBox_2);
        lineEdit_ListenPort->setObjectName(QStringLiteral("lineEdit_ListenPort"));

        gridLayout->addWidget(lineEdit_ListenPort, 0, 1, 1, 1);

        label_TargetIP = new QLabel(groupBox_2);
        label_TargetIP->setObjectName(QStringLiteral("label_TargetIP"));

        gridLayout->addWidget(label_TargetIP, 1, 0, 1, 1);

        lineEdit_TargetIP = new QLineEdit(groupBox_2);
        lineEdit_TargetIP->setObjectName(QStringLiteral("lineEdit_TargetIP"));

        gridLayout->addWidget(lineEdit_TargetIP, 1, 1, 1, 1);

        label_TargetPort = new QLabel(groupBox_2);
        label_TargetPort->setObjectName(QStringLiteral("label_TargetPort"));

        gridLayout->addWidget(label_TargetPort, 2, 0, 1, 1);

        lineEdit_TargetPort = new QLineEdit(groupBox_2);
        lineEdit_TargetPort->setObjectName(QStringLiteral("lineEdit_TargetPort"));

        gridLayout->addWidget(lineEdit_TargetPort, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 2, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 245, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(EditSystem);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_RecvName = new QLabel(groupBox_3);
        label_RecvName->setObjectName(QStringLiteral("label_RecvName"));

        gridLayout_3->addWidget(label_RecvName, 0, 0, 1, 1);

        lineEdit_RecvName = new QLineEdit(groupBox_3);
        lineEdit_RecvName->setObjectName(QStringLiteral("lineEdit_RecvName"));

        gridLayout_3->addWidget(lineEdit_RecvName, 0, 1, 1, 2);

        label_RecvType = new QLabel(groupBox_3);
        label_RecvType->setObjectName(QStringLiteral("label_RecvType"));

        gridLayout_3->addWidget(label_RecvType, 1, 0, 1, 1);

        comboBox_RecvType = new QComboBox(groupBox_3);
        comboBox_RecvType->setObjectName(QStringLiteral("comboBox_RecvType"));

        gridLayout_3->addWidget(comboBox_RecvType, 1, 1, 1, 2);

        pushBtn_AddRecv = new QPushButton(groupBox_3);
        pushBtn_AddRecv->setObjectName(QStringLiteral("pushBtn_AddRecv"));

        gridLayout_3->addWidget(pushBtn_AddRecv, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushBtn_DeleteRecv = new QPushButton(groupBox_3);
        pushBtn_DeleteRecv->setObjectName(QStringLiteral("pushBtn_DeleteRecv"));

        gridLayout_3->addWidget(pushBtn_DeleteRecv, 2, 2, 1, 1);

        tableWidget_Recv = new QTableWidget(groupBox_3);
        tableWidget_Recv->setObjectName(QStringLiteral("tableWidget_Recv"));

        gridLayout_3->addWidget(tableWidget_Recv, 3, 0, 1, 3);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(EditSystem);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_SendName = new QLabel(groupBox_4);
        label_SendName->setObjectName(QStringLiteral("label_SendName"));

        gridLayout_4->addWidget(label_SendName, 0, 0, 1, 1);

        lineEdit_SendName = new QLineEdit(groupBox_4);
        lineEdit_SendName->setObjectName(QStringLiteral("lineEdit_SendName"));

        gridLayout_4->addWidget(lineEdit_SendName, 0, 1, 1, 2);

        label_SourceSystem = new QLabel(groupBox_4);
        label_SourceSystem->setObjectName(QStringLiteral("label_SourceSystem"));

        gridLayout_4->addWidget(label_SourceSystem, 1, 0, 1, 1);

        comboBox_SourceSystem = new QComboBox(groupBox_4);
        comboBox_SourceSystem->setObjectName(QStringLiteral("comboBox_SourceSystem"));

        gridLayout_4->addWidget(comboBox_SourceSystem, 1, 1, 1, 2);

        label_SourceData = new QLabel(groupBox_4);
        label_SourceData->setObjectName(QStringLiteral("label_SourceData"));

        gridLayout_4->addWidget(label_SourceData, 2, 0, 1, 1);

        comboBox_SourceData = new QComboBox(groupBox_4);
        comboBox_SourceData->setObjectName(QStringLiteral("comboBox_SourceData"));

        gridLayout_4->addWidget(comboBox_SourceData, 2, 1, 1, 2);

        pushBtn_AddSend = new QPushButton(groupBox_4);
        pushBtn_AddSend->setObjectName(QStringLiteral("pushBtn_AddSend"));

        gridLayout_4->addWidget(pushBtn_AddSend, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(143, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        pushBtn_DeleteSend = new QPushButton(groupBox_4);
        pushBtn_DeleteSend->setObjectName(QStringLiteral("pushBtn_DeleteSend"));

        gridLayout_4->addWidget(pushBtn_DeleteSend, 3, 2, 1, 1);

        tableWidget_Send = new QTableWidget(groupBox_4);
        tableWidget_Send->setObjectName(QStringLiteral("tableWidget_Send"));

        gridLayout_4->addWidget(tableWidget_Send, 4, 0, 1, 3);


        horizontalLayout->addWidget(groupBox_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        pushBtn_Confirm = new QPushButton(EditSystem);
        pushBtn_Confirm->setObjectName(QStringLiteral("pushBtn_Confirm"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/704.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushBtn_Confirm->setIcon(icon);

        verticalLayout->addWidget(pushBtn_Confirm);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        pushBtn_Cancel = new QPushButton(EditSystem);
        pushBtn_Cancel->setObjectName(QStringLiteral("pushBtn_Cancel"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushBtn_Cancel->setIcon(icon1);

        verticalLayout->addWidget(pushBtn_Cancel);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(EditSystem);

        QMetaObject::connectSlotsByName(EditSystem);
    } // setupUi

    void retranslateUi(QDialog *EditSystem)
    {
        EditSystem->setWindowTitle(QApplication::translate("EditSystem", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("EditSystem", "\347\263\273\347\273\237\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        label_SystemName->setText(QApplication::translate("EditSystem", "\347\263\273\347\273\237\345\220\215\347\247\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("EditSystem", "\347\275\221\347\273\234\351\205\215\347\275\256", Q_NULLPTR));
        label_ListenPort->setText(QApplication::translate("EditSystem", "\346\234\254\345\234\260\347\253\257\345\217\243", Q_NULLPTR));
        label_TargetIP->setText(QApplication::translate("EditSystem", "\347\233\256\346\240\207\345\234\260\345\235\200", Q_NULLPTR));
        label_TargetPort->setText(QApplication::translate("EditSystem", "\347\233\256\346\240\207\347\253\257\345\217\243", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("EditSystem", "\346\216\245\346\224\266\345\217\202\346\225\260", Q_NULLPTR));
        label_RecvName->setText(QApplication::translate("EditSystem", "\346\216\245\346\224\266\345\217\202\346\225\260\345\220\215", Q_NULLPTR));
        label_RecvType->setText(QApplication::translate("EditSystem", "\345\217\202\346\225\260\347\261\273\345\236\213", Q_NULLPTR));
        comboBox_RecvType->clear();
        comboBox_RecvType->insertItems(0, QStringList()
         << QApplication::translate("EditSystem", "short", Q_NULLPTR)
         << QApplication::translate("EditSystem", "int", Q_NULLPTR)
         << QApplication::translate("EditSystem", "long", Q_NULLPTR)
         << QApplication::translate("EditSystem", "float", Q_NULLPTR)
         << QApplication::translate("EditSystem", "double", Q_NULLPTR)
         << QApplication::translate("EditSystem", "bool", Q_NULLPTR)
        );
        pushBtn_AddRecv->setText(QApplication::translate("EditSystem", "\346\267\273\345\212\240", Q_NULLPTR));
        pushBtn_DeleteRecv->setText(QApplication::translate("EditSystem", "\345\210\240\351\231\244\351\200\211\344\270\255\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("EditSystem", "\345\217\221\351\200\201\345\217\202\346\225\260", Q_NULLPTR));
        label_SendName->setText(QApplication::translate("EditSystem", "\345\217\221\351\200\201\345\217\202\346\225\260\345\220\215", Q_NULLPTR));
        label_SourceSystem->setText(QApplication::translate("EditSystem", "\346\225\260\346\215\256\346\235\245\346\272\220\347\263\273\347\273\237", Q_NULLPTR));
        label_SourceData->setText(QApplication::translate("EditSystem", "\345\257\271\345\272\224\345\217\202\346\225\260", Q_NULLPTR));
        pushBtn_AddSend->setText(QApplication::translate("EditSystem", "\346\267\273\345\212\240", Q_NULLPTR));
        pushBtn_DeleteSend->setText(QApplication::translate("EditSystem", "\345\210\240\351\231\244\351\200\211\344\270\255\345\217\202\346\225\260", Q_NULLPTR));
        pushBtn_Confirm->setText(QApplication::translate("EditSystem", "\347\241\256\345\256\232", Q_NULLPTR));
        pushBtn_Cancel->setText(QApplication::translate("EditSystem", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditSystem: public Ui_EditSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSYSTEM_H
