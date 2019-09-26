#include "MyProcessList.h"
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <errno.h>



MyProcessList::MyProcessList(QWidget* parent) :QDockWidget(parent)
{
	QWidget* Widget = new QWidget;
	ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("处理列表"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();
	connect(ui.pB_do, SIGNAL(clicked()), this, SLOT(doProcess()));
	//connect(ui.pB_reset, SIGNAL(clicked()), this, SLOT(originPic()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(getPath()));
}

MyProcessList::~MyProcessList()
{
	
}

void MyProcessList::getPic(QStringList Pic)
{
	pathList = Pic;
	if (pathList.size() == 2) {
		cv::Mat t = cv::imread(pathList[0].toLocal8Bit().toStdString());
		img = t.clone();
		origin_img = t.clone();
	}
}

void MyProcessList::setPicNum(int i)
{
	QStringList Numlist;
	Numlist << QString::number(i);
	while (i - 100 > 0) {
		Numlist << QString::number(i - 100);
		i = i - 100;
	}
	ui.Picnum->clear();
	ui.Picnum->addItems(Numlist);
}

void MyProcessList::closeEvent(QCloseEvent* event)
{
	emit closeSignal();
}

Mat MyProcessList::addfog(double beta, cv::Mat& img)
{
	cv::Mat fog_img = fog(img, beta);
	return fog_img;
}


Mat MyProcessList::addrain(double alpha, std::string path, cv::Mat& img)
{
	cv::Mat rain_img = addRain(img, alpha, path);
	return rain_img;
}

Mat MyProcessList::addsnow(double ext, cv::Mat& img)
{
	cv::Mat snow_img = addSnow(img, ext);
	return snow_img;
}

void MyProcessList::getPath()
{
	QString file = QFileDialog::getExistingDirectory(this, "choose src Directory",
		"/");
	if (file.isEmpty())
		return;
	else
		ui.rain_path->setText(file);
}

void MyProcessList::doProcess()
{
	if (pathList.size() == 2) {
		if (ui.cB_addFog->isChecked()) {
			img = addfog(ui.fog_para->value(), img);
		}
		if (ui.cB_addRain->isChecked()) {
			img = addrain(ui.rain_para->value(), ui.rain_path->text().toStdString(), img);
		}
		if (ui.cB_addSnow->isChecked()) {
			img = addsnow(ui.snow_para->value(), img);
		}
		emit creatWin("afterAdd-"+pathList[1], img, false);
		ui.PSNR->setText(QString::number(psnr(origin_img, img), 10, 2));
		ui.SSIM->setText(QString::number(ssim(origin_img, img), 10, 2));
	}
	else if (pathList.size() > 2)
	{
		DeleteFile("C:/Users/ASUS/source/repos/Simulation/afterAdd");
		QApplication::setOverrideCursor(Qt::WaitCursor);//设置鼠标为等待状态
		QProgressDialog progress;
		progress.setWindowTitle(QString::fromLocal8Bit("提示"));
		progress.setLabelText(QString::fromLocal8Bit("正在处理中..."));
		progress.setCancelButtonText(QString::fromLocal8Bit("取消"));
		progress.setRange(0, pathList.size() - 1);//设置范围
		progress.setModal(true);//设置为模态对话框
		progress.show();
		QString path = pathList[pathList.size() - 1]+"/";
		int iSucceed = 0;

		for (int i = 0; i < ui.Picnum->currentText().toInt(); i++) {
			QString item = path + pathList[i];
			img = cv::imread(item.toLocal8Bit().toStdString());
			if (ui.cB_addFog->isChecked()) {
				img = addfog(ui.fog_para->value(), img);
			}
			if (ui.cB_addRain->isChecked()) {
				img = addrain(ui.rain_para->value(), ui.rain_path->text().toStdString(), img);
			}
			if (ui.cB_addSnow->isChecked()) {
				img = addsnow(ui.snow_para->value(), img);
			}

			cv::imwrite("C:/Users/ASUS/source/repos/Simulation/afterAdd/" + pathList[i].mid(0, pathList[i].indexOf(".")).toStdString() + ".jpg", img);
			progress.setValue(i);
			iSucceed = iSucceed + 1;
			if (progress.wasCanceled())
			{
				break;
			}
			QCoreApplication::processEvents();
		}
		QApplication::restoreOverrideCursor();
		progress.close();
		QMessageBox::warning(this, QStringLiteral("提示"), QString::fromLocal8Bit("共处理%1个文件！").arg(iSucceed));
		QString path2 = "C:/Users/ASUS/source/repos/Simulation/afterAdd";
		QStringList afterAddPath;
		if (!afterAddPath.isEmpty())
			afterAddPath.clear();
		afterAddPath = getDirFilesName(path2);
		afterAddPath << path2;
		emit afterAddPathList(afterAddPath);
	}
	else
		return;
}

QStringList  MyProcessList::getDirFilesName(QString pathsDir)
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


//void MyProcessList::originPic()
//{
//	ui.PSNR->setText("");
//	ui.SSIM->setText("");
//	img = origin_img.clone();
//	//emit creatWin(img);
//}


double MyProcessList::psnr(cv::Mat & I1, cv::Mat & I2)
{
	cv::Mat s1;
	absdiff(I1, I2, s1);
	s1.convertTo(s1, CV_32F);//转换为32位的float类型，8位不能计算平方  
	s1 = s1.mul(s1);
	cv::Scalar s = sum(s1);  //计算每个通道的和  
	double sse = s.val[0] + s.val[1] + s.val[2];
	if (sse <= 1e-10) // for small values return zero  
		return 0;
	else
	{
		double mse = sse / (double)(I1.channels() * I1.total()); //  sse/(w*h*3)  
		double psnr = 20.0 * log10((255) / sqrt(mse));
		return psnr;
	}
}

double MyProcessList::ssim(cv::Mat & i1, cv::Mat & i2)
{
	const double C1 = 6.5025, C2 = 58.5225;
	int d = CV_32F;
	cv::Mat I1, I2;
	i1.convertTo(I1, d);
	i2.convertTo(I2, d);
	cv::Mat I1_2 = I1.mul(I1);
	cv::Mat I2_2 = I2.mul(I2);
	cv::Mat I1_I2 = I1.mul(I2);
	cv::Mat mu1, mu2;
	GaussianBlur(I1, mu1, cv::Size(11, 11), 1.5);
	GaussianBlur(I2, mu2, cv::Size(11, 11), 1.5);
	cv::Mat mu1_2 = mu1.mul(mu1);
	cv::Mat mu2_2 = mu2.mul(mu2);
	cv::Mat mu1_mu2 = mu1.mul(mu2);
	cv::Mat sigma1_2, sigam2_2, sigam12;
	GaussianBlur(I1_2, sigma1_2, cv::Size(11, 11), 1.5);
	sigma1_2 -= mu1_2;

	GaussianBlur(I2_2, sigam2_2, cv::Size(11, 11), 1.5);
	sigam2_2 -= mu2_2;

	GaussianBlur(I1_I2, sigam12, cv::Size(11, 11), 1.5);
	sigam12 -= mu1_mu2;
	cv::Mat t1, t2, t3;
	t1 = 2 * mu1_mu2 + C1;
	t2 = 2 * sigam12 + C2;
	t3 = t1.mul(t2);

	t1 = mu1_2 + mu2_2 + C1;
	t2 = sigma1_2 + sigam2_2 + C2;
	t1 = t1.mul(t2);

	cv::Mat ssim_map;
	divide(t3, t1, ssim_map);
	cv::Scalar mssim = mean(ssim_map);

	double ssim = (mssim.val[0] + mssim.val[1] + mssim.val[2]) / 3;
	return ssim;
}

bool MyProcessList::IsSpecialDir(const char *path)
{
	return strcmp(path, "..") == 0 || strcmp(path, ".") == 0;
}

//判断文件属性是目录还是文件
bool MyProcessList::IsDir(int attrib)
{
	return attrib == 16 || attrib == 18 || attrib == 20;
}

//显示删除失败原因
void MyProcessList::ShowError(const char *file_name = NULL)
{
	errno_t err;
	_get_errno(&err);
	switch (err)
	{
	case ENOTEMPTY:
		printf("Given path is not a directory, the directory is not empty, or the directory is either the current working directory or the root directory.\n");
		break;
	case ENOENT:
		printf("Path is invalid.\n");
		break;
	case EACCES:
		printf("%s had been opend by some application, can't delete.\n", file_name);
		break;
	}
}

void MyProcessList::GetFilePath(const char *path, const char *file_name, char *file_path)
{
	strcpy_s(file_path, sizeof(char) * _MAX_PATH, path);
	file_path[strlen(file_path) - 1] = '\0';
	strcat_s(file_path, sizeof(char) * _MAX_PATH, file_name);
}

//递归搜索目录中文件并删除
void MyProcessList::DeleteFile(const char *path)
{
	char pcSearchPath[_MAX_PATH];
	sprintf_s(pcSearchPath, _MAX_PATH, "%s\\*", path); //pcSearchPath 为搜索路径，* 代表通配符

	_finddata_t DirInfo; //文件夹信息
	_finddata_t FileInfo; //文件信息
	intptr_t f_handle; //查找句柄

	char pcTempPath[_MAX_PATH];
	if ((f_handle = _findfirst(pcSearchPath, &DirInfo)) != -1)
	{
		while (_findnext(f_handle, &FileInfo) == 0)
		{
			if (IsSpecialDir(FileInfo.name))
				continue;
			if (FileInfo.attrib & _A_SUBDIR)//如果是目录，生成完整的路径
			{
				GetFilePath(pcSearchPath, FileInfo.name, pcTempPath);
				DeleteFile(pcTempPath); //开始递归删除目录中的内容
				if (FileInfo.attrib == 20)
					printf("This is system file, can't delete!\n");
				else
				{
					//删除空目录，必须在递归返回前调用_findclose,否则无法删除目录
					if (_rmdir(pcTempPath) == -1)
					{
						ShowError();//目录非空则会显示出错原因
					}
				}
			}
			else
			{
				strcpy_s(pcTempPath, pcSearchPath);
				pcTempPath[strlen(pcTempPath) - 1] = '\0';
				strcat_s(pcTempPath, FileInfo.name);//生成完整的文件路径

				if (remove(pcTempPath) == -1)
				{
					ShowError(FileInfo.name);
				}

			}
		}
		_findclose(f_handle);//关闭打开的文件句柄，并释放关联资源，否则无法删除空目录
	}
	else
	{
		ShowError();//若路径不存在，显示错误信息
	}
}


