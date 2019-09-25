/********************************************************************************
** Form generated from reading UI file 'DetectorList.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORLIST_H
#define UI_DETECTORLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorListClass
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_load;
    QPushButton *pb_unload;
    QPushButton *pb_start;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_Add;
    QPushButton *pb_Edit;
    QPushButton *pb_Del;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *tw_Detectors;

    void setupUi(QWidget *DetectorListClass)
    {
        if (DetectorListClass->objectName().isEmpty())
            DetectorListClass->setObjectName(QString::fromUtf8("DetectorListClass"));
        DetectorListClass->resize(375, 300);
        layoutWidget = new QWidget(DetectorListClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 130, 2, 2));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout(DetectorListClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_load = new QPushButton(DetectorListClass);
        pb_load->setObjectName(QString::fromUtf8("pb_load"));

        horizontalLayout_3->addWidget(pb_load);

        pb_unload = new QPushButton(DetectorListClass);
        pb_unload->setObjectName(QString::fromUtf8("pb_unload"));

        horizontalLayout_3->addWidget(pb_unload);

        pb_start = new QPushButton(DetectorListClass);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));

        horizontalLayout_3->addWidget(pb_start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_Add = new QPushButton(DetectorListClass);
        pb_Add->setObjectName(QString::fromUtf8("pb_Add"));

        horizontalLayout->addWidget(pb_Add);

        pb_Edit = new QPushButton(DetectorListClass);
        pb_Edit->setObjectName(QString::fromUtf8("pb_Edit"));

        horizontalLayout->addWidget(pb_Edit);

        pb_Del = new QPushButton(DetectorListClass);
        pb_Del->setObjectName(QString::fromUtf8("pb_Del"));

        horizontalLayout->addWidget(pb_Del);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tw_Detectors = new QTreeWidget(DetectorListClass);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tw_Detectors->setHeaderItem(__qtreewidgetitem);
        tw_Detectors->setObjectName(QString::fromUtf8("tw_Detectors"));
        tw_Detectors->setColumnCount(1);
        tw_Detectors->header()->setVisible(false);

        gridLayout->addWidget(tw_Detectors, 4, 0, 1, 1);


        retranslateUi(DetectorListClass);

        QMetaObject::connectSlotsByName(DetectorListClass);
    } // setupUi

    void retranslateUi(QWidget *DetectorListClass)
    {
        DetectorListClass->setWindowTitle(QApplication::translate("DetectorListClass", "\346\250\241\345\236\213\345\210\227\350\241\250", nullptr));
        pb_load->setText(QApplication::translate("DetectorListClass", "\345\212\240\350\275\275\346\250\241\345\236\213", nullptr));
        pb_unload->setText(QApplication::translate("DetectorListClass", "\345\215\270\350\275\275\346\250\241\345\236\213", nullptr));
        pb_start->setText(QApplication::translate("DetectorListClass", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        pb_Add->setText(QApplication::translate("DetectorListClass", "\346\267\273\345\212\240\346\250\241\345\236\213", nullptr));
        pb_Edit->setText(QApplication::translate("DetectorListClass", "\347\274\226\350\276\221\346\250\241\345\236\213", nullptr));
        pb_Del->setText(QApplication::translate("DetectorListClass", "\345\210\240\351\231\244\346\250\241\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectorListClass: public Ui_DetectorListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORLIST_H
