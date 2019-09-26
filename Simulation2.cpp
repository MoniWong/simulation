#include "Simulation2.h"
#include <QPointF>
#include <QImage>
#include <QPixmap>
#include "opencv2/opencv.hpp"

Simulation2::Simulation2(QWidget *parent)
	: QMainWindow(parent)
{
	//注册
	ui.setupUi(this);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<cv::Mat>("cv::Mat&");
	qRegisterMetaType<Info>("Info");
	qRegisterMetaType<Info>("Info&");
	qRegisterMetaType<DetectResult>("DetectResult");
	qRegisterMetaType<DetectResult>("DetectResult&");
	qRegisterMetaType<DetectorInfo>("DetectorInfo");
	qRegisterMetaType<DetectorInfo>("DetectorInfo&");

	//处理列表
	processList = new MyProcessList(this);
	this->addDockWidget(Qt::RightDockWidgetArea, processList);
	
	connect(processList, SIGNAL(creatWin(QString, cv::Mat&, bool)), this, SLOT(Creat_newSubWin(QString, cv::Mat&, bool)));



	//检测器列表
	detectorList = new MyDetectorList(this);
	this->addDockWidget(Qt::LeftDockWidgetArea, detectorList);
	connect(detectorList, SIGNAL(closeSignal()), this, SLOT(setDetectorFalse()));


	//connect(deviceList, SIGNAL(sendMattoDetect(QString, cv::Mat&)), detectorList, SLOT(get_Pic(QString, cv::Mat&)));
	//传入图片到去雾group
	//connect(deviceInfo, SIGNAL(NameMat(QString, cv::Mat&)), detectorList, SLOT(get_Pic(QString, cv::Mat&)));
	//去雾group传图片到检测group
	//connect(dehazerGroup, SIGNAL(output_img(QString, cv::Mat&)), FODDetectorGroup, SLOT(input_img(QString, cv::Mat&)));

	//从检测group传出图片
	connect(detectorList, SIGNAL(showMat(QString, cv::Mat&, bool)), this, SLOT(showFinalPic(QString, cv::Mat&, bool)));
	connect(detectorList, SIGNAL(showResult(QString, DetectResult, cv::Mat&, bool)), this, SLOT(showResult(QString, DetectResult, cv::Mat&, bool)));

	//批量加载图片
	connect(ui.load_Pic, SIGNAL(triggered()), this, SLOT(loadPic()));
	//其他信号
	connect(ui.open_List, SIGNAL(toggled(bool)), this, SLOT(ProcessList_toggled(bool)));
	connect(ui.modelList, SIGNAL(toggled(bool)), this, SLOT(a_Detector_toggled(bool)));
	connect(ui.open_Pic, SIGNAL(triggered()), this, SLOT(openPic()));

	connect(processList, SIGNAL(closeSignal()), this, SLOT(setPicFalse()));
	connect(processList, SIGNAL(afterAddPathList(QStringList)), detectorList, SLOT(setPathList(QStringList)));
}

Simulation2::~Simulation2()
{
	delete processList;
}

void Simulation2::setDetectorFalse()
{
	ui.modelList->disconnect(SIGNAL(toggled(bool)));
	ui.modelList->setChecked(false);
	connect(ui.modelList, SIGNAL(toggled(bool)), this, SLOT(a_Detector_toggled(bool)));
}

void Simulation2::showResult(QString name, DetectResult result, cv::Mat& img, bool flag)
{
	if (flag) {
		detectResult->ShowResultList(result);
		MySubWindow* subWindow = (MySubWindow*)ui.mdiArea->currentSubWindow();
		subWindow->ShowResultRect(result);
		}
	else {
		QPen pen(QColor(255, 0, 0, 127));
		pen.setWidth(4);
		for (int i = 0; i < result.num_detections; i++)
		{
			//QPointF topLeft((result.boxes_data[i][1]) * img.cols, (result.boxes_data[i][0]) * img.rows);
			//QPointF bottomRight((result.boxes_data[i][3]) * img.cols, (result.boxes_data[i][2]) * img.rows);
			//items.append(originalScene->addRect(QRectF(topLeft, bottomRight), pen));
			//QRectF(topLeft, bottomRight);
			Rect rect((result.boxes_data[i][1]) * img.cols, (result.boxes_data[i][0]) * img.rows, (result.boxes_data[i][3]- result.boxes_data[i][1]), (result.boxes_data[i][2] - result.boxes_data[i][0]));//左上坐标（x,y）和矩形的长(x)宽(y)
			cv::rectangle(img, rect, Scalar(0, 0, 255), 1, LINE_8, 0);
		}
		cv::imwrite("C:/Users/ASUS/source/repos/Simulation/afterDetect/" + name.mid(0, name.indexOf(".")).toStdString() + ".jpg", img);
	}
}
void Simulation2::showFinalPic(QString name, cv::Mat & img, bool flag)
{
	if (flag)
		update_subWin(name, img);
	else
		cv::imwrite("C:/Users/ASUS/source/repos/Simulation/afterDetect/" + name.mid(0, name.indexOf(".")).toStdString() + ".jpg", img);
}
void Simulation2::a_Detector_toggled(bool open)
{
	if (!open)
	{
		detectorList->close();
		return;
	}
	detectorList->show();
}

QStringList  Simulation2::getDirFilesName(QString pathsDir)
{
	QDir dir(pathsDir);
	dir.setFilter(QDir::Files | QDir::NoSymLinks);
	QStringList filters;
	filters << "*.png" << "*.jpg";
	dir.setNameFilters(filters);
	QStringList allImageNameList = dir.entryList();
	if (allImageNameList.count() <= 0)
	{
		QMessageBox::information(nullptr, "ERROR", QStringLiteral("文件夹为空!"),
			QMessageBox::Ok);
	}
	return allImageNameList;
}

void Simulation2::Creat_newSubWin(QString title, cv::Mat& image, bool saved)
{
	MySubWindow* subWindow = new MySubWindow(title, image, saved);
	ui.mdiArea->addSubWindow(subWindow);
	subWindow->show();
}
void Simulation2::update_subWin(QString title, cv::Mat& image)
{
	//if(flag)
	//	cv::imwrite("D:/FOD3/FOD/processedPic/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss").toStdString() + ".jpg", image);
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	for (auto subWindow : subWinList)
		if ((subWindow->windowTitle() == title) || (subWindow->windowTitle() == title + "*"))
		{
			((MySubWindow*)subWindow)->setImg(image);
			return;
		}

	Creat_newSubWin(title, image, false);
}

void Simulation2::ProcessList_toggled(bool open)
{
	if (!open)
	{
		processList->close();
		return;
	}
	processList->show();
}

void Simulation2::setPicFalse()
{
	ui.open_Pic->disconnect(SIGNAL(toggled(bool)));
	ui.open_Pic->setChecked(false);
	connect(ui.open_Pic, SIGNAL(toggled(bool)), this, SLOT(ProcessList_toggled(bool)));
}

void Simulation2::close_Pic(QString name)
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	for (auto subWindow : subWinList)
		if ((subWindow->windowTitle() == name) || (subWindow->windowTitle() == name + "*"))
		{
			subWindow->close();
			processList->ui.PSNR->setText("");
			processList->ui.SSIM->setText("");
			return;
		}
}

void Simulation2::loadPic()
{
	file = QFileDialog::getExistingDirectory(this, "choose Picture Directory",
		"/");
	if (file.isEmpty())
		return;
	else
	{
		if (!PicList.isEmpty())
			PicList.clear();
		PicList = getDirFilesName(file);
		PicList << file;
		processList->getPic(PicList);
		processList->setPicNum(PicList.size()-1);
	}
}

void Simulation2::openPic()
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	if (subWinList.length() == 1) return;
	QString path = QFileDialog::getOpenFileName(NULL, QStringLiteral("打开图像"),
		"", QStringLiteral("PNG图像 (*.png *.jpg *.bmp)"));
	if (path.isEmpty())
		return;
	else
	{
		if (!PicList.isEmpty())
			PicList.clear();
		PicList << path;
		cv::Mat t = cv::imread(path.toLocal8Bit().toStdString());
		if (t.empty())
		{
			return;
		}
		QFileInfo fileInfo(path);
		PicList << fileInfo.fileName();
		Creat_newSubWin(fileInfo.fileName(), t, false);
		processList->getPic(PicList);
		detectorList->getPicPath(PicList);
	}
}























