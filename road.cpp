#include "road.h"

Road::Road()
{
	roadArr.push_back(sf::Vertex(sf::Vector2f(0,0), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(0,640), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(100,0), sf::Color::Red));
}


