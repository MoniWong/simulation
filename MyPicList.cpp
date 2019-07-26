#include "MyPicList.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <opencv2\opencv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>


MyPicList::MyPicList(QWidget* parent) :QDockWidget(parent)
{
	qRegisterMetaType<Info>("Info");
	qRegisterMetaType<Info>("Info&");
	QWidget* Widget = new QWidget;
	ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("图像列表"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();
	connect(ui.Fog, SIGNAL(clicked()), this, SLOT(addFog()));
	connect(ui.Rain, SIGNAL(clicked()), this, SLOT(addrain()));
	connect(ui.Snow, SIGNAL(clicked()), this, SLOT(addsnow()));
	connect(ui.Open, SIGNAL(clicked()), this, SLOT(openPic()));
	connect(ui.Del, SIGNAL(clicked()), this, SLOT(delPic()));
}

MyPicList::~MyPicList()
{
	ui.lw_Pics->clear();
}

void MyPicList::closeEvent(QCloseEvent* event)
{
	emit closeSignal();
}


void MyPicList::addFog()
{
	QListWidgetItem* currentItem = ui.lw_Pics->currentItem();
	if (currentItem == nullptr) return;
	QPointer<QDialog> fogDialog = new QDialog();
	addfog_ui.setupUi(fogDialog);
	Info info = currentItem->data(Qt::UserRole + 1).value<Info>();
	int res = fogDialog->exec();
	if (res == QDialog::Accepted)
	{	
		double beta = addfog_ui.beta->value();
		cv::Mat fog_img = fog(info.Pic, beta);
		emit creatWin(info.name + "(addfog)", fog_img);
	}
	delete fogDialog;
	fogDialog.clear();
}

void MyPicList::addrain()
{
	QListWidgetItem* currentItem = ui.lw_Pics->currentItem();
	if (currentItem == nullptr) return;
	QPointer<QDialog> rainDialog = new QDialog(this);
	addrain_ui.setupUi(rainDialog);
	rainDialog->setBaseSize(300, 100);
	Info info = currentItem->data(Qt::UserRole + 1).value<Info>();
	connect(addrain_ui.pb_select, SIGNAL(clicked()), this, SLOT(getPath()));
	int res = rainDialog->exec();
	if (res == QDialog::Accepted)
	{
		double alpha = addrain_ui.alpha->value();
		std::string path = addrain_ui.le_pbPath->text().toStdString();
		cv::Mat fog_img = addRain(info.Pic, alpha, path);
		emit creatWin(info.name + "(addrain)", fog_img);
	}
	delete rainDialog;
	rainDialog.clear();
}

void MyPicList::addsnow()
{
	QListWidgetItem* currentItem = ui.lw_Pics->currentItem();
	if (currentItem == nullptr) return;
	QPointer<QDialog> snowDialog = new QDialog();
	addsnow_ui.setupUi(snowDialog);
	Info info = currentItem->data(Qt::UserRole + 1).value<Info>();
	int res = snowDialog->exec();
	if (res == QDialog::Accepted)
	{
		double ext = addsnow_ui.ext->value();
		cv::Mat fog_img = addSnow(info.Pic, ext);
		emit creatWin(info.name + "(addsnow)", fog_img);
	}
	delete snowDialog;
	snowDialog.clear();
}

void MyPicList::openPic()
{
	Info *info = new Info;
	QString file = QFileDialog::getOpenFileName(this, QStringLiteral("打开图像"),
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
		info->name = fileInfo.fileName();
		info->Pic = t;
		emit creatWin(fileInfo.fileName(), t);
	}
	if (info != nullptr)
	{
		QListWidgetItem* Item = new QListWidgetItem;
		Item->setData(Qt::UserRole + 1, QVariant::fromValue(*info));
		Item->setData(Qt::DisplayRole, info->name);
		ui.lw_Pics->addItem(Item);
	}
}

void MyPicList::delPic()
{
	QListWidgetItem* currentItem = ui.lw_Pics->currentItem();
	if (currentItem == nullptr) return;
	Info info = currentItem->data(Qt::UserRole + 1).value<Info>();
	emit sendItemName(info.name);
	delete currentItem;
}

void MyPicList::getPath()
{
	QString file = QFileDialog::getExistingDirectory(this, "choose src Directory",
		"/");
	if (file.isEmpty())
		return;
	else
		addrain_ui.le_pbPath->setText(file);
}

