/********************************************************************************
** Form generated from reading UI file 'AddFog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFOG_H
#define UI_ADDFOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddFogClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *beta;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddFogClass)
    {
        if (AddFogClass->objectName().isEmpty())
            AddFogClass->setObjectName(QString::fromUtf8("AddFogClass"));
        AddFogClass->resize(300, 101);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddFogClass->sizePolicy().hasHeightForWidth());
        AddFogClass->setSizePolicy(sizePolicy);
        AddFogClass->setMinimumSize(QSize(300, 100));
        AddFogClass->setMaximumSize(QSize(300, 101));
        AddFogClass->setModal(true);
        gridLayout = new QGridLayout(AddFogClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AddFogClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label);

        beta = new QDoubleSpinBox(AddFogClass);
        beta->setObjectName(QString::fromUtf8("beta"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(beta->sizePolicy().hasHeightForWidth());
        beta->setSizePolicy(sizePolicy1);
        beta->setMinimumSize(QSize(0, 20));
        beta->setMaximumSize(QSize(16777215, 20));
        beta->setMinimum(0.010000000000000);
        beta->setMaximum(0.990000000000000);
        beta->setSingleStep(0.010000000000000);
        beta->setValue(0.800000000000000);

        horizontalLayout->addWidget(beta);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddFogClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(AddFogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddFogClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddFogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddFogClass);
    } // setupUi

    void retranslateUi(QDialog *AddFogClass)
    {
        AddFogClass->setWindowTitle(QApplication::translate("AddFogClass", "\345\212\240\351\233\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("AddFogClass", "beta\345\217\202\346\225\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFogClass: public Ui_AddFogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFOG_H
