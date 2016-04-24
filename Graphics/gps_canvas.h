#ifndef GPS_CANVAS_H
#define GPS_CANVAS_H

#include "sfml_widget.h"
#include <QWidget>
#include <vector>
#include "road.h"

class GPS_Canvas : public SFML_Widget
{
	Q_OBJECT
public:
	explicit GPS_Canvas(QWidget* Parent = 0);
	GPS_Canvas(QWidget* Parent, const QPoint& Position, const QSize& Size);
	virtual ~GPS_Canvas() {}
	void setViewRotation(float _angle);
	void setViewCenter(float _x, float _y);
	void setViewSize(float _x, float _y);

public slots:
	void moveMap2();

signals:
	void click();

private:
	void OnInit();

	void OnUpdate();
	std::vector<sf::Vertex> road;
	sf::Image myImage;
	sf::Texture myTexture;
	sf::Sprite mySprite;
	sf::View view;
	Road roadCLA;

};

#endif // GPS_CANVAS_H
