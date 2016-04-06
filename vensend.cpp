#include "vensend.h"
#include <qdebug.h>

VENSend::VENSend()
{
    venCom = VENCreate();
}
VENSend::~VENSend(){}

void VENSend::sendDouble(double command){
    qDebug() << command;
    VENInit(venCom, "239.255.0.1", 63999, VENSendNonBuffered);
    double dataOut[1] = {command};
    qDebug() << dataOut[0];
    VENMessageWrite(venCom, "SCANER_SCENARIO", "FROM_SCANER", VENTypeDouble, dataOut, 1);
	VENRelease(venCom);
}
