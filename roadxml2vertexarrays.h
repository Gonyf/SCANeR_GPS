#ifndef ROADXML2VERTEXARRAYS_H
#define ROADXML2VERTEXARRAYS_H
#include <string>
#include <utility>      // std::pair, std::make_pair
#include "Defines_Structures_Functions.h"
#include <fstream>
#include <iostream>
#include "RoadXMLParsing/rapidxml.hpp"
#include <vector>
#include "RoadXMLParsing/XYCurve.h"
#include <QDebug>
#include <math.h>
#include <iostream>
using namespace std;
using namespace rapidxml;

class RoadXML2VertexArrays
{
public:
	RoadXML2VertexArrays(string _path);
	vector <position> getSegmentVertices() { return segmentsVertices; }
	vector <position> getCircleArcVertices(){ return circleArcVertices; }
	vector <position> getClothoArcVertices() { return clothoArcVertices; }

private:
	void fillVertexArrays();
	position segment2Vertices(position _startPosition, double _startDirection, double _length);
	pair <position, double> circleArc2Vertices(position _startPosition, double _startDirection, double _length, double _curvature);
	pair <position,position> calculateCornerOfRoadVertices(position _middleOfRoad, double _angle);
	position calculateEndPointOfRoad(position _startPosition, double _direction, double _length);
	position calculateCenterOfCircle(position _startPosition, double _XYCurveDirection, double _radius);

	xml_document<> roadXMLDoc; // To store the RoadXML-document
	xml_node<> *subNetwork_node;
	//vector<char> buffer;
	vector<XYCurve> XYCurveVector;
	vector<position> segmentsVertices;
	vector <position> circleArcVertices;
	vector<position> clothoArcVertices;

	int circleArcIterator;
};

#endif // ROADXML2VERTEXARRAYS_He
