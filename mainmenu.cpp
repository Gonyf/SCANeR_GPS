#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <qdebug.h>

MainMenu::MainMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainMenu)
{
	ui->setupUi(this);
	stopThread = false;

	threadTest_INT_slet = 0;
	testThreadSend = new std::thread(&MainMenu::threadTest_slet, this);
	testThreadreceive = new std::thread(&MainMenu::threadTest_slet_Receive, this);
}

MainMenu::~MainMenu()
{
	stopThread = true;
	testThreadSend->join();
	delete ui;
}

void MainMenu::on_button_Scenario_clicked()
{
	emit gotoSelectScanarioPage();
	qDebug() << "scenario";
}

void MainMenu::threadTest_slet(){
	while(!stopThread){
		updated = true;
		threadTest_INT_slet += 1;
	}
}
void MainMenu::threadTest_slet_Receive(){
	while(!stopThread){
		if (updated){
			qDebug() << threadTest_INT_slet;
			updated = false;
		}else {
			stopThread = true;
		}
	}
}
