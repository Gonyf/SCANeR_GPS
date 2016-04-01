#include "testpage.h"
#include "ui_testpage.h"
#include <QPainter>

TestPage::TestPage(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::TestPage)
{
    ui->setupUi(this);
	//this->setStyleSheet("background:transparent");
	//setAttribute(Qt::WA_TranslucentBackground);
	//setWindowFlags(Qt::FramelessWindowHint);

	QPalette pal = palette();
	pal.setBrush(QPalette::Window, QColor(100, 2, 2, 255) );
	setPalette(pal);
	setAutoFillBackground(true);
}

TestPage::~TestPage()
{
    delete ui;
}

//void TestPage::on_pushButto_Quit_clicked()
//{
//    emit killALL();
//}

void TestPage::on_pushButton_Back_clicked()
{
    emit back();
}

void TestPage::on_pushButton_Launch_clicked()
{
	qDebug() << "Launch clicked";
	#ifdef __arm__
		sender.sendDouble(0);
	#endif
}

void TestPage::on_pushButton_Play_clicked()
{
	qDebug() << "Play clicked";
	#ifdef __arm__
		sender.sendDouble(1.0);
	#endif

}

void TestPage::on_pushButton_Pause_clicked()
{
	qDebug() << "Pause clicked";
	#ifdef __arm__
		sender.sendDouble(2.0);
	#endif
}

void TestPage::on_pushButton_Stop_clicked()
{
	qDebug() << "Stop clicked";
	#ifdef __arm__
		sender.sendDouble(3.0);
	#endif

}

void TestPage::on_pushButton_Crash_clicked()
{
	qDebug() << "Crash clicked";
	#ifdef __arm__
		sender.sendDouble(4.0);
	#endif
}

void TestPage::on_pushButton_QuitPCApp_clicked()
{
	qDebug() << "Quit on PC clicked";
	#ifdef __arm__
		sender.sendDouble(6.0);
	#endif

}

void TestPage::on_pushButton_BadRequest_clicked()
{
	qDebug() << "Bad request clicked";
	#ifdef __arm__
		sender.sendDouble(40.0);
	#endif

}

void TestPage::on_pushButton_Kill_all_processes_clicked()
{
	qDebug() << "Kill all processes clicked";
	#ifdef __arm__
		sender.sendDouble(5.0);
	#endif
}

void TestPage::on_pushButto_Quit_clicked()
{
	qDebug() << "Quit clicked";
	emit quit_clicked();
}
