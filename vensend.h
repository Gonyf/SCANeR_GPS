#ifndef VENSEND_H
#define VENSEND_H
#ifdef __arm__
	#include "VEN/VEN2.h"

class VENSend
{
public:
    VENSend();
    ~VENSend();

    void sendDouble(double command);
private:
	VENCom* venCom;
};
#endif

#endif // VENSEND_H
