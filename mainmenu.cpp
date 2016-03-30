#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <qdebug.h>

MainMenu::MainMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MainMenu)
{
	ui->setupUi(this);
}

MainMenu::~MainMenu()
{
	delete ui;
}

void MainMenu::on_button_Scenario_clicked()
{
	emit gotoSelectScanarioPage();
	qDebug() << "scenario";
}
