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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pB_do;
    QPushButton *pB_reset;

    void setupUi(QWidget *ProcessListClass)
    {
        if (ProcessListClass->objectName().isEmpty())
            ProcessListClass->setObjectName(QString::fromUtf8("ProcessListClass"));
        ProcessListClass->resize(270, 354);
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

        horizontalLayout_4->addWidget(snow_para);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(gB_addSnow);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pB_do = new QPushButton(ProcessListClass);
        pB_do->setObjectName(QString::fromUtf8("pB_do"));

        horizontalLayout_5->addWidget(pB_do);

        pB_reset = new QPushButton(ProcessListClass);
        pB_reset->setObjectName(QString::fromUtf8("pB_reset"));

        horizontalLayout_5->addWidget(pB_reset);


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
        pB_do->setText(QApplication::translate("ProcessListClass", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        pB_reset->setText(QApplication::translate("ProcessListClass", "\350\277\230\345\216\237\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcessListClass: public Ui_ProcessListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSLIST_H
