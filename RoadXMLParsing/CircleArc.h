#ifndef CIRCLEARC_H
#define CIRCLEARC_H

#include <iostream>

#include "rapidxml.hpp"
#include "Defines_Structures_Functions.h"

using namespace rapidxml;

class CircleArc
{
    public:
        CircleArc();
        CircleArc(float _curvature, float _length);
        CircleArc(xml_node<> *circleArcNode);
        virtual ~CircleArc();

        void setCurvature(float curvature);
        void setLength(float Length);

        float getCurvature();
        float getLength();
    protected:
    private:
        float curvature;
        float length;

        bool curvatureSet;
        bool lengthSet;

        void checkInitialization();
};

#endif // CIRCLEARC_H
