/********************************************************************************
** Form generated from reading UI file 'AddSnow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSNOW_H
#define UI_ADDSNOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddSnowClass
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *ext;

    void setupUi(QDialog *AddSnowClass)
    {
        if (AddSnowClass->objectName().isEmpty())
            AddSnowClass->setObjectName(QString::fromUtf8("AddSnowClass"));
        AddSnowClass->resize(300, 100);
        AddSnowClass->setMinimumSize(QSize(300, 100));
        AddSnowClass->setMaximumSize(QSize(300, 100));
        AddSnowClass->setModal(true);
        gridLayout = new QGridLayout(AddSnowClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(AddSnowClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AddSnowClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ext = new QDoubleSpinBox(AddSnowClass);
        ext->setObjectName(QString::fromUtf8("ext"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ext->sizePolicy().hasHeightForWidth());
        ext->setSizePolicy(sizePolicy);
        ext->setMinimumSize(QSize(0, 20));
        ext->setMaximumSize(QSize(16777215, 20));
        ext->setMaximum(1.000000000000000);
        ext->setSingleStep(0.010000000000000);
        ext->setValue(0.800000000000000);

        horizontalLayout->addWidget(ext);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(AddSnowClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddSnowClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddSnowClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddSnowClass);
    } // setupUi

    void retranslateUi(QDialog *AddSnowClass)
    {
        AddSnowClass->setWindowTitle(QApplication::translate("AddSnowClass", "\345\212\240\351\233\252\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("AddSnowClass", "ext\345\217\202\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSnowClass: public Ui_AddSnowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSNOW_H
