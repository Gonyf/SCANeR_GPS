#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <thread>
//#include "page.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
	Q_OBJECT

public:
	explicit MainMenu(QWidget *parent = 0);
	~MainMenu();

private slots:
	void on_button_Scenario_clicked();

signals:
	void gotoSelectScanarioPage();

private:
	Ui::MainMenu *ui;
	int threadTest_INT_slet;
	bool updated;

	std::thread *testThreadSend;
	std::thread *testThreadreceive;
	bool stopThread;
	void threadTest_slet();
	void threadTest_slet_Receive();
};

#endif // MAINMENU_H
