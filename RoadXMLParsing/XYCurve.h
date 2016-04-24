#ifndef XYCURVE_H
#define XYCURVE_H

#include <vector>
#include <string>
#include <iostream>
#include "math.h"

#include "CircleArc.h"
#include "Segment.h"
#include "ClothoArcs.h"
#include "rapidxml.hpp"
#include "defines_functions.h"

using namespace rapidxml;
using namespace std;


class XYCurve
{
    public:
        XYCurve();
        XYCurve(float _direction, float _x, float _y);
        XYCurve(xml_node<> *XYCurveNode);
        virtual ~XYCurve();

        void setDirection(float _direction);
        void setX(float _x);
        void setY(float _y);

        float getDirection();
        float getX();
        float getY();
        vector<int> getSequence();
        Segment getNextSegment();
        CircleArc getNextCircleArc();
        ClothoArc getNextClothoArc();

        void addCircleArc(CircleArc _circleArc);
        void addSegment(Segment _segment);
        void addClothoArc(ClothoArc _clothoArc);
        void addElementToSequence(string _elementName);
        void addElemenToSequenceEnum(int _elementEnum);

        void printElementSequence();
        void printElementSequenceEnum();
        void printSegmentAttributes();
        void printCircleArcAttributes();
        void printClothoArcAttributes();


        bool circleArcsEmpty();
        bool segmentEmpty();
        bool clothoArcsEmpty();
    protected:
    private:
        float direction;
        float x;
        float y;

        bool directionSet;
        bool xSet;
        bool ySet;
        int segmentIterator;
        int CircleArcIterator;
        int ClothoArcIterator;

        vector <CircleArc> circleArcs;
        vector <Segment> segments;
        vector <ClothoArc> clothoArcs;
        vector <string> sequence;
        vector <int> sequence_Enum;

        void checkInitialization();
};

#endif // XYCURVE_H
