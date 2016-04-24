#include "XYCurve.h"

XYCurve::XYCurve(){
    xSet            = false;
    ySet            = false;
    directionSet    = false;
}

XYCurve::XYCurve(float _direction, float _x, float _y){
    setDirection(_direction);
    setX        (_x);
    setY        (_y);
}

XYCurve::XYCurve(rapidxml::xml_node<> *XYCurveNode){
    segmentIterator = 0;
    CircleArcIterator = 0;
    ClothoArcIterator = 0;
    setDirection( convertStringToDouble( string(XYCurveNode->first_attribute()->value()) ) );
    setX( convertStringToDouble( XYCurveNode->first_attribute("x")->value() ) );
    setY( convertStringToDouble( XYCurveNode->first_attribute("y")->value() ) );

    for (xml_node<> *curveElement = XYCurveNode->first_node(); curveElement; curveElement = curveElement->next_sibling()){
        string elementType = curveElement->name();
        addElementToSequence(elementType);
        if (elementType.compare("Segment") == 0){
            addSegment(Segment(curveElement ) );
            addElemenToSequenceEnum(Segment_Enum);
        }
        else if (elementType.compare("CircleArc") == 0){
            addCircleArc( CircleArc(curveElement) );
            addElemenToSequenceEnum(CircleArc_Enum);
        }
        else if (elementType.compare("ClothoArc") == 0){
            addClothoArc( ClothoArc(curveElement) );
            addElemenToSequenceEnum(ClothoArc_Enum);
        }
        else{
            cout << "shit" << endl;
        }
    }
}

XYCurve::~XYCurve() {   }

/// ############## sets ##################
void XYCurve::setDirection(float _direction){
    direction       = _direction;
    directionSet    = true;
}

void XYCurve::setX(float _x){
    x       = _x;
    xSet    = true;
}

void XYCurve::setY(float _y){
    y       = _y;
    ySet    = true;
}

/// ############ gets ####################
float XYCurve::getDirection(){
    checkInitialization();
    return direction;
}

float XYCurve::getX(){
    checkInitialization();
    return x;
}

float XYCurve::getY(){
    checkInitialization();
    return y;
}
vector<int> XYCurve::getSequence(){
    return sequence_Enum;
}

Segment XYCurve::getNextSegment(){
    return segments[segmentIterator++];
}
CircleArc XYCurve::getNextCircleArc(){
    return circleArcs[CircleArcIterator++];
}
ClothoArc XYCurve::getNextClothoArc(){
    return clothoArcs[ClothoArcIterator++];
}

/// ############ CHECKS ##################
void XYCurve::checkInitialization(){
    if (!directionSet && !xSet && !ySet){
        throw("XYCurve uninitialized!");
    }
}

/// ############## ADDS ####################
void XYCurve::addCircleArc(CircleArc _circleArc){
    circleArcs.push_back(_circleArc);
}

void XYCurve::addSegment(Segment _segment){
    segments.push_back(_segment);
}

void XYCurve::addClothoArc(ClothoArc _clothoArc){
    clothoArcs.push_back(_clothoArc);
}

void XYCurve::addElementToSequence(string _elementName){
    sequence.push_back(_elementName);
}

void XYCurve::addElemenToSequenceEnum(int _elementEnum){
    sequence_Enum.push_back(_elementEnum);
}

/// ############### Prints ######################
void XYCurve::printElementSequence(){
    for (unsigned int i = 0; i < sequence.size(); i++){
        cout << sequence[i] << endl;
    }
}
void XYCurve::printElementSequenceEnum(){
    for (unsigned int i = 0; i < sequence_Enum.size(); i++){
        cout << sequence_Enum[i] << endl;
    }
}
void XYCurve::printSegmentAttributes(){
    for(unsigned int i = 0; i < segments.size(); i++){
        cout << "Length:\t " << segments[i].getLength() << endl;
    }
}
void XYCurve::printCircleArcAttributes(){
    for(unsigned int i = 0; i < circleArcs.size(); i++){
        cout << "Length:\t\t " << circleArcs[i].getLength() << endl;
        cout << "Curvature:\t " << circleArcs[i].getCurvature() << endl;
    }
}
void XYCurve::printClothoArcAttributes(){
    for(unsigned int i = 0; i < clothoArcs.size(); i++){
        cout << "Length:\t\t\t " << clothoArcs[i].getLength() << endl;
        cout << "Start Curvature:\t " << clothoArcs[i].getStartCurvature() << endl;
        cout << "End Curvature:\t\t " << clothoArcs[i].getEndCurvature() << endl;
    }
}

/// ########## ATTRIBUTES ##############
bool XYCurve::circleArcsEmpty(){
    return circleArcs.empty();
}
bool XYCurve::segmentEmpty(){
    return segments.empty();
}
bool XYCurve::clothoArcsEmpty(){
    return clothoArcs.empty();
}
