/********************************************************************************
** Form generated from reading UI file 'waitingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGWINDOW_H
#define UI_WAITINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waitingWindow
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *waitingWindow)
    {
        if (waitingWindow->objectName().isEmpty())
            waitingWindow->setObjectName(QString::fromUtf8("waitingWindow"));
        waitingWindow->resize(180, 100);
        gridLayout_2 = new QGridLayout(waitingWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(waitingWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(waitingWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(waitingWindow);

        QMetaObject::connectSlotsByName(waitingWindow);
    } // setupUi

    void retranslateUi(QWidget *waitingWindow)
    {
        waitingWindow->setWindowTitle(QApplication::translate("waitingWindow", "waiting", nullptr));
        label->setText(QApplication::translate("waitingWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("waitingWindow", "\346\255\243\345\234\250\345\244\204\347\220\206\344\270\255...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waitingWindow: public Ui_waitingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGWINDOW_H
