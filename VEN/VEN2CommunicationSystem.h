#pragma once

#include "VEN/VEN2.h"
#include "VEN/VEN2ReceptionFunctor.h"

#include <string>

class VENCommunicator;
class VENReceptionFunctor;


///=================================================================================================
/// \brief VEN Communcation system main object.
///=================================================================================================
class VENCommunicationSystem
{
public:

	///=================================================================================================
	/// \fn	VENCommunicationSystem::VENCommunicationSystem(void)
	/// \brief	Default constructor. 
	///=================================================================================================
	VENCommunicationSystem() : myCom(NULL)
		{};
	~VENCommunicationSystem()
		{VENRelease(myCom);};

	///=================================================================================================
	/// \brief	Initialises this object. 
	/// \param	multicastAddress		The VEN multicast address. 
	/// \param	port					The VEN port. 
	/// \param 	recieveFunctor			This functor is called for each VEN message read. 
	/// \return	0 if no problem. 
	///=================================================================================================
	int init(const std::string& multicastAddress, unsigned short port, VENSendMode sendMode=VENSendNonBuffered, VENReceptionFunctor* recieveFunctor = NULL)
	{
		if (myCom == NULL) myCom = VENCreate();
		return VENAdvanceInit(myCom, multicastAddress.c_str(), port, sendMode, (void*)recieveFunctor, (recieveFunctor!=NULL)?genericCallback:NULL);
	}

	///=================================================================================================
	/// \fn	int release()
	/// \brief	Releases this object. 
	/// \return	. 
	///=================================================================================================
	int release()
		{VENRelease(myCom); myCom=0; return 0;}

	///=================================================================================================
	/// \fn	int flush()
	/// \brief	Flushes the buffer on network. 
	/// Do nothing if non bufferised mode
	/// \return	0 if no problem. 
	///=================================================================================================
	int flush()
		{return VENFlush(myCom);}

	///=================================================================================================
	/// \fn	int VENCommunicationSystem::write(const std::string& srcName, const std::string& messageName,
	/// 	VENType type, const void*data, unsigned int elementNumber)
	/// \brief	Writes. 
	/// \param [in]	srcName		Source Name. 
	/// \param [in]	messageName	Message Name. 
	/// \param	type			Data type. 
	/// \param [in]	data		poiter to data values. 
	/// \param	elementNumber	number of data element in the data pointer. 
	/// \return	0 if no problem. 
	///=================================================================================================
	int write(const std::string& srcName, const std::string& messageName, VENType type, const void* data, unsigned int elementNumber)
		{return VENMessageWrite(myCom, srcName.c_str(), messageName.c_str(), type, data, elementNumber);}

	///=================================================================================================
	/// \fn	int VENCommunicationSystem::write(const std::string& srcName, const std::string& messageName,
	/// 	VENType type, const void*data, unsigned int elementNumber)
	/// \brief	Writes. 
	/// \param [in]	srcName		Source Name. 
	/// \param [in]	messageName	Message Name. 
	/// \param	type			Data type. 
	/// \param [in]	data		poiter to data values. 
	/// \param	elementNumber	number of data element in the data pointer. 
	/// \return	0 if no problem. 
	///=================================================================================================
	int write(const std::string& srcName, const std::string& messageName, const int* data, unsigned int elementNumber)
		{return VENMessageWritei(myCom, srcName.c_str(), messageName.c_str(), data, elementNumber);}
	int write(const std::string&srcName, const std::string&messageName, const char*data, unsigned int elementNumber)
		{return VENMessageWrite(myCom, srcName.c_str(), messageName.c_str(), VENTypeString, data, elementNumber);}
	int write(const std::string&srcName, const std::string&messageName, const double*data, unsigned int elementNumber)
		{return VENMessageWrited(myCom, srcName.c_str(), messageName.c_str(), data, elementNumber);}

	///=================================================================================================
	/// \fn	int read(const std::string&srcName, const std::string&messageName, VENType type, void*data,
	/// 	unsigned int elementNumber)
	/// \brief	Reads this object. 
	/// \param [in]	srcName		Name of the source. 
	/// \param [in]	messageName	Name of the message. 
	/// \param	type				The VENType to read. 
	/// \param [out]	data		data to store the readed values. 
	/// \param	elementNumber		The unsigned int to read. 
	/// \return	number of element read, =!0 in case of error. 
	///=================================================================================================
	int read(const std::string&srcName, const std::string&messageName, VENType type, void* data, unsigned int elementNumber)
		{return VENMessageRead(myCom, srcName.c_str(), messageName.c_str(), type, data, elementNumber);}
	int read(const std::string&srcName, const std::string&messageName, char*data, unsigned int elementNumber)
		{return VENMessageReadc(myCom, srcName.c_str(), messageName.c_str(), data, elementNumber);}
	int read(const std::string&srcName, const std::string&messageName, double*data, unsigned int elementNumber)
		{return VENMessageReadd(myCom, srcName.c_str(), messageName.c_str(), data, elementNumber);}
	int read(const std::string&srcName, const std::string&messageName, int*data, unsigned int elementNumber)
		{return VENMessageReadi(myCom, srcName.c_str(), messageName.c_str(), data, elementNumber);}

	///=================================================================================================
	/// \fn	const std::string& getErrorString()const
	/// \brief	Gets the error string. 
	/// \return	The error string. 
	///=================================================================================================
	std::string getErrorString()const
		{return VENGetErrorString(myCom);}

	///=================================================================================================
	/// \fn	int notImplemented() const
	/// \brief	Helper function for not implemented feature. 
	/// \return	10. 
	///=================================================================================================
	//int notImplemented() const {myLastError="Not Implemented Yet"; return 10;}

	///=================================================================================================
	/// \fn	int available(const std::string&srcName, const std::string&messageName)
	/// \brief	The read state of a VEN message: true if not read since it's last change, false else. 
	/// \param	srcName		Name of the source. 
	/// \param	messageName	Name of the message. 
	/// \return	true if not read since it's last change, false else. 
	///=================================================================================================
	int available(const std::string&srcName, const std::string&messageName)
		{return VENMessageAvailable(myCom, srcName.c_str(), messageName.c_str());}

	static void genericCallback(void* callbackData, const char* messgeKey, VENType type, const void* data, unsigned int elementNumber)
	{
		VENReceptionFunctor* func = static_cast<VENReceptionFunctor*>(callbackData);
		(*func)(messgeKey, type, data, elementNumber);
	}
protected:
	VENCom* myCom;
};
