#ifndef SELECTSCENARIO_H
#define SELECTSCENARIO_H

#define ASCIIConversion 48

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <vector>


namespace Ui {
class SelectScenario;
}

class SelectScenario : public QWidget
{
	Q_OBJECT

public:
	explicit SelectScenario(QWidget *parent = 0);
	~SelectScenario();
public slots:
	void buttonHandler();

signals:
	void gotoGPSPage();

private:
	Ui::SelectScenario *ui;
	QVBoxLayout *vlay;
	QWidget * wdg;
	int numberOfScenarios;
	std::vector <QPushButton*> buttonVector;
	std::vector <int> slet;

};

#endif // SELECTSCENARIO_H
