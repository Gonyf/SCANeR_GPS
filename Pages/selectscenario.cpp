#include "selectscenario.h"
#include "ui_selectscenario.h"
#include <qdebug.h>
#include "testpage.h"
#include <QPushButton>
#include <QFrame>
#include <QHBoxLayout>

SelectScenario::SelectScenario(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SelectScenario)
{
	ui->setupUi(this);
	vlay = new QVBoxLayout(this);
	//implement a way to get number of scenarios from simulator computer
	//but for now, have a fixed counter
	numberOfScenarios = 5;

	for (int scenarioCounter = 0; scenarioCounter < numberOfScenarios; scenarioCounter++){
		buttonVector.push_back(new QPushButton);
		QString buttonName = "Scenario ";
		buttonName += char(scenarioCounter + 1 + ASCIIConversion);
		buttonVector[scenarioCounter]->setText(buttonName);
		buttonVector[scenarioCounter]->setMinimumHeight(50);
		vlay->addWidget(buttonVector[scenarioCounter]);
		connect(buttonVector[scenarioCounter], SIGNAL( released() ),this, SLOT(buttonHandler() ) );
	}
	this->setLayout(vlay);
}

SelectScenario::~SelectScenario()
{
	delete ui;
}

void SelectScenario::buttonHandler(){
	emit gotoGPSPage();
	qDebug() << "ewfjewp";
}
