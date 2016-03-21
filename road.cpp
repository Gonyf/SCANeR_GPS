#include "road.h"

Road::Road()
{
	roadArr.push_back(sf::Vertex(sf::Vector2f(210,210), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(210,300), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(300,210), sf::Color::Red));
}


