#ifndef SEGMENT_H
#define SEGMENT_H

#include "Defines_Structures_Functions.h"
#include "rapidxml.hpp"

using namespace rapidxml;
class Segment
{
    public:
        Segment();
        Segment(float _length);
        Segment(xml_node<> *segmentNode);
        virtual ~Segment();

        void setLength(float _length);

        float getLength();
    private:
        float length;
        bool lengthSet;
};

#endif // SEGMENT_H
