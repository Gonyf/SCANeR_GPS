#ifndef _VEN_H_
#define _VEN_H_

#ifdef __linux__
#define VEN_API
#else
#ifdef VEN_EXPORTS
#define VEN_API __declspec(dllexport)
#else
#define VEN_API __declspec(dllimport)
#endif
#endif

#ifdef __cplusplus 
extern "C" {
#endif

#define VEN_MAX_MESSAGE_SIZE 2800

#define VEN_VERSION_MAJOR 2
#define VEN_VERSION_MINOR 0

struct _VENCom;
typedef struct VENCom VENCom;

typedef enum
{
	VENTypeUnknown = 0,
	VENTypeInt,
	VENTypeDouble,
	VENTypeString,
	VENTypeNumber
} VENType;

typedef enum
{
	VENSendNonBuffered=0,
	VENSendBuffered
} VENSendMode;

/*!
 * \brief	return the size of a VENType, 1 for string type, 0 for unknown. 
 * \param	type	The type the size is wanted. 
 */
VEN_API unsigned int VENSize(VENType type);

/*!
 * \brief	return the name of a VENType, NULL for unknown. 
 * \param	type	The type the name is wanted. 
 */
VEN_API const char* VENTypeName(VENType type);

/*!
 * \brief	return Version of the VEN library.
 *			format is : the 16 less significant bits is minor version, the 16 others is major verison
 *			major version = VENVersion() & 0xFFFF000 >> 16
 *			minor version = VENVersion() & 0xFFFF
 */
VEN_API int VENVersion();

/*!
 * \brief Call back function type trigger on a message reception.
 * parameters are: 
 * callbackData, the pointer passed to VENAdvanceInit
 * name of the message.
 * type of the data.
 * array of data
 * number  of element in the array.
 * 
 * \see VENAdvanceFileInit|VENAdvanceInit.
 */
typedef void(*VENRecieveCallBack)(void* , const char* , VENType , const void* , unsigned int );

/*!
 * \brief create the VEN communication objectthe created VEN communication object
 */
VEN_API VENCom* VENCreate();

/*!
 * \brief returns the current error string, if any, of the VEN communication
 */
VEN_API const char* VENGetErrorString(VENCom* com);
/*!
 * \brief Initialize the VEN communication system
 * \return != 0 in case of error
 */
VEN_API int VENInit(VENCom* com, const char* multicastAddress, unsigned short port, VENSendMode buffered);

/*!
 * \brief Initialize the VEN communication system.
 * Use this initialization if you need to get a message a soon as it is available,
 * or if you need all the possible message without the knowledge of the message.
 * the callback will be called for all the incomming message
 * the callbackData will be passed to the callback function each time it is called
 * \return != 0 in case of error
 */
VEN_API int VENAdvanceInit(VENCom* com, const char* multicastAddress, unsigned short port, VENSendMode sendMode, void* callbackData, VENRecieveCallBack callback);

/*!
 * \brief Release all ressources of VEN communication system.
  * VEN is not usable after this call, But it can be re-inited with #VENInit.
 * \return != 0 in case of error
  * \see VENInit
 */
VEN_API int VENRelease(VENCom* com);

/*!
 * \brief Flush of VEN communication system.
 * Send the buffer on network and reinit it
 * Do nothing in non bufferised mode.
 * \return != 0 in case of error
 */
VEN_API int VENFlush(VENCom* com);

/*!
  * \brief write a message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrite(VENCom* com, const char* srcName, const char* messageName, const VENType type, const void* buffer, const unsigned int elementNumber);

/*!
  * \brief write an integer message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWritei(VENCom* com, const char* srcName, const char* messageName, const int* buffer, const unsigned int elementNumber);

/*!
  * \brief write an decimal number message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrited(VENCom* com, const char* srcName, const char* messageName, const double* buffer, const unsigned int elementNumber);

/*!
  * \brief write an string message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer NULL termnating string.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWritec(VENCom* com, const char* srcName, const char* messageName, const char* buffer);

/*!
  * \brief write a message represent by 1 integer on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrite1i(VENCom* com, const char* srcName, const char* messageName, int data);

/*!
  * \brief write a message represent by 2 integers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrite2i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2);

/*!
 * \brief write a message represent by 3 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite3i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3);

/*!
 * \brief write a message represent by 4 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite4i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4);

/*!
 * \brief write a message represent by 5 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite5i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5);

/*!
 * \brief write a message represent by 6 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite6i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6);

/*!
 * \brief write a message represent by 7 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite7i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7);

/*!
 * \brief write a message represent by 8 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite8i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8);

/*!
 * \brief write a message represent by 9 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite9i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8, int data9);

/*!
 * \brief write a message represent by 10 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite10i(VENCom* com, const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8, int data9, int data10);

/*!
  * \brief write an decimal numbers message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrited(VENCom* com, const char*srcName, const char*messageName, const double*buffer, const unsigned int elementNumber);

/*!
  * \brief write a message represent by 1 decimal number on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrite1d(VENCom* com, const char* srcName, const char* messageName, double data);

/*!
  * \brief write a message represent by 2 decimal numbers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageWrite2d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2);

/*!
 * \brief write a message represent by 3 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite3d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3);

/*!
 * \brief write a message represent by 4 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite4d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4);

/*!
 * \brief write a message represent by 5 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite5d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5);

/*!
 * \brief write a message represent by 6 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite6d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6);

/*!
 * \brief write a message represent by 7 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite7d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7);

/*!
 * \brief write a message represent by 8 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite8d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8);

/*!
 * \brief write a message represent by 9 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite9d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8, double data9);

/*!
 * \brief write a message represent by 10 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageWrite10d(VENCom* com, const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8, double data9, double data10);

/*!
 * \brief Informative fonction about message availlability on the VEN
 * \param messageName message name, used as message unique identifier
 * \return 1 if a message is available
 * \return 0 if no message is available
 * \return Other value in case of error
 */
VEN_API int VENMessageAvailable(VENCom* com, const char* srcName, const char* messageName);

/*!
  * \brief read a message on the VEN.
  * The buffer you give to this fonction doesn't have to be a void*. 
  * If you have to read a message of, at maximum, 5 double you can do it this way:
  * double buffer[5];
  * VENMessageRead("toto", "titi", VENTypeDouble, buffer, 5);
  * \param messageName message name, used as message unique identifier
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN_API int VENMessageRead(VENCom* com, const char* srcName, const char* messageName, VENType type, void* buffer, const unsigned int elementNumber);

/*!
  * \brief read an integer message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN_API int VENMessageReadi(VENCom* com, const char* srcName, const char* messageName, int* buffer, const unsigned int elementNumber);

/*!
  * \brief read an double message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN_API int VENMessageReadd(VENCom* com, const char* srcName, const char* messageName, double* buffer, const unsigned int elementNumber);

/*!
  * \brief read an string message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN_API int VENMessageReadc(VENCom* com, const char* srcName, const char* messageName, char* buffer, const unsigned int elementNumber);

/*!
  * \brief write a message represent by 1 integer on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageRead1i(VENCom* com, const char* srcName, const char* messageName, int* data);

/*!
  * \brief write a message represent by 2 integers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageRead2i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2);

/*!
 * \brief read a message represent by 3 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead3i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3);

/*!
 * \brief read a message represent by 4 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead4i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4);

/*!
 * \brief read a message represent by 5 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead5i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5);

/*!
 * \brief read a message represent by 6 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead6i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6);

/*!
 * \brief read a message represent by 7 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead7i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7);

/*!
 * \brief read a message represent by 8 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead8i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8);

/*!
 * \brief read a message represent by 9 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead9i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8, int* data9);

/*!
 * \brief read a message represent by 10 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead10i(VENCom* com, const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8, int* data9, int* data10);

/*!
  * \brief write a message represent by 1 decimal value on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageRead1d(VENCom* com, const char* srcName, const char* messageName, double* data);

/*!
  * \brief write a message represent by 2 decimal values on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN_API int VENMessageRead2d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2);

/*!
 * \brief read a message represent by 3 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead3d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3);

/*!
 * \brief read a message represent by 4 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead4d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4);

/*!
 * \brief read a message represent by 5 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead5d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5);

/*!
 * \brief read a message represent by 6 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead6d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6);

/*!
 * \brief read a message represent by 7 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead7d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7);

/*!
 * \brief read a message represent by 8 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead8d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8);

/*!
 * \brief read a message represent by 9 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead9d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8, double* data9);

/*!
 * \brief read a message represent by 10 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN_API int VENMessageRead10d(VENCom* com, const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8, double* data9, double* data10);


#ifdef __cplusplus 
}
#endif

#endif
