#include "Segment.h"

Segment::Segment(){
    lengthSet = false;
}

Segment::Segment(float _length){
    setLength(_length);
}

Segment::Segment(xml_node<> *segmentNode){
    setLength( convertStringToDouble( segmentNode->first_attribute("length")->value() ) );
}

Segment::~Segment() {   }

void Segment::setLength(float _length){
    length = _length;
    lengthSet = true;
}

float Segment::getLength(){
    if(!lengthSet){
        throw("This segment is uninitialized");
    }
    return length;
}
