#include "Simulation2.h"

Simulation2::Simulation2(QWidget *parent)
	: QMainWindow(parent)
{
	//注册
	ui.setupUi(this);
	qRegisterMetaType<cv::Mat>("cv::Mat");
	qRegisterMetaType<cv::Mat>("cv::Mat&");

	//处理列表
	processList = new MyProcessList(this);
	this->addDockWidget(Qt::LeftDockWidgetArea, processList);
	
	connect(processList, SIGNAL(creatWin(cv::Mat&)), this, SLOT(update_subWin(cv::Mat&)));



	//其他信号
	connect(ui.open_List, SIGNAL(toggled(bool)), this, SLOT(ProcessList_toggled(bool)));
	connect(ui.open_Pic, SIGNAL(triggered()), this, SLOT(openPic()));

	connect(processList, SIGNAL(closeSignal()), this, SLOT(setPicFalse()));
	
}

Simulation2::~Simulation2()
{
	delete processList;
}

void Simulation2::Creat_newSubWin(QString title, cv::Mat& image)
{
	MySubWindow* subWindow = new MySubWindow(title, image);
	ui.mdiArea->addSubWindow(subWindow);
	subWindow->show();
}
void Simulation2::update_subWin(cv::Mat& image)
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	for (auto subWindow : subWinList){
		((MySubWindow*)subWindow)->setImg(image);
		return;
		}
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

void Simulation2::openPic()
{
	QList<QMdiSubWindow *> subWinList = ui.mdiArea->subWindowList();
	if (subWinList.length() == 1) return;
	QString file = QFileDialog::getOpenFileName(NULL, QStringLiteral("打开图像"),
		"", QStringLiteral("PNG图像 (*.png *.jpg *.bmp)"));
	if (file.isEmpty())
		return;
	else
	{
		cv::Mat t = cv::imread(file.toLocal8Bit().toStdString());
		if (t.empty())
		{
			return;
		}
		QFileInfo fileInfo(file);
		Creat_newSubWin(fileInfo.fileName(), t);
		processList->getPic(t);
	}
}























