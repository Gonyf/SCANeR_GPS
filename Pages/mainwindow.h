#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "gps_page.h"
#include "mainmenu.h"
#include "selectscenario.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void exitSl();
	void decreaseStackIndex();
	void increaseStackIndex();
	void gotoSelectScenarioPage();
	void gotoGPSPage();


signals:
	void exitSig();

private:
	Ui::MainWindow *ui;
	GPS_page *GPSPage;
	MainMenu *mainMenu;
	SelectScenario *selectScenario;

	QStackedWidget *stack;
};

#endif // MAINWINDOW_H
