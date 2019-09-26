/********************************************************************************
** Form generated from reading UI file 'ProcessList.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSLIST_H
#define UI_PROCESSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessListClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cB_addFog;
    QGroupBox *gB_addFog;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *fog_para;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cB_addRain;
    QGroupBox *gB_addRain;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *rain_path;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *rain_para;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cB_addSnow;
    QGroupBox *gB_addSnow;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *snow_para;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QComboBox *Picnum;
    QGroupBox *gB_evaIndex;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLineEdit *PSNR;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *SSIM;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pB_do;

    void setupUi(QWidget *ProcessListClass)
    {
        if (ProcessListClass->objectName().isEmpty())
            ProcessListClass->setObjectName(QString::fromUtf8("ProcessListClass"));
        ProcessListClass->resize(270, 377);
        verticalLayout_2 = new QVBoxLayout(ProcessListClass);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        cB_addFog = new QCheckBox(ProcessListClass);
        cB_addFog->setObjectName(QString::fromUtf8("cB_addFog"));

        verticalLayout_2->addWidget(cB_addFog);

        gB_addFog = new QGroupBox(ProcessListClass);
        gB_addFog->setObjectName(QString::fromUtf8("gB_addFog"));
        gB_addFog->setEnabled(false);
        horizontalLayout = new QHBoxLayout(gB_addFog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(gB_addFog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fog_para = new QDoubleSpinBox(gB_addFog);
        fog_para->setObjectName(QString::fromUtf8("fog_para"));
        fog_para->setMinimum(0.000000000000000);
        fog_para->setMaximum(1.000000000000000);
        fog_para->setSingleStep(0.010000000000000);
        fog_para->setValue(0.000000000000000);

        horizontalLayout->addWidget(fog_para);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(gB_addFog);

        cB_addRain = new QCheckBox(ProcessListClass);
        cB_addRain->setObjectName(QString::fromUtf8("cB_addRain"));

        verticalLayout_2->addWidget(cB_addRain);

        gB_addRain = new QGroupBox(ProcessListClass);
        gB_addRain->setObjectName(QString::fromUtf8("gB_addRain"));
        gB_addRain->setEnabled(false);
        verticalLayout = new QVBoxLayout(gB_addRain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(gB_addRain);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        rain_path = new QLineEdit(gB_addRain);
        rain_path->setObjectName(QString::fromUtf8("rain_path"));

        horizontalLayout_2->addWidget(rain_path);

        pushButton = new QPushButton(gB_addRain);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(gB_addRain);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        rain_para = new QDoubleSpinBox(gB_addRain);
        rain_para->setObjectName(QString::fromUtf8("rain_para"));
        rain_para->setMaximum(1.000000000000000);
        rain_para->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(rain_para);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(gB_addRain);

        cB_addSnow = new QCheckBox(ProcessListClass);
        cB_addSnow->setObjectName(QString::fromUtf8("cB_addSnow"));

        verticalLayout_2->addWidget(cB_addSnow);

        gB_addSnow = new QGroupBox(ProcessListClass);
        gB_addSnow->setObjectName(QString::fromUtf8("gB_addSnow"));
        gB_addSnow->setEnabled(false);
        horizontalLayout_4 = new QHBoxLayout(gB_addSnow);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(gB_addSnow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        snow_para = new QDoubleSpinBox(gB_addSnow);
        snow_para->setObjectName(QString::fromUtf8("snow_para"));
        snow_para->setMaximum(1.000000000000000);
        snow_para->setSingleStep(0.010000000000000);

        horizontalLayout_4->addWidget(snow_para);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(gB_addSnow);

        groupBox = new QGroupBox(ProcessListClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_10 = new QHBoxLayout(groupBox);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);

        Picnum = new QComboBox(groupBox);
        Picnum->setObjectName(QString::fromUtf8("Picnum"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Picnum->sizePolicy().hasHeightForWidth());
        Picnum->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(Picnum);


        verticalLayout_2->addWidget(groupBox);

        gB_evaIndex = new QGroupBox(ProcessListClass);
        gB_evaIndex->setObjectName(QString::fromUtf8("gB_evaIndex"));
        verticalLayout_3 = new QVBoxLayout(gB_evaIndex);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_6 = new QLabel(gB_evaIndex);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_9->addWidget(label_6);

        PSNR = new QLineEdit(gB_evaIndex);
        PSNR->setObjectName(QString::fromUtf8("PSNR"));
        PSNR->setMinimumSize(QSize(114, 15));
        PSNR->setReadOnly(true);

        horizontalLayout_9->addWidget(PSNR);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(gB_evaIndex);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        SSIM = new QLineEdit(gB_evaIndex);
        SSIM->setObjectName(QString::fromUtf8("SSIM"));
        SSIM->setReadOnly(true);

        horizontalLayout_6->addWidget(SSIM);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(gB_evaIndex);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        pB_do = new QPushButton(ProcessListClass);
        pB_do->setObjectName(QString::fromUtf8("pB_do"));

        horizontalLayout_5->addWidget(pB_do);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(ProcessListClass);
        QObject::connect(cB_addFog, SIGNAL(toggled(bool)), gB_addFog, SLOT(setEnabled(bool)));
        QObject::connect(cB_addRain, SIGNAL(toggled(bool)), gB_addRain, SLOT(setEnabled(bool)));
        QObject::connect(cB_addSnow, SIGNAL(toggled(bool)), gB_addSnow, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(ProcessListClass);
    } // setupUi

    void retranslateUi(QWidget *ProcessListClass)
    {
        ProcessListClass->setWindowTitle(QApplication::translate("ProcessListClass", "\345\244\204\347\220\206\345\210\227\350\241\250", nullptr));
        cB_addFog->setText(QApplication::translate("ProcessListClass", "\345\212\240\351\233\276", nullptr));
        gB_addFog->setTitle(QApplication::translate("ProcessListClass", "\345\212\240\351\233\276", nullptr));
        label->setText(QApplication::translate("ProcessListClass", "\344\273\277\347\234\237\351\233\276\346\265\223\345\272\246\347\263\273\346\225\260", nullptr));
        cB_addRain->setText(QApplication::translate("ProcessListClass", "\345\212\240\351\233\250", nullptr));
        gB_addRain->setTitle(QApplication::translate("ProcessListClass", "\345\212\240\351\233\250", nullptr));
        label_4->setText(QApplication::translate("ProcessListClass", "\351\233\250\346\273\264\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        pushButton->setText(QApplication::translate("ProcessListClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        label_5->setText(QApplication::translate("ProcessListClass", "\347\233\270\345\257\271\351\233\250\351\207\217\347\263\273\346\225\260", nullptr));
        cB_addSnow->setText(QApplication::translate("ProcessListClass", "\345\212\240\351\233\252", nullptr));
        gB_addSnow->setTitle(QApplication::translate("ProcessListClass", "\345\212\240\351\233\252", nullptr));
        label_2->setText(QApplication::translate("ProcessListClass", "\347\233\270\345\257\271\351\233\252\351\207\217\347\263\273\346\225\260", nullptr));
        groupBox->setTitle(QApplication::translate("ProcessListClass", "\345\233\276\347\211\207\346\225\260\351\207\217\350\256\276\347\275\256", nullptr));
        label_7->setText(QApplication::translate("ProcessListClass", "\345\244\204\347\220\206\345\233\276\347\211\207\346\225\260\351\207\217\357\274\232", nullptr));
        gB_evaIndex->setTitle(QApplication::translate("ProcessListClass", "\350\257\204\344\273\267\346\214\207\346\240\207", nullptr));
        label_6->setText(QApplication::translate("ProcessListClass", "\345\263\260\345\200\274\344\277\241\345\231\252\346\257\224(PSNR):", nullptr));
        label_3->setText(QApplication::translate("ProcessListClass", "\347\273\223\346\236\204\347\233\270\344\274\274\346\200\247(SSIM):", nullptr));
        pB_do->setText(QApplication::translate("ProcessListClass", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessListClass: public Ui_ProcessListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSLIST_H
