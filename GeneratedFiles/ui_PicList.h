/********************************************************************************
** Form generated from reading UI file 'PicList.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICLIST_H
#define UI_PICLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicListClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Open;
    QPushButton *Del;
    QPushButton *Save;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Fog;
    QPushButton *Rain;
    QPushButton *Snow;
    QSpacerItem *horizontalSpacer;
    QListWidget *lw_Pics;

    void setupUi(QWidget *PicListClass)
    {
        if (PicListClass->objectName().isEmpty())
            PicListClass->setObjectName(QString::fromUtf8("PicListClass"));
        PicListClass->resize(263, 381);
        gridLayout = new QGridLayout(PicListClass);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Open = new QPushButton(PicListClass);
        Open->setObjectName(QString::fromUtf8("Open"));
        Open->setCheckable(false);

        horizontalLayout_2->addWidget(Open);

        Del = new QPushButton(PicListClass);
        Del->setObjectName(QString::fromUtf8("Del"));

        horizontalLayout_2->addWidget(Del);

        Save = new QPushButton(PicListClass);
        Save->setObjectName(QString::fromUtf8("Save"));

        horizontalLayout_2->addWidget(Save);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Fog = new QPushButton(PicListClass);
        Fog->setObjectName(QString::fromUtf8("Fog"));

        horizontalLayout->addWidget(Fog);

        Rain = new QPushButton(PicListClass);
        Rain->setObjectName(QString::fromUtf8("Rain"));

        horizontalLayout->addWidget(Rain);

        Snow = new QPushButton(PicListClass);
        Snow->setObjectName(QString::fromUtf8("Snow"));

        horizontalLayout->addWidget(Snow);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lw_Pics = new QListWidget(PicListClass);
        lw_Pics->setObjectName(QString::fromUtf8("lw_Pics"));

        gridLayout->addWidget(lw_Pics, 6, 0, 1, 1);


        retranslateUi(PicListClass);

        QMetaObject::connectSlotsByName(PicListClass);
    } // setupUi

    void retranslateUi(QWidget *PicListClass)
    {
        PicListClass->setWindowTitle(QApplication::translate("PicListClass", "\345\233\276\345\203\217\345\210\227\350\241\250", nullptr));
        Open->setText(QApplication::translate("PicListClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        Del->setText(QApplication::translate("PicListClass", "\345\210\240\351\231\244\345\233\276\347\211\207", nullptr));
        Save->setText(QApplication::translate("PicListClass", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        Fog->setText(QApplication::translate("PicListClass", "\345\212\240\351\233\276", nullptr));
        Rain->setText(QApplication::translate("PicListClass", "\345\212\240\351\233\250", nullptr));
        Snow->setText(QApplication::translate("PicListClass", "\345\212\240\351\233\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PicListClass: public Ui_PicListClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICLIST_H
