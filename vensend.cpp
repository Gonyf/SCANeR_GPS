#include "vensend.h"
#include <qdebug.h>

VENSend::VENSend()
{
    venCom = VENCreate();
    VENInit(venCom, "239.255.0.1", 63999, VENSendNonBuffered);
}
VENSend::~VENSend(){}

void VENSend::sendDouble(double command){
    qDebug() << command;
    double dataOut[1] = {command};
    qDebug() << dataOut[0];
    VENMessageWrite(venCom, "SCANER_SCENARIO", "FROM_SCANER", VENTypeDouble, dataOut, 1);
    //VENRelease(venCom);
}
position VENSend::getPosition(){
    position carPosition;
    double dataIn[2]; // remove the number
    while (VENMessageAvailable(venCom, "SCANER_SCENARIO", "Position") == 0)
    {   }
    if(VENMessageReadd(venCom,
                       "SCANER_SCENARIO",
                       "Position",
                       dataIn,
                       2) == 0){
        qDebug() << "Data recieved: ";
    }
    carPosition.x = dataIn[0];
    carPosition.y = dataIn[1];
    return carPosition;
}

double VENSend::getAngle(){
    double dataIn[1]; // remove the number
    while (VENMessageAvailable(venCom, "SCANER_SCENARIO", "Angle") == 0)
    {   }
    if(VENMessageReadd(venCom,
                       "SCANER_SCENARIO",
                       "Angle",
                       dataIn,
                       1) == 0){
        qDebug() << "Data recieved: ";
    }
    return dataIn[0];
}
