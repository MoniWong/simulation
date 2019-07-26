#include "Simulation2.h"

Simulation2::Simulation2(QWidget *parent)
	: QMainWindow(parent)
{
	//注册
	ui.setupUi(this);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<cv::Mat>("cv::Mat&");
	qRegisterMetaType<Info>("Info");
	qRegisterMetaType<Info>("Info&");

	//图像列表
	picList = new MyPicList(this);
	this->addDockWidget(Qt::LeftDockWidgetArea, picList);
	
	connect(picList, SIGNAL(closeSignal()), this, SLOT(setPicFalse()));
	connect(picList, SIGNAL(creatWin(QString, cv::Mat&)), this, SLOT(update_subWin(QString, cv::Mat&)));
	connect(picList->ui.Save, SIGNAL(clicked()), this, SLOT(a_SavePic_triggered()));
	connect(picList, SIGNAL(sendItemName(QString)), this, SLOT(close_Pic(QString)));


	//其他信号
	connect(ui.open_Pic, SIGNAL(toggled(bool)), this, SLOT(PicList_toggled(bool)));
	connect(picList, SIGNAL(closeSignal()), this, SLOT(setPicFalse()));
}

Simulation2::~Simulation2()
{

}

void Simulation2::update_subWin(QString title, cv::Mat& image)
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	for (auto subWindow : subWinList)
		if ((subWindow->windowTitle() == title)||(subWindow->windowTitle() == title+ "*"))
		{
			((MySubWindow*)subWindow)->setImg(image);
			return;
		}
	Creat_newSubWin(title, image);
}

void Simulation2::Creat_newSubWin(QString title, cv::Mat& image)
{
	MySubWindow* subWindow = new MySubWindow(title, image);
	ui.mdiArea->addSubWindow(subWindow);
	subWindow->show();
}

void Simulation2::PicList_toggled(bool open)
{
	if (!open)
	{
		picList->close();
		return;
	}

	picList->show();

}

void Simulation2::setPicFalse()
{
	ui.open_Pic->disconnect(SIGNAL(toggled(bool)));
	ui.open_Pic->setChecked(false);
	connect(ui.open_Pic, SIGNAL(toggled(bool)), this, SLOT(PicList_toggled(bool)));
}

void Simulation2::close_Pic(QString name)
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	for (auto subWindow : subWinList)
		if ((subWindow->windowTitle() == name) || (subWindow->windowTitle() == name + "*"))
		{
			subWindow->close();
			return;
		}
}

void Simulation2::a_SavePic_triggered()
{
	MySubWindow* subWindow = (MySubWindow*)ui.mdiArea->currentSubWindow();
	if (subWindow != nullptr)
	{
		subWindow->SaveImg();
	}
}























