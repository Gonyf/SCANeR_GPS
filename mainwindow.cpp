#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	canvas = new GPS_Canvas(ui->MUGPS_widget);
	//ui->MUGPS_widget = canvas;

	connect(this, SIGNAL(click()), canvas, SLOT(moveMap2()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	qDebug() << "Click!!";
	emit click();
}
