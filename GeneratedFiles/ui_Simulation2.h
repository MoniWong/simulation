/********************************************************************************
** Form generated from reading UI file 'Simulation2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION2_H
#define UI_SIMULATION2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulationClass
{
public:
    QAction *open_Pic;
    QAction *open_List;
    QAction *modelList;
    QAction *result;
    QAction *load_Pic;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QToolBar *picToolBar;

    void setupUi(QMainWindow *SimulationClass)
    {
        if (SimulationClass->objectName().isEmpty())
            SimulationClass->setObjectName(QString::fromUtf8("SimulationClass"));
        SimulationClass->resize(640, 480);
        SimulationClass->setMinimumSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/FOD/Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        SimulationClass->setWindowIcon(icon);
        open_Pic = new QAction(SimulationClass);
        open_Pic->setObjectName(QString::fromUtf8("open_Pic"));
        open_List = new QAction(SimulationClass);
        open_List->setObjectName(QString::fromUtf8("open_List"));
        open_List->setCheckable(true);
        modelList = new QAction(SimulationClass);
        modelList->setObjectName(QString::fromUtf8("modelList"));
        result = new QAction(SimulationClass);
        result->setObjectName(QString::fromUtf8("result"));
        load_Pic = new QAction(SimulationClass);
        load_Pic->setObjectName(QString::fromUtf8("load_Pic"));
        centralWidget = new QWidget(SimulationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabShape(QTabWidget::Triangular);
        mdiArea->setTabPosition(QTabWidget::North);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        SimulationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimulationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 18));
        SimulationClass->setMenuBar(menuBar);
        picToolBar = new QToolBar(SimulationClass);
        picToolBar->setObjectName(QString::fromUtf8("picToolBar"));
        SimulationClass->addToolBar(Qt::TopToolBarArea, picToolBar);

        picToolBar->addAction(open_Pic);
        picToolBar->addAction(open_List);
        picToolBar->addAction(load_Pic);
        picToolBar->addAction(modelList);
        picToolBar->addAction(result);

        retranslateUi(SimulationClass);

        QMetaObject::connectSlotsByName(SimulationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimulationClass)
    {
        SimulationClass->setWindowTitle(QApplication::translate("SimulationClass", "\344\273\277\347\234\237\347\263\273\347\273\237", nullptr));
        open_Pic->setText(QApplication::translate("SimulationClass", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        open_List->setText(QApplication::translate("SimulationClass", "\345\244\204\347\220\206\345\210\227\350\241\250", nullptr));
        modelList->setText(QApplication::translate("SimulationClass", "\346\250\241\345\236\213\345\210\227\350\241\250", nullptr));
        result->setText(QApplication::translate("SimulationClass", "\346\243\200\346\265\213\347\273\223\346\236\234", nullptr));
        load_Pic->setText(QApplication::translate("SimulationClass", "\346\211\271\351\207\217\345\212\240\350\275\275", nullptr));
        picToolBar->setWindowTitle(QApplication::translate("SimulationClass", "\344\273\277\347\234\237\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulationClass: public Ui_SimulationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION2_H
