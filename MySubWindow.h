#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <QtCore>
#include <QtWidgets>

#include "ui_SubWindow.h"
#include "MyType.h"


class MySubWindow : public QMdiSubWindow
{
	Q_OBJECT
public:
	MySubWindow(QString str, cv::Mat& image);
	~MySubWindow();
	void setImg(cv::Mat& image);
	cv::Mat getMat();
	void SaveImg();

private:
	Ui::SubWindowClass ui;
	cv::Mat img;
	QString title;
	bool isSaved;

	int scale_rate;

	QPointer<QMenu> contextMenu;
	QPointer<QAction> a_zoom_in;
	QPointer<QAction> a_zoom_out;
	QPointer<QAction> a_reset;


	QPointer<QWidget> widget;
	QPointer<QGraphicsScene> originalScene;
	QGraphicsItemGroup* rects;

	void closeEvent(QCloseEvent* event);

private slots:
	void showListWidgetMenuSlot(QPoint pos);
	void a_zoom_in_triggered();
	void a_zoom_out_triggered();
	void a_reset_triggered();
};

Q_DECLARE_OPAQUE_POINTER(MySubWindow)