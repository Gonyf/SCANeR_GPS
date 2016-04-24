#include "CircleArc.h"

CircleArc::CircleArc(){
    curvatureSet = false;
    lengthSet = false;
}

CircleArc::CircleArc(float _curvature, float _length){
    setCurvature(_curvature);
    setLength   (_length);
}

CircleArc::CircleArc(xml_node<> *circleArcNode){
    setCurvature( convertStringToDouble( circleArcNode->first_attribute("curvature")->value() ) );
    setLength( convertStringToDouble( circleArcNode->first_attribute("length")->value() ) );
}

CircleArc::~CircleArc() {   }

void CircleArc::setCurvature(float _curvature){
    curvature = _curvature;
    curvatureSet = true;
}

void CircleArc::setLength(float _length){
    length = _length;
    lengthSet = true;
}

float CircleArc::getCurvature(){
    checkInitialization();
    return curvature;
}

float CircleArc::getLength(){
    checkInitialization();
    return length;
}

void CircleArc::checkInitialization(){
    if(!lengthSet && !curvatureSet){
        cout << "This circle arc is uninitialized" << endl;
        throw("This circle arc is uninitialized");
    }
}
