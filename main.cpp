<<<<<<< HEAD
#include <qtextstream.h>
=======
>>>>>>> 8e9d379af22964e4d14f82db5ade09ac84c90df2
#include "mainwindow.h"
#include <QApplication>
//#include <SFML/Graphics.hpp>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	/*sf::RenderWindow window(sf::VideoMode(800, 640), "SFML works!");
	sf::CircleShape shape(640.0f/2);
	shape.setFillColor(sf::Color::Yellow);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/

	return a.exec();
}
