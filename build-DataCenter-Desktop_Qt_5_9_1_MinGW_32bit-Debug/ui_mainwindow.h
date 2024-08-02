/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QAction *action_CreateSystem;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ListenPort;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *lineEdit_TargetIP;
    QLabel *label_3;
    QLineEdit *lineEdit_TargetPort;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushBtn_Listen;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *mainTabWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1059, 667);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon);
        action_CreateSystem = new QAction(MainWindow);
        action_CreateSystem->setObjectName(QStringLiteral("action_CreateSystem"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/images/804.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_CreateSystem->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 70));
        groupBox->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_ListenPort = new QLineEdit(groupBox);
        lineEdit_ListenPort->setObjectName(QStringLiteral("lineEdit_ListenPort"));

        horizontalLayout->addWidget(lineEdit_ListenPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_TargetIP = new QLineEdit(groupBox);
        lineEdit_TargetIP->setObjectName(QStringLiteral("lineEdit_TargetIP"));

        horizontalLayout->addWidget(lineEdit_TargetIP);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_TargetPort = new QLineEdit(groupBox);
        lineEdit_TargetPort->setObjectName(QStringLiteral("lineEdit_TargetPort"));

        horizontalLayout->addWidget(lineEdit_TargetPort);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushBtn_Listen = new QPushButton(groupBox);
        pushBtn_Listen->setObjectName(QStringLiteral("pushBtn_Listen"));
        pushBtn_Listen->setMinimumSize(QSize(0, 0));
        pushBtn_Listen->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/images/104.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushBtn_Listen->setIcon(icon2);

        horizontalLayout->addWidget(pushBtn_Listen);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(groupBox);

        mainTabWidget = new QTabWidget(centralWidget);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));

        verticalLayout->addWidget(mainTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1059, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(action_CreateSystem);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_Exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_Exit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_CreateSystem->setText(QApplication::translate("MainWindow", "\346\226\260\345\242\236\347\263\273\347\273\237", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_CreateSystem->setToolTip(QApplication::translate("MainWindow", "\345\210\233\345\273\272\347\263\273\347\273\237", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237\344\270\273\344\275\223\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ListenPort", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TargetIP", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TargetPort", Q_NULLPTR));
        pushBtn_Listen->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
