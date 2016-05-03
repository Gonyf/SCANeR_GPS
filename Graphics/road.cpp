#include "road.h"

Road::Road()
{
	roadArr.push_back(sf::Vertex(sf::Vector2f(0, 10), sf::Color::Red));
	roadArr.push_back(sf::Vertex(sf::Vector2f(10, 0), sf::Color::Green));
	roadArr.push_back(sf::Vertex(sf::Vector2f(-10, 0), sf::Color::Red));

	RoadXML2VertexArrays extractedVertices("/home/gonyf/Qt/Projects/SCANeR_GPS/Big_roundabout.rnd");
	addSegmentVerticesFromPositions(extractedVertices.getSegmentVertices());
	addCircleArcVerticesFromPositions(extractedVertices.getCircleArcVertices());
}
void Road::addSegmentVerticesFromPositions(vector <position> _segmentVertexPositions){
	for (unsigned int positionIterator = 0; positionIterator < _segmentVertexPositions.size(); positionIterator++){
		position vertexPosition = _segmentVertexPositions[positionIterator];
		segmentVertices.push_back(sf::Vertex(sf::Vector2f(vertexPosition.x,   -vertexPosition.y), sf::Color::Blue));
	}
}

void Road::addCircleArcVerticesFromPositions(vector <position> _circleArcVertexPositions){
	for (unsigned int positionIterator = 0; positionIterator < _circleArcVertexPositions.size(); positionIterator++){
		position vertexPosition = _circleArcVertexPositions[positionIterator];
		circleArcVertices.push_back(sf::Vertex(sf::Vector2f(vertexPosition.x, -vertexPosition.y), sf::Color::Green));
	}
}
