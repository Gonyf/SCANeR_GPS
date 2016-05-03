#include "gps_canvas.h"
#include <QDebug>

GPS_Canvas::GPS_Canvas(QWidget* Parent, const QPoint& Position, const QSize& Size) :
SFML_Widget(Parent, Position, Size)
{
	view.reset(sf::FloatRect(0, 0, 800*0.72, 480*0.72));
}
GPS_Canvas::GPS_Canvas(QWidget* Parent) :
SFML_Widget(Parent)
{
	view.reset(sf::FloatRect(0, 0, 800 * 0.72, 480 * 0.72));
}

//GPS_Canvas::~GPS_Canvas(){}
void GPS_Canvas::OnInit(){
	// Load the image
	//myImage.loadFromFile("/home/gonyf/Wallpapers/33818_abstract_geometric_abstract_shapes.jpg");

	// Setup the sprite
	//myTexture.loadFromImage(myImage);
	//myTexture.setSmooth(false);
	//mySprite.setTexture(myTexture, false);
	//mySprite.SetCenter(mySprite.getSize() / 2.f);

	// initialize the vertex array
	road.push_back(sf::Vertex(sf::Vector2f(50,50), sf::Color::Red));
	road.push_back(sf::Vertex(sf::Vector2f(50,200), sf::Color::Red));
	road.push_back(sf::Vertex(sf::Vector2f(200,50), sf::Color::Red));

	road.push_back(sf::Vertex(sf::Vector2f(100,100), sf::Color::Red));

}

void GPS_Canvas::OnUpdate(){
	// Clear screen
	clear(sf::Color(0, 0, 0));
	//

	// Rotate the sprite
	//mySprite.rotate(100.0f);
	//mySprite.setScale(float(parentWidget()->size().width()) / float(myImage.getSize().x), float(parentWidget()->size().height()) / float(myImage.getSize().y));

	// Draw it
	//draw(&road[0], road.size(), sf::Triangles);
    //view.setRotation(90);
	setView(view);
	draw(roadCLA);
	//roadCLA.setOrigin(-200,-200);
}

void GPS_Canvas::moveMap2(){
	roadCLA.rotate(15);
	qDebug() << "CLACK!";
}

void GPS_Canvas::setViewRotation(float _angle){
    //view.setRotation(view.getRotation()+_angle);
    view.setRotation(_angle);
}

void GPS_Canvas::setViewCenter(float _x, float _y){
    //view.setCenter(view.getCenter().x + _x, view.getCenter().y + _y);
   view.setCenter(_x, _y);
}

void GPS_Canvas::setViewSize(float _x, float _y){
	view.setSize(_x, _y);
}
