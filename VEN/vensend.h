#ifndef VENSEND_H
#define VENSEND_H
#ifdef __arm__
	#include "VEN/VEN2.h"
#include <qdebug.h>
#include "Defines_Structures.h"

using namespace std;
class VENSend
{
public:
    VENSend();
    ~VENSend();

    void sendDouble(double command);
    position getPosition();
    double getAngle();

private:
	VENCom* venCom;
};
#endif

#endif // VENSEND_H
