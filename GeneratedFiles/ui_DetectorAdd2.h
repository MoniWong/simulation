/********************************************************************************
** Form generated from reading UI file 'DetectorAdd2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORADD2_H
#define UI_DETECTORADD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *le_name_2;
    QLabel *label_6;
    QComboBox *le_device_2;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *le_pbPath_2;
    QPushButton *pb_select_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *dehaze_select_2;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *detector_select_2;
    QLabel *label_9;
    QDoubleSpinBox *dsb_confidence_2;
    QLabel *label_10;
    QDoubleSpinBox *dsb_NMS_2;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_OK;
    QPushButton *pb_Cancel;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 133);
        Form->setMinimumSize(QSize(400, 130));
        Form->setMaximumSize(QSize(400, 133));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_3);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_4);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        le_name_2 = new QLineEdit(Form);
        le_name_2->setObjectName(QString::fromUtf8("le_name_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_name_2->sizePolicy().hasHeightForWidth());
        le_name_2->setSizePolicy(sizePolicy1);
        le_name_2->setMinimumSize(QSize(0, 20));
        le_name_2->setMaximumSize(QSize(180, 20));

        horizontalLayout_6->addWidget(le_name_2);

        label_6 = new QLabel(Form);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(67, 16777215));
        label_6->setTextFormat(Qt::AutoText);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        le_device_2 = new QComboBox(Form);
        le_device_2->setObjectName(QString::fromUtf8("le_device_2"));
        le_device_2->setMaxVisibleItems(10);
        le_device_2->setIconSize(QSize(12, 12));
        le_device_2->setDuplicatesEnabled(false);
        le_device_2->setFrame(true);

        horizontalLayout_6->addWidget(le_device_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        le_pbPath_2 = new QLineEdit(Form);
        le_pbPath_2->setObjectName(QString::fromUtf8("le_pbPath_2"));
        sizePolicy1.setHeightForWidth(le_pbPath_2->sizePolicy().hasHeightForWidth());
        le_pbPath_2->setSizePolicy(sizePolicy1);
        le_pbPath_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(le_pbPath_2);

        pb_select_2 = new QPushButton(Form);
        pb_select_2->setObjectName(QString::fromUtf8("pb_select_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pb_select_2->sizePolicy().hasHeightForWidth());
        pb_select_2->setSizePolicy(sizePolicy2);
        pb_select_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_7->addWidget(pb_select_2);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        dehaze_select_2 = new QRadioButton(Form);
        dehaze_select_2->setObjectName(QString::fromUtf8("dehaze_select_2"));
        dehaze_select_2->setChecked(false);

        verticalLayout_7->addWidget(dehaze_select_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        detector_select_2 = new QRadioButton(Form);
        detector_select_2->setObjectName(QString::fromUtf8("detector_select_2"));
        detector_select_2->setChecked(true);

        horizontalLayout_10->addWidget(detector_select_2);

        label_9 = new QLabel(Form);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_9);

        dsb_confidence_2 = new QDoubleSpinBox(Form);
        dsb_confidence_2->setObjectName(QString::fromUtf8("dsb_confidence_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dsb_confidence_2->sizePolicy().hasHeightForWidth());
        dsb_confidence_2->setSizePolicy(sizePolicy3);
        dsb_confidence_2->setMinimumSize(QSize(0, 20));
        dsb_confidence_2->setMaximumSize(QSize(16777215, 20));
        dsb_confidence_2->setMaximum(1.000000000000000);
        dsb_confidence_2->setSingleStep(0.010000000000000);
        dsb_confidence_2->setValue(0.800000000000000);

        horizontalLayout_10->addWidget(dsb_confidence_2);

        label_10 = new QLabel(Form);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(label_10);

        dsb_NMS_2 = new QDoubleSpinBox(Form);
        dsb_NMS_2->setObjectName(QString::fromUtf8("dsb_NMS_2"));
        sizePolicy3.setHeightForWidth(dsb_NMS_2->sizePolicy().hasHeightForWidth());
        dsb_NMS_2->setSizePolicy(sizePolicy3);
        dsb_NMS_2->setMinimumSize(QSize(0, 20));
        dsb_NMS_2->setMaximumSize(QSize(16777215, 20));
        dsb_NMS_2->setMaximum(1.000000000000000);
        dsb_NMS_2->setSingleStep(0.010000000000000);
        dsb_NMS_2->setValue(0.100000000000000);

        horizontalLayout_10->addWidget(dsb_NMS_2);


        verticalLayout_7->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(verticalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        pb_OK = new QPushButton(Form);
        pb_OK->setObjectName(QString::fromUtf8("pb_OK"));

        horizontalLayout_11->addWidget(pb_OK);

        pb_Cancel = new QPushButton(Form);
        pb_Cancel->setObjectName(QString::fromUtf8("pb_Cancel"));

        horizontalLayout_11->addWidget(pb_Cancel);


        verticalLayout->addLayout(horizontalLayout_11);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        label_3->setText(QApplication::translate("Form", "\346\250\241\345\236\213\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Form", "pb\346\250\241\345\236\213\346\226\207\344\273\266\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Form", "\350\277\220\347\256\227\347\241\254\344\273\266\357\274\232", nullptr));
        pb_select_2->setText(QApplication::translate("Form", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        dehaze_select_2->setText(QApplication::translate("Form", "\345\216\273\351\233\276\346\250\241\345\235\227", nullptr));
        detector_select_2->setText(QApplication::translate("Form", "\346\243\200\346\265\213\345\231\250\346\250\241\345\235\227", nullptr));
        label_9->setText(QApplication::translate("Form", "\347\275\256\344\277\241\345\272\246\351\230\210\345\200\274\357\274\232", nullptr));
        label_10->setText(QApplication::translate("Form", "\351\235\236\346\236\201\345\244\247\345\200\274\346\212\221\345\210\266\351\230\210\345\200\274\357\274\232", nullptr));
        pb_OK->setText(QApplication::translate("Form", "OK", nullptr));
        pb_Cancel->setText(QApplication::translate("Form", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORADD2_H
