/********************************************************************************
** Form generated from reading UI file 'SubWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindowClass
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *SubWindowClass)
    {
        if (SubWindowClass->objectName().isEmpty())
            SubWindowClass->setObjectName(QString::fromUtf8("SubWindowClass"));
        SubWindowClass->resize(400, 300);
        gridLayout = new QGridLayout(SubWindowClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(SubWindowClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setContextMenuPolicy(Qt::CustomContextMenu);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(SubWindowClass);

        QMetaObject::connectSlotsByName(SubWindowClass);
    } // setupUi

    void retranslateUi(QWidget *SubWindowClass)
    {
        SubWindowClass->setWindowTitle(QApplication::translate("SubWindowClass", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubWindowClass: public Ui_SubWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
