#ifndef ROAD_H
#define ROAD_H
#include <SFML/Graphics.hpp>
#include <vector>

class Road : public sf::Drawable, public sf::Transformable
{
public:
	Road();
	~Road(){}
	//void virtual move(float,float){}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the entity's transform -- combine it with the one that was passed by the caller
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

		// apply the texture
		states.texture = &m_texture;

		// you may also override states.shader or states.blendMode if you want

		// draw the vertex array
		target.draw(&roadArr[0], roadArr.size(), sf::Triangles, states);
	}

	std::vector<sf::Vertex> roadArr;
	sf::Texture m_texture;
};

#endif // ROAD_H
