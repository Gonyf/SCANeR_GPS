#ifndef CLOTHOARCS_H
#define CLOTHOARCS_H

#include "rapidxml.hpp"
#include "defines_functions.h"

using namespace rapidxml;

class ClothoArc
{
    public:
        ClothoArc();
        ClothoArc(float _length, float _startCurvature, float _endCurvature);
        ClothoArc(xml_node<> *clothoArcNode);
        virtual ~ClothoArc();

        float getLength();
        float getStartCurvature();
        float getEndCurvature();

        void setLength(float _length);
        void setStartCurvature(float _startCurvature);
        void setEndCurvature(float _endCurvature);
    protected:
    private:
        float length;
        float startCurvature;
        float endCurvature;

        bool lengthSet;
        bool startCurvatureSet;
        bool endCurvatureSet;

        void checkInitialization();
};

#endif // CLOTHOARCS_H
