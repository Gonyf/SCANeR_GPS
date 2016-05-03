#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	// Get stack widget
	stack = centralWidget()->findChild<QStackedWidget *>("widgetStack");

	// Initialize widgets
	GPSPage = new GPS_page;
	mainMenu = new MainMenu;
	selectScenario = new SelectScenario;

	// Add widgets to the widget stack
	stack->addWidget(mainMenu);
	stack->addWidget(selectScenario);
	stack->addWidget(GPSPage);

	// set current widget for stacked widget
	stack->setCurrentWidget(mainMenu);

	connect( mainMenu, SIGNAL( gotoSelectScanarioPage() ), this, SLOT( gotoSelectScenarioPage() ) );
	connect( selectScenario, SIGNAL( gotoGPSPage() ), this, SLOT( gotoGPSPage() ) );
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::exitSl(){
	emit exitSig();
}

void MainWindow::decreaseStackIndex(){
	stack->setCurrentIndex(stack->currentIndex()-1);
}

void MainWindow::increaseStackIndex(){
	stack->setCurrentIndex(stack->currentIndex()+1);
}
void MainWindow::gotoSelectScenarioPage(){
	stack->setCurrentIndex(stack->indexOf(selectScenario));
	qDebug() << "scenarioMM";
}
void MainWindow::gotoGPSPage(){
	stack->setCurrentIndex(stack->indexOf(GPSPage));
	qDebug() << "scenarioMM";
}
