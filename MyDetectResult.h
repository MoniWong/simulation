#pragma once

#include <QtCore>
#include <QtWidgets>

#include "ui_DetectResult.h"

#include "MyType.h"

#ifdef _DEBUG
# include <QDebug>
#endif // _DEBUG

class MyDetectResult :public QDockWidget
{
	Q_OBJECT
public:
	MyDetectResult(QWidget* parent = Q_NULLPTR);
	~MyDetectResult();

	void SetDock(QMainWindow* dock);
	const DetectResult getResult();
	void ShowResultList(DetectResult result);

private:
	Ui::DetectResultClass ui;
	void closeEvent(QCloseEvent* event);
	DetectResult localResult;

private slots:
	void pb_ClearSelect_clicked();
	void pb_ClearAll_clicked();
	void pb_OutPut_clicked();
	

signals:
	void closeSignal();

};

