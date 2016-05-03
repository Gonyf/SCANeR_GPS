#ifndef ROAD_H
#define ROAD_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "roadxml2vertexarrays.h"
#include <qdebug.h>

class Road : public sf::Drawable, public sf::Transformable
{
public:
	Road();
	~Road(){}
	//void virtual move(float,float){}
	void AddSegment(float position);

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
		target.draw(&segmentVertices[0], segmentVertices.size(), sf::Quads, states);
		target.draw(&circleArcVertices[0], circleArcVertices.size(), sf::TrianglesStrip, states);
	}
	void addSegmentVerticesFromPositions(vector <position> _segmentVertexPositions);
	void addCircleArcVerticesFromPositions(vector <position>  _circleArcVertexPositions);

	std::vector<sf::Vertex> roadArr;
	std::vector<sf::Vertex> segmentVertices;
	std::vector<sf::Vertex> circleArcVertices;
	std::vector<sf::Vertex> clothoArcVertices;
	sf::Texture m_texture;
};

#endif // ROAD_H
