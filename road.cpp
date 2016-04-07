#include "road.h"

Road::Road()
{
    roadArr.push_back(sf::Vertex(sf::Vector2f(70,0), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(70, 480), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(200,0), sf::Color::Red));
}


