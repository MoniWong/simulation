/********************************************************************************
** Form generated from reading UI file 'AddRain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRAIN_H
#define UI_ADDRAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddRainClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_pbPath;
    QPushButton *pb_select;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *alpha;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddRainClass)
    {
        if (AddRainClass->objectName().isEmpty())
            AddRainClass->setObjectName(QString::fromUtf8("AddRainClass"));
        AddRainClass->setWindowModality(Qt::WindowModal);
        AddRainClass->resize(300, 100);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddRainClass->sizePolicy().hasHeightForWidth());
        AddRainClass->setSizePolicy(sizePolicy);
        AddRainClass->setMinimumSize(QSize(300, 100));
        AddRainClass->setMaximumSize(QSize(300, 100));
        AddRainClass->setModal(true);
        verticalLayout = new QVBoxLayout(AddRainClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(AddRainClass);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(AddRainClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        le_pbPath = new QLineEdit(AddRainClass);
        le_pbPath->setObjectName(QString::fromUtf8("le_pbPath"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(le_pbPath->sizePolicy().hasHeightForWidth());
        le_pbPath->setSizePolicy(sizePolicy2);
        le_pbPath->setMinimumSize(QSize(0, 20));
        le_pbPath->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(le_pbPath);

        pb_select = new QPushButton(AddRainClass);
        pb_select->setObjectName(QString::fromUtf8("pb_select"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pb_select->sizePolicy().hasHeightForWidth());
        pb_select->setSizePolicy(sizePolicy3);
        pb_select->setMinimumSize(QSize(0, 20));
        pb_select->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(pb_select);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        alpha = new QDoubleSpinBox(AddRainClass);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(alpha->sizePolicy().hasHeightForWidth());
        alpha->setSizePolicy(sizePolicy4);
        alpha->setMinimumSize(QSize(0, 20));
        alpha->setMaximumSize(QSize(16777215, 20));
        alpha->setMaximum(1.000000000000000);
        alpha->setSingleStep(0.010000000000000);
        alpha->setValue(0.800000000000000);

        horizontalLayout->addWidget(alpha);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(AddRainClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddRainClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddRainClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddRainClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddRainClass);
    } // setupUi

    void retranslateUi(QDialog *AddRainClass)
    {
        AddRainClass->setWindowTitle(QApplication::translate("AddRainClass", "\345\212\240\351\233\250\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("AddRainClass", "\351\233\250\346\273\264\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        label_3->setText(QApplication::translate("AddRainClass", "alpha\345\217\202\346\225\260\357\274\232", nullptr));
        pb_select->setText(QApplication::translate("AddRainClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRainClass: public Ui_AddRainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRAIN_H
