#ifndef SFML_WIDGET_H
#define SFML_WIDGET_H

#include <QWidget>
#include <SFML/Graphics.hpp>
#include <QTimer>
class SFML_Widget : public QWidget, public sf::RenderWindow, sf::Texture
{
	Q_OBJECT
public:
	explicit SFML_Widget(QWidget *parent = 0);
	SFML_Widget(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 60);
	virtual ~SFML_Widget();

signals:

public slots:
	void moveMap();

private:
	//Functions
	virtual void OnInit(); // Called when the SFML view is first created

	virtual void OnUpdate(); // Called before each refresh of the SFML view

	virtual void showEvent(QShowEvent*); // Initialize SFML window

	virtual void paintEvent(QPaintEvent*); // Refresh SFML view

	//Attributes
	virtual QPaintEngine* paintEngine() const;

	QTimer frameTimer;

	bool myInitialized;
};

#endif // SFML_WIDGET_H
