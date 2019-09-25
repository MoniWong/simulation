/********************************************************************************
** Form generated from reading UI file 'DetectResult.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTRESULT_H
#define UI_DETECTRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectResultClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_ClearSelect;
    QPushButton *pb_ClearAll;
    QPushButton *pb_OutPut;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *tw_Result;

    void setupUi(QWidget *DetectResultClass)
    {
        if (DetectResultClass->objectName().isEmpty())
            DetectResultClass->setObjectName(QString::fromUtf8("DetectResultClass"));
        DetectResultClass->resize(720, 207);
        verticalLayout = new QVBoxLayout(DetectResultClass);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_ClearSelect = new QPushButton(DetectResultClass);
        pb_ClearSelect->setObjectName(QString::fromUtf8("pb_ClearSelect"));

        horizontalLayout->addWidget(pb_ClearSelect);

        pb_ClearAll = new QPushButton(DetectResultClass);
        pb_ClearAll->setObjectName(QString::fromUtf8("pb_ClearAll"));

        horizontalLayout->addWidget(pb_ClearAll);

        pb_OutPut = new QPushButton(DetectResultClass);
        pb_OutPut->setObjectName(QString::fromUtf8("pb_OutPut"));

        horizontalLayout->addWidget(pb_OutPut);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tw_Result = new QTreeWidget(DetectResultClass);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tw_Result->setHeaderItem(__qtreewidgetitem);
        tw_Result->setObjectName(QString::fromUtf8("tw_Result"));

        verticalLayout->addWidget(tw_Result);


        retranslateUi(DetectResultClass);

        QMetaObject::connectSlotsByName(DetectResultClass);
    } // setupUi

    void retranslateUi(QWidget *DetectResultClass)
    {
        DetectResultClass->setWindowTitle(QApplication::translate("DetectResultClass", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        pb_ClearSelect->setText(QApplication::translate("DetectResultClass", "\346\270\205\351\231\244\351\200\211\344\270\255\346\235\241\347\233\256", nullptr));
        pb_ClearAll->setText(QApplication::translate("DetectResultClass", "\346\270\205\351\231\244\346\211\200\346\234\211\346\235\241\347\233\256", nullptr));
        pb_OutPut->setText(QApplication::translate("DetectResultClass", "\344\277\235\345\255\230\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectResultClass: public Ui_DetectResultClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTRESULT_H
