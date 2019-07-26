#include "Simulation.h"
#include <QFileDialog> 


Simulation::Simulation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionfog, SIGNAL(triggered()), this, SLOT(a_addfog()));
	connect(ui.actionsnow, SIGNAL(triggered()), this, SLOT(a_addsnow()));
	connect(ui.actionrain, SIGNAL(triggered()), this, SLOT(a_addrain()));
	scene = new QGraphicsScene();
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}


void Simulation::a_addfog() {
	Mat srcImg = imread("Resources/timg.png");
	double beta = 0.75;
	Mat fog_img = fog(srcImg, beta);
	QImage image = Mat2QImg(fog_img);
	scene->clear();
	scene->addPixmap(QPixmap::fromImage(image));
}

void Simulation::a_addsnow()
{
	Mat srcImg = imread("Resources/timg.png");
	double ext = 1;
	Mat fog_img = addSnow(srcImg, ext);
	QImage image = Mat2QImg(fog_img);
	scene->clear();
	scene->addPixmap(QPixmap::fromImage(image));
}

void Simulation::a_addrain()
{
	//QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
	//	"./Data/point_light_database", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	Mat oriImg = imread("Resources/timg.png");
	double alpha = 1.0;
	Mat fog_img = addRain(oriImg, alpha, "./Data/point_light_database");
	QImage image = Mat2QImg(fog_img);

	scene->clear();
	scene->addPixmap(QPixmap::fromImage(image));
}

Simulation::~Simulation()
{
	delete scene;
}

QImage Simulation::Mat2QImg(const Mat & cvImg)
{
	if (cvImg.channels() == 3) {
		cvtColor(cvImg, cvImg, CV_BGR2RGB);
		return QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1) {
		return QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	return QImage((const unsigned char*)(cvImg.data),
		cvImg.cols, cvImg.rows,
		cvImg.cols*cvImg.channels(),
		QImage::Format_RGB888);
}


