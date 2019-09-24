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


MyProcessList::MyProcessList(QWidget* parent) :QDockWidget(parent)
{
	QWidget* Widget = new QWidget;
	ui.setupUi(Widget);
	this->setWidget(Widget);
	this->setWindowTitle(QStringLiteral("处理列表"));
	this->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	this->hide();

	connect(ui.pB_do, SIGNAL(clicked()), this, SLOT(doProcess()));
	connect(ui.pB_reset, SIGNAL(clicked()), this, SLOT(originPic()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(getPath()));
}

MyProcessList::~MyProcessList()
{
	
}

void MyProcessList::getPic(cv::Mat Pic)
{
	img = Pic.clone();
	origin_img = Pic.clone();
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
	if (img.empty()) return;
	if (ui.cB_addFog->isChecked()) {
		img = addfog(ui.fog_para->value(), img);
	}
	if (ui.cB_addRain->isChecked()) {
		img = addrain(ui.rain_para->value(), ui.rain_path->text().toStdString(), img);
	}
	if (ui.cB_addSnow->isChecked()) {
		img = addsnow(ui.snow_para->value(), img);
	}
	emit creatWin(img);
	ui.PSNR->setText(QString::number(psnr(origin_img, img), 10, 2));
	ui.SSIM->setText(QString::number(ssim(origin_img, img), 10, 2));
	
}

void MyProcessList::originPic()
{
	ui.PSNR->setText("");
	ui.SSIM->setText("");
	img = origin_img.clone();
	emit creatWin(img);
}


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