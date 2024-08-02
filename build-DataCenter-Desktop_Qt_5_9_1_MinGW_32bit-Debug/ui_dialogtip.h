/********************************************************************************
** Form generated from reading UI file 'dialogtip.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTIP_H
#define UI_DIALOGTIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogTip
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogTip)
    {
        if (DialogTip->objectName().isEmpty())
            DialogTip->setObjectName(QStringLiteral("DialogTip"));
        DialogTip->resize(387, 171);
        verticalLayout = new QVBoxLayout(DialogTip);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogTip);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(DialogTip);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogTip);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTip, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTip, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTip);
    } // setupUi

    void retranslateUi(QDialog *DialogTip)
    {
        DialogTip->setWindowTitle(QApplication::translate("DialogTip", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogTip", "\346\230\257\345\220\246\345\205\263\351\227\255\350\257\245\347\263\273\347\273\237\357\274\237\345\205\263\351\227\255\345\220\216\345\260\206\345\220\214\346\255\245\345\210\240\351\231\244\350\257\245\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogTip: public Ui_DialogTip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTIP_H
