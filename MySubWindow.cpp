#include "MySubWindow.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>

MySubWindow::MySubWindow(QString str, cv::Mat & image)
{
	widget = new QWidget(this);
	ui.setupUi(widget);
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setWidget(widget);
	title = str;
	originalScene = new QGraphicsScene(this);
	rects = nullptr;
	ui.graphicsView->setScene(originalScene);
	setImg(image);

	scale_rate = 0;
	contextMenu = new QMenu;
	a_zoom_in = new QAction(QStringLiteral("放大"), this);
	a_zoom_out = new QAction(QStringLiteral("缩小"), this);
	a_reset = new QAction(QStringLiteral("100%大小"), this);
	contextMenu->addAction(a_zoom_in);
	contextMenu->addAction(a_zoom_out);
	contextMenu->addAction(a_reset);
	connect(ui.graphicsView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showListWidgetMenuSlot(QPoint)));
	connect(a_zoom_in, SIGNAL(triggered()), this, SLOT(a_zoom_in_triggered()));
	connect(a_zoom_out, SIGNAL(triggered()), this, SLOT(a_zoom_out_triggered()));
	connect(a_reset, SIGNAL(triggered()), this, SLOT(a_reset_triggered()));
}

MySubWindow::~MySubWindow()
{
	img.release();
	delete originalScene;
	delete widget;
}

void MySubWindow::setImg(cv::Mat & image)
{
	img = image;
	QImage qImage((const unsigned char*)(img.data), img.cols, img.rows, img.step, QImage::Format_RGB888);
	QPixmap* pix = new QPixmap();
	*pix = QPixmap::fromImage(qImage.rgbSwapped());
	if (rects != nullptr)
	{
		originalScene->destroyItemGroup(rects);
		rects = nullptr;
	}
	originalScene->clear();
	originalScene->addPixmap(*pix);
	delete pix;
	this->setWindowTitle(title + "*");
}

void MySubWindow::closeEvent(QCloseEvent * event)
{
	event->accept();
}

cv::Mat MySubWindow::getMat()
{
	return img.clone();
}


void MySubWindow::SaveImg()
{
	QString file = QFileDialog::getSaveFileName(this, QStringLiteral("保存结果"),
		"", QStringLiteral("PNG图像 (*.png);;JPG图像 (*.jpg);;BMP图像 (*.bmp)"));
	if (file.isEmpty())
		return;
	else
	{
		if (cv::imwrite(file.toStdString(), img))
		{
			QFileInfo fileInfo(file);
			title = fileInfo.fileName();
			isSaved = true;
			this->setWindowTitle(title);
		}
	}
}


void MySubWindow::showListWidgetMenuSlot(QPoint pos)
{
	contextMenu->exec(QCursor::pos());
}

void MySubWindow::a_zoom_in_triggered()
{
	if (scale_rate < 4) {
		++scale_rate;
		if (scale_rate == 4)
			a_zoom_in->setDisabled(true);
		if (scale_rate == -3)
			a_zoom_out->setEnabled(true);
		ui.graphicsView->scale(2, 2);
	}
}

void MySubWindow::a_zoom_out_triggered()
{
	if (scale_rate > -4) {
		--scale_rate;
		if (scale_rate == -4)
			a_zoom_out->setDisabled(true);
		if (scale_rate == 3)
			a_zoom_in->setEnabled(true);
		ui.graphicsView->scale(0.5, 0.5);
	}
}

void MySubWindow::a_reset_triggered()
{
	a_zoom_in->setEnabled(true);
	a_zoom_out->setEnabled(true);
	qreal rate = pow(2, -scale_rate);
	ui.graphicsView->scale(rate, rate);
	scale_rate = 0;
}