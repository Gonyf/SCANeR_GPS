#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
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
};

#endif // MAINMENU_H
