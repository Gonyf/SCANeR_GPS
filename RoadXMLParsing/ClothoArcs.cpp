#include "ClothoArcs.h"

ClothoArc::ClothoArc()
{
    lengthSet = false;
    startCurvatureSet = false;
    endCurvatureSet = false;
}

ClothoArc::ClothoArc(float _length, float _startCurvature, float _endCurvature){
    setLength(_length);
    setStartCurvature(_startCurvature);
    setEndCurvature(_endCurvature);
}

ClothoArc::ClothoArc(xml_node<> *clothoArcNode){
    setStartCurvature( convertStringToDouble( clothoArcNode->first_attribute("startCurvature")->value() ) );
    setEndCurvature( convertStringToDouble( clothoArcNode->first_attribute("endCurvature")->value() ) );
    setLength( convertStringToDouble( clothoArcNode->first_attribute("length")->value() ) );
}

ClothoArc::~ClothoArc()
{
    //dtor
}

float ClothoArc::getLength(){
    checkInitialization();
    return length;
}
float ClothoArc::getStartCurvature(){
    checkInitialization();
    return startCurvature;
}
float ClothoArc::getEndCurvature(){
    checkInitialization();
    return endCurvature;
}

void ClothoArc::setLength(float _length){
    length = _length;
    lengthSet = true;
}
void ClothoArc::setStartCurvature(float _startCurvature){
    startCurvature = _startCurvature;
    startCurvatureSet = true;
}
void ClothoArc::setEndCurvature(float _endCurvature){
    endCurvature = _endCurvature;
    endCurvatureSet = true;
}

void ClothoArc::checkInitialization(){
    if(!lengthSet && !startCurvatureSet  && !endCurvatureSet){
        throw("This segment is uninitialized");
    }
}
