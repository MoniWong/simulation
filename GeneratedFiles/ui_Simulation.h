/********************************************************************************
** Form generated from reading UI file 'Simulation.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATION_H
#define UI_SIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulationClass
{
public:
    QAction *actionfog;
    QAction *actionsnow;
    QAction *actionrain;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimulationClass)
    {
        if (SimulationClass->objectName().isEmpty())
            SimulationClass->setObjectName(QString::fromUtf8("SimulationClass"));
        SimulationClass->resize(600, 400);
        actionfog = new QAction(SimulationClass);
        actionfog->setObjectName(QString::fromUtf8("actionfog"));
        actionsnow = new QAction(SimulationClass);
        actionsnow->setObjectName(QString::fromUtf8("actionsnow"));
        actionrain = new QAction(SimulationClass);
        actionrain->setObjectName(QString::fromUtf8("actionrain"));
        centralWidget = new QWidget(SimulationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        SimulationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimulationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        SimulationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimulationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SimulationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SimulationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SimulationClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionfog);
        mainToolBar->addAction(actionsnow);
        mainToolBar->addAction(actionrain);

        retranslateUi(SimulationClass);

        QMetaObject::connectSlotsByName(SimulationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimulationClass)
    {
        SimulationClass->setWindowTitle(QApplication::translate("SimulationClass", "Simulation", nullptr));
        actionfog->setText(QApplication::translate("SimulationClass", "fog", nullptr));
        actionsnow->setText(QApplication::translate("SimulationClass", "snow", nullptr));
        actionrain->setText(QApplication::translate("SimulationClass", "rain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulationClass: public Ui_SimulationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATION_H
