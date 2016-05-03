#include "roadxml2vertexarrays.h"

RoadXML2VertexArrays::RoadXML2VertexArrays(string _path)
{
	circleArcIterator = 0;
	/// Read the xml file into a vector
	ifstream theFile;
	theFile.open(_path); //creating the file

	if (!theFile){
		qDebug() << "RoadXML file not found";
	}
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0'); //zero terminate the buffer
	/// Parse the buffer using the xml file parsing library into doc
	roadXMLDoc.parse<0>(&buffer[0]);
	/// Find the parent node of all the XY curves root node (SubNetwork)
	subNetwork_node = roadXMLDoc.first_node("RoadXML")->first_node("Network")->first_node("SubNetwork");

	/// For each track in the SubNetwork node
	for (xml_node<> *trackNode = subNetwork_node->first_node("Track"); trackNode; trackNode = trackNode->next_sibling("Track")){
		/// For each XYCurve in the track (This should not be a for loop)
		XYCurveVector.push_back( XYCurve( trackNode->first_node("XYCurve") ) );
	}
	fillVertexArrays();
}

void RoadXML2VertexArrays::fillVertexArrays(){
	for (unsigned int xyCurveIterator = 0; xyCurveIterator < XYCurveVector.size(); xyCurveIterator++){
		vector <int> elementSequence = XYCurveVector[xyCurveIterator].getSequence();
		position currentPosition(XYCurveVector[xyCurveIterator].getX(), XYCurveVector[xyCurveIterator].getY());
		double currentDirection = XYCurveVector[xyCurveIterator].getDirection();

		int debug_lastElement = 400; // dummy variable

		for(unsigned int sequenceIterator = 0; sequenceIterator < elementSequence.size(); sequenceIterator++){
			if (elementSequence[sequenceIterator] == Segment_Enum){
				qDebug() << "Remember to change the debugging in this if-statement";
				double length = XYCurveVector[xyCurveIterator].getNextSegment().getLength();
				if ((debug_lastElement == 400) || (debug_lastElement == Segment_Enum || debug_lastElement == CircleArc_Enum)){
					currentPosition = segment2Vertices(currentPosition, currentDirection, length);
				}
				debug_lastElement = Segment_Enum;
			}
			else if (elementSequence[sequenceIterator] == CircleArc_Enum){
				if ((debug_lastElement == 400) || (debug_lastElement == Segment_Enum) || debug_lastElement == CircleArc_Enum){
					CircleArc currentCircleArc	= XYCurveVector[xyCurveIterator].getNextCircleArc();
					double length				= currentCircleArc.getLength();
					double curvature			= currentCircleArc.getCurvature();
					pair <position, double> position_direction = circleArc2Vertices(currentPosition, currentDirection, length, curvature);
					currentPosition				= position_direction.first;
					currentDirection			= position_direction.second;
				}
				debug_lastElement = CircleArc_Enum;
			}
			else if (elementSequence[sequenceIterator] == ClothoArc_Enum){
				debug_lastElement = ClothoArc_Enum;
			}
		}

	}

}

position RoadXML2VertexArrays::segment2Vertices(position _startPosition, double _startDirection, double _length){
	pair <position,position> startVerticesPositions = calculateCornerOfRoadVertices(_startPosition, _startDirection);

	position endPoint = calculateEndPointOfRoad(_startPosition, _startDirection, _length);
	pair <position,position> endVerticesPositions = calculateCornerOfRoadVertices(endPoint, _startDirection);

	// push back positions one corner at a time in either clockwise or counter-clockwise order.
	segmentsVertices.push_back(startVerticesPositions.first);
	segmentsVertices.push_back(endVerticesPositions.first);
	segmentsVertices.push_back(endVerticesPositions.second);
	segmentsVertices.push_back(startVerticesPositions.second);

	return endPoint;
}

pair <position, double> RoadXML2VertexArrays::circleArc2Vertices(position _startPosition, double _startDirection, double _length, double _curvature){
	double radius					= 1.0 / _curvature;
	position centerPoint = calculateCenterOfCircle(_startPosition, _startDirection, radius);
	double startDirectionFromCenter = _startDirection - 0.5 * M_PI * sign(radius);
	double directionToNextPoint		= startDirectionFromCenter;
	double totalAngleOfCircleArc	= _length/fabs(radius);
	double currentAngleOfCircleArc	= 0.0;
	bool firstPoint = true;
	int pointOffset			= 0.5 * ROAD_WIDTH;
	position nextPoint = calculateEndPointOfRoad(centerPoint, directionToNextPoint, fabs(radius) + pointOffset);

	while (currentAngleOfCircleArc <= totalAngleOfCircleArc){
		// the first point is added twice in order to avoid continuation from the last circle arc.
		//(The last point is also added twice for the same reason)
		if (firstPoint){
			firstPoint = false;
			circleArcVertices.push_back(nextPoint);
		}
		circleArcVertices.push_back(nextPoint);
		pointOffset *= -1; // every other time we want the point on the inner circle and every other time we want the point on the outer circle.
		directionToNextPoint += DELTA_ANGLE * sign(radius);
		currentAngleOfCircleArc += DELTA_ANGLE;
		nextPoint = calculateEndPointOfRoad(centerPoint, directionToNextPoint, fabs(radius) + pointOffset);
	}
	//push back the exact last two points
	nextPoint = calculateEndPointOfRoad(centerPoint, directionToNextPoint, fabs(radius) + pointOffset);
	nextPoint = calculateEndPointOfRoad(centerPoint, directionToNextPoint, fabs(radius) - pointOffset);
	circleArcVertices.push_back(circleArcVertices[circleArcVertices.size()-1]);

	// calculate the current position and -direction and return them
	directionToNextPoint		-= DELTA_ANGLE * sign(radius); // redo the last addition
	double currentDirection		 = directionToNextPoint + 0.5 * M_PI * sign(radius);
	position currentPosition	 = calculateEndPointOfRoad(centerPoint, directionToNextPoint, fabs(radius) );
	pair <position, double> returnPair = make_pair(currentPosition, currentDirection);
	return returnPair;
}

pair <position,position> RoadXML2VertexArrays::calculateCornerOfRoadVertices(position _middleOfRoad, double _angle){
	double upperX = cos(_angle + 0.5 * M_PI) * 0.5 * ROAD_WIDTH + _middleOfRoad.x;
	double upperY = sin(_angle + 0.5 * M_PI) * 0.5 * ROAD_WIDTH + _middleOfRoad.y;
	position upperPosition(upperX, upperY);
	double lowerX = cos(_angle - 0.5 * M_PI) * 0.5 * ROAD_WIDTH + _middleOfRoad.x;
	double lowerY = sin(_angle - 0.5 * M_PI) * 0.5 * ROAD_WIDTH + _middleOfRoad.y;
	position lowerPosition(lowerX, lowerY);
	pair <position,position> returnPair = make_pair(upperPosition,lowerPosition);
	return returnPair;
}


position RoadXML2VertexArrays::calculateEndPointOfRoad(position _startPosition, double _direction, double _length){
	double xEnd = cos(_direction) * _length + _startPosition.x;
	double yEnd = sin(_direction) * _length + _startPosition.y;
	return position(xEnd, yEnd);
}

position RoadXML2VertexArrays::calculateCenterOfCircle(position _startPosition, double _XYCurveDirection, double _radius){
	position centerOfCircle;
	double directionToCenter = _XYCurveDirection + (0.5 * M_PI);// * sign(_radius);
	centerOfCircle = calculateEndPointOfRoad(_startPosition, directionToCenter, (_radius) );
	return centerOfCircle;
}
