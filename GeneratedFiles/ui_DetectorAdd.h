/********************************************************************************
** Form generated from reading UI file 'DetectorAdd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORADD_H
#define UI_DETECTORADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DetectorAddClass
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *le_name;
    QLabel *label_5;
    QComboBox *le_device;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_pbPath;
    QPushButton *pb_select;
    QRadioButton *derainer_select;
    QRadioButton *dehaze_select;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *detector_select;
    QLabel *label_3;
    QDoubleSpinBox *dsb_confidence;
    QLabel *label_4;
    QDoubleSpinBox *dsb_NMS;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DetectorAddClass)
    {
        if (DetectorAddClass->objectName().isEmpty())
            DetectorAddClass->setObjectName(QString::fromUtf8("DetectorAddClass"));
        DetectorAddClass->resize(505, 210);
        DetectorAddClass->setMinimumSize(QSize(505, 210));
        DetectorAddClass->setMaximumSize(QSize(505, 210));
        DetectorAddClass->setModal(true);
        verticalLayout = new QVBoxLayout(DetectorAddClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(DetectorAddClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        le_name = new QLineEdit(DetectorAddClass);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_name->sizePolicy().hasHeightForWidth());
        le_name->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(le_name);

        label_5 = new QLabel(DetectorAddClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_5);

        le_device = new QComboBox(DetectorAddClass);
        le_device->setObjectName(QString::fromUtf8("le_device"));
        sizePolicy.setHeightForWidth(le_device->sizePolicy().hasHeightForWidth());
        le_device->setSizePolicy(sizePolicy);
        le_device->setMaxVisibleItems(30);
        le_device->setIconSize(QSize(12, 12));
        le_device->setDuplicatesEnabled(false);
        le_device->setFrame(true);

        horizontalLayout_3->addWidget(le_device);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);

        label = new QLabel(DetectorAddClass);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        le_pbPath = new QLineEdit(DetectorAddClass);
        le_pbPath->setObjectName(QString::fromUtf8("le_pbPath"));
        sizePolicy1.setHeightForWidth(le_pbPath->sizePolicy().hasHeightForWidth());
        le_pbPath->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(le_pbPath);

        pb_select = new QPushButton(DetectorAddClass);
        pb_select->setObjectName(QString::fromUtf8("pb_select"));
        sizePolicy.setHeightForWidth(pb_select->sizePolicy().hasHeightForWidth());
        pb_select->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pb_select);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);


        verticalLayout->addLayout(formLayout);

        derainer_select = new QRadioButton(DetectorAddClass);
        derainer_select->setObjectName(QString::fromUtf8("derainer_select"));

        verticalLayout->addWidget(derainer_select);

        dehaze_select = new QRadioButton(DetectorAddClass);
        dehaze_select->setObjectName(QString::fromUtf8("dehaze_select"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dehaze_select->sizePolicy().hasHeightForWidth());
        dehaze_select->setSizePolicy(sizePolicy2);
        dehaze_select->setChecked(false);

        verticalLayout->addWidget(dehaze_select);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        detector_select = new QRadioButton(DetectorAddClass);
        detector_select->setObjectName(QString::fromUtf8("detector_select"));
        detector_select->setChecked(true);

        horizontalLayout_5->addWidget(detector_select);

        label_3 = new QLabel(DetectorAddClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_3);

        dsb_confidence = new QDoubleSpinBox(DetectorAddClass);
        dsb_confidence->setObjectName(QString::fromUtf8("dsb_confidence"));
        sizePolicy2.setHeightForWidth(dsb_confidence->sizePolicy().hasHeightForWidth());
        dsb_confidence->setSizePolicy(sizePolicy2);
        dsb_confidence->setMinimumSize(QSize(0, 20));
        dsb_confidence->setMaximum(1.000000000000000);
        dsb_confidence->setSingleStep(0.010000000000000);
        dsb_confidence->setValue(0.800000000000000);

        horizontalLayout_5->addWidget(dsb_confidence);

        label_4 = new QLabel(DetectorAddClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_4);

        dsb_NMS = new QDoubleSpinBox(DetectorAddClass);
        dsb_NMS->setObjectName(QString::fromUtf8("dsb_NMS"));
        sizePolicy2.setHeightForWidth(dsb_NMS->sizePolicy().hasHeightForWidth());
        dsb_NMS->setSizePolicy(sizePolicy2);
        dsb_NMS->setMinimumSize(QSize(0, 20));
        dsb_NMS->setMaximum(1.000000000000000);
        dsb_NMS->setSingleStep(0.010000000000000);
        dsb_NMS->setValue(0.100000000000000);

        horizontalLayout_5->addWidget(dsb_NMS);


        verticalLayout->addLayout(horizontalLayout_5);

        buttonBox = new QDialogButtonBox(DetectorAddClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DetectorAddClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), DetectorAddClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DetectorAddClass, SLOT(reject()));
        QObject::connect(detector_select, SIGNAL(toggled(bool)), dsb_confidence, SLOT(setEnabled(bool)));
        QObject::connect(detector_select, SIGNAL(toggled(bool)), dsb_NMS, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(DetectorAddClass);
    } // setupUi

    void retranslateUi(QDialog *DetectorAddClass)
    {
        DetectorAddClass->setWindowTitle(QApplication::translate("DetectorAddClass", "\346\267\273\345\212\240\346\243\200\346\265\213\345\231\250", nullptr));
        label_2->setText(QApplication::translate("DetectorAddClass", "\346\250\241\345\236\213\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("DetectorAddClass", "\350\277\220\347\256\227\347\241\254\344\273\266\357\274\232", nullptr));
        label->setText(QApplication::translate("DetectorAddClass", "pb\346\250\241\345\236\213\346\226\207\344\273\266\357\274\232", nullptr));
        pb_select->setText(QApplication::translate("DetectorAddClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        derainer_select->setText(QApplication::translate("DetectorAddClass", "\345\216\273\351\233\250\346\250\241\345\235\227", nullptr));
        dehaze_select->setText(QApplication::translate("DetectorAddClass", "\345\216\273\351\233\276\346\250\241\345\235\227", nullptr));
        detector_select->setText(QApplication::translate("DetectorAddClass", "\346\243\200\346\265\213\345\231\250\346\250\241\345\235\227", nullptr));
        label_3->setText(QApplication::translate("DetectorAddClass", "\347\275\256\344\277\241\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        label_4->setText(QApplication::translate("DetectorAddClass", "\351\235\236\346\236\201\345\244\247\345\200\274\346\212\221\345\210\266\351\230\210\345\200\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectorAddClass: public Ui_DetectorAddClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORADD_H
