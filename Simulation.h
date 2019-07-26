#pragma once

#include <QtWidgets/QMainWindow>
#include <opencv2/highgui/highgui_c.h>
#include "ui_Simulation.h"
#include <math.h>
#include <iostream>

#include "fogdll1/fog.h"
#include "AddSnow/AddSnow.h"
#include "AddRain/addRain.h"

#include <QtCore>
#ifdef _DEBUG
#include <QDebug>
#else

#endif

class Simulation : public QMainWindow
{
	Q_OBJECT

public:
	Simulation(QWidget *parent = Q_NULLPTR);
	~Simulation();
private:
	Ui::SimulationClass ui;
	QImage Mat2QImg(const cv::Mat &cvImg);
	QGraphicsScene* scene;

public slots:
	void a_addfog();
	void a_addsnow();
	void a_addrain();
};
