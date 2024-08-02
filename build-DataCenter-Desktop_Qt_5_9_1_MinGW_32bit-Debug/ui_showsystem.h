/********************************************************************************
** Form generated from reading UI file 'showsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWSYSTEM_H
#define UI_SHOWSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowSystem
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_TargetIP;
    QLabel *label_TargetPort;
    QLabel *label_LocalPort;
    QLineEdit *lineEdit_ListenPort;
    QLineEdit *lineEdit_TargetIP;
    QLineEdit *lineEdit_TargetPort;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushBtn_ReviseSystem;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_Recv;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget_Send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowSystem)
    {
        if (ShowSystem->objectName().isEmpty())
            ShowSystem->setObjectName(QStringLiteral("ShowSystem"));
        ShowSystem->resize(865, 650);
        centralwidget = new QWidget(ShowSystem);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(220, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_TargetIP = new QLabel(groupBox);
        label_TargetIP->setObjectName(QStringLiteral("label_TargetIP"));

        gridLayout->addWidget(label_TargetIP, 1, 0, 1, 1);

        label_TargetPort = new QLabel(groupBox);
        label_TargetPort->setObjectName(QStringLiteral("label_TargetPort"));

        gridLayout->addWidget(label_TargetPort, 2, 0, 1, 1);

        label_LocalPort = new QLabel(groupBox);
        label_LocalPort->setObjectName(QStringLiteral("label_LocalPort"));

        gridLayout->addWidget(label_LocalPort, 0, 0, 1, 1);

        lineEdit_ListenPort = new QLineEdit(groupBox);
        lineEdit_ListenPort->setObjectName(QStringLiteral("lineEdit_ListenPort"));

        gridLayout->addWidget(lineEdit_ListenPort, 0, 2, 1, 1);

        lineEdit_TargetIP = new QLineEdit(groupBox);
        lineEdit_TargetIP->setObjectName(QStringLiteral("lineEdit_TargetIP"));

        gridLayout->addWidget(lineEdit_TargetIP, 1, 2, 1, 1);

        lineEdit_TargetPort = new QLineEdit(groupBox);
        lineEdit_TargetPort->setObjectName(QStringLiteral("lineEdit_TargetPort"));

        gridLayout->addWidget(lineEdit_TargetPort, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 416, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/706.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        gridLayout->addWidget(pushButton, 5, 0, 1, 3);

        pushBtn_ReviseSystem = new QPushButton(groupBox);
        pushBtn_ReviseSystem->setObjectName(QStringLiteral("pushBtn_ReviseSystem"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushBtn_ReviseSystem->setIcon(icon1);

        gridLayout->addWidget(pushBtn_ReviseSystem, 4, 0, 1, 3);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget_Recv = new QTableWidget(groupBox_2);
        tableWidget_Recv->setObjectName(QStringLiteral("tableWidget_Recv"));

        gridLayout_2->addWidget(tableWidget_Recv, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget_Send = new QTableWidget(groupBox_3);
        tableWidget_Send->setObjectName(QStringLiteral("tableWidget_Send"));

        gridLayout_3->addWidget(tableWidget_Send, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        ShowSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowSystem);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 865, 23));
        ShowSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowSystem);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ShowSystem->setStatusBar(statusbar);

        retranslateUi(ShowSystem);

        QMetaObject::connectSlotsByName(ShowSystem);
    } // setupUi

    void retranslateUi(QMainWindow *ShowSystem)
    {
        ShowSystem->setWindowTitle(QApplication::translate("ShowSystem", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ShowSystem", "\347\263\273\347\273\237\344\277\241\346\201\257", Q_NULLPTR));
        label_TargetIP->setText(QApplication::translate("ShowSystem", "\347\233\256\346\240\207\345\234\260\345\235\200", Q_NULLPTR));
        label_TargetPort->setText(QApplication::translate("ShowSystem", "\347\233\256\346\240\207\347\253\257\345\217\243", Q_NULLPTR));
        label_LocalPort->setText(QApplication::translate("ShowSystem", "\344\276\246\345\220\254\347\253\257\345\217\243", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ShowSystem", "\345\210\240\351\231\244\345\275\223\345\211\215\347\263\273\347\273\237", Q_NULLPTR));
        pushBtn_ReviseSystem->setText(QApplication::translate("ShowSystem", "\344\277\256\346\224\271\347\263\273\347\273\237\344\277\241\346\201\257", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ShowSystem", "\346\216\245\346\224\266\346\225\260\346\215\256", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ShowSystem", "\345\217\221\351\200\201\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowSystem: public Ui_ShowSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWSYSTEM_H
