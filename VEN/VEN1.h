#pragma once

#ifdef VEN1_EXPORTS
#define VEN1_API __declspec(dllexport)
#else
#define VEN1_API __declspec(dllimport)
#endif

#ifdef __cplusplus 
extern "C" {
#endif

#define VEN1_MAX_MESSAGE_SIZE 2048

#define VEN1_VERSION_MAJOR 1
#define VEN1_VERSION_MINOR 2

typedef enum
{
	VEN1TypeUnknown = 0,
	VEN1TypeInt,
	VEN1TypeDouble,
	VEN1TypeString,
	VEN1TypeNumber
} VEN1Type;


/*!
 * \brief	return the size of a VENType, 1 for string type, 0 for unknown. 
 * \param	type	The type the size is wanted. 
 */
VEN1_API unsigned int VEN1Size(VEN1Type type);

/*!
 * \brief	return the name of a VENType, NULL for unknown. 
 * \param	type	The type the name is wanted. 
 */
VEN1_API const char* VEN1TypeName(VEN1Type type);

/*!
 * \brief	return Version of the VEN library.
 *			format is : the 16 less significant bits is minor version, the 16 others is major verison
 *			major version = VENVersion() & 0xFFFF000 >> 16
 *			minor version = VENVersion() & 0xFFFF
 */
VEN1_API int VEN1Version();

/*!
 * \brief Call back function type trigger on a message reception.
 * parameters are: 
 * name of the message.
 * type of the data.
 * array of data
 * number  of element in the array.
 * 
 * \see VENAdvanceFileInit|VENAdvanceInit.
 */
typedef void(*VEN1RecieveCallBack)(const char*, VEN1Type, const void*, unsigned int);

/*!
 * \brief Initialize the VEN communication system
 * \return != 0 in case of error
 */
VEN1_API int VEN1Init(const char* multicastAddress, unsigned short port);

/*!
 * \brief Initialize the VEN communication system.
 * Use this initialization if you need to get a message a soon as it is available,
 * or if you need all the possible message without the knowledge of the message.
 * the callback will be call for all the incomming message
 * \return != 0 in case of error
 */
VEN1_API int VEN1AdvanceInit(const char* multicastAddress, unsigned short port, VEN1RecieveCallBack callback);

/*!
 * \brief Initialize the VEN communication system, parameter are read in a confirguration file.
 * \return != 0 in case of error
 */
VEN1_API int VEN1FileInit(const char* file);

/*!
 * \brief Initialize the VEN communication system, parameter are read in a confirguration file.
 * Use this initialization if you need to get a message a soon as it is available,
 * or if you need all the possible message without the knowledge of the message.
 * the callback will be call for all the incomming message
 * \return != 0 in case of error
 */
VEN1_API int VEN1AdvanceFileInit(const char* file, VEN1RecieveCallBack callback);
/*!
 * \brief Release all ressources of VEN communication system.
  * VEN is not usable after this call, But it can be re-inited with #VENInit.
 * \return != 0 in case of error
  * \see VENInit
 */

VEN1_API int VEN1Release();


/*!
  * \brief write a message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrite(const char* srcName, const char* messageName, const VEN1Type type, const void* buffer, const unsigned int elementNumber);

/*!
  * \brief write an integer message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWritei(const char* srcName, const char* messageName, const int* buffer, const unsigned int elementNumber);

/*!
  * \brief write an decimal number message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrited(const char* srcName, const char* messageName, const double* buffer, const unsigned int elementNumber);

/*!
  * \brief write an string message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer NULL termnating string.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWritec(const char* srcName, const char* messageName, const char* buffer);

/*!
  * \brief write a message represent by 1 integer on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrite1i(const char* srcName, const char* messageName, int data);

/*!
  * \brief write a message represent by 2 integers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrite2i(const char* srcName, const char* messageName, int data1, int data2);

/*!
 * \brief write a message represent by 3 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite3i(const char* srcName, const char* messageName, int data1, int data2, int data3);

/*!
 * \brief write a message represent by 4 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite4i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4);

/*!
 * \brief write a message represent by 5 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite5i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5);

/*!
 * \brief write a message represent by 6 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite6i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6);

/*!
 * \brief write a message represent by 7 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite7i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7);

/*!
 * \brief write a message represent by 8 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite8i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8);

/*!
 * \brief write a message represent by 9 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite9i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8, int data9);

/*!
 * \brief write a message represent by 10 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite10i(const char* srcName, const char* messageName, int data1, int data2, int data3, int data4, int data5, int data6, int data7, int data8, int data9, int data10);

/*!
  * \brief write an decimal numbers message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \type type of data to write.
  * \param buffer buffer containing the message data.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrited(const char*srcName, const char*messageName, const double*buffer, const unsigned int elementNumber);

/*!
  * \brief write a message represent by 1 decimal number on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrite1d(const char* srcName, const char* messageName, double data);

/*!
  * \brief write a message represent by 2 decimal numbers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageWrite2d(const char* srcName, const char* messageName, double data1, double data2);

/*!
 * \brief write a message represent by 3 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite3d(const char* srcName, const char* messageName, double data1, double data2, double data3);

/*!
 * \brief write a message represent by 4 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite4d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4);

/*!
 * \brief write a message represent by 5 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite5d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5);

/*!
 * \brief write a message represent by 6 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite6d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6);

/*!
 * \brief write a message represent by 7 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite7d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7);

/*!
 * \brief write a message represent by 8 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite8d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8);

/*!
 * \brief write a message represent by 9 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite9d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8, double data9);

/*!
 * \brief write a message represent by 10 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageWrite10d(const char* srcName, const char* messageName, double data1, double data2, double data3, double data4, double data5, double data6, double data7, double data8, double data9, double data10);

/*!
 * \brief Informative fonction about message availlability on the VEN
 * \param messageName message name, used as message unique identifier
 * \return 1 if a message is available
 * \return 0 if no message is available
 * \return Other value in case of error
 */
VEN1_API int VEN1MessageAvailable(const char* srcName, const char* messageName);

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
VEN1_API int VEN1MessageRead(const char* srcName, const char* messageName, VEN1Type type, void* buffer, const unsigned int elementNumber);

/*!
  * \brief read an integer message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN1_API int VEN1MessageReadi(const char* srcName, const char* messageName, int* buffer, const unsigned int elementNumber);

/*!
  * \brief read an double message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN1_API int VEN1MessageReadd(const char* srcName, const char* messageName, double* buffer, const unsigned int elementNumber);

/*!
  * \brief read an string message on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \param buffer buffer filled with the message data. The number of element returned is troncated at elementNumber
  * \return number of element store in buffer
  * \return <0 in case of error
  */
VEN1_API int VEN1MessageReadc(const char* srcName, const char* messageName, char* buffer, const unsigned int elementNumber);

/*!
  * \brief write a message represent by 1 integer on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageRead1i(const char* srcName, const char* messageName, int* data);

/*!
  * \brief write a message represent by 2 integers on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageRead2i(const char* srcName, const char* messageName, int* data1, int* data2);

/*!
 * \brief read a message represent by 3 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead3i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3);

/*!
 * \brief read a message represent by 4 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead4i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4);

/*!
 * \brief read a message represent by 5 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead5i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5);

/*!
 * \brief read a message represent by 6 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead6i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6);

/*!
 * \brief read a message represent by 7 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead7i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7);

/*!
 * \brief read a message represent by 8 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead8i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8);

/*!
 * \brief read a message represent by 9 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead9i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8, int* data9);

/*!
 * \brief read a message represent by 10 integers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead10i(const char* srcName, const char* messageName, int* data1, int* data2, int* data3, int* data4, int* data5, int* data6, int* data7, int* data8, int* data9, int* data10);

/*!
  * \brief write a message represent by 1 decimal value on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageRead1d(const char* srcName, const char* messageName, double* data);

/*!
  * \brief write a message represent by 2 decimal values on the VEN.
  * \param messageName message name, used as message unique identifier.
  * \return != 0 in case of error.
  */
VEN1_API int VEN1MessageRead2d(const char* srcName, const char* messageName, double* data1, double* data2);

/*!
 * \brief read a message represent by 3 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead3d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3);

/*!
 * \brief read a message represent by 4 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead4d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4);

/*!
 * \brief read a message represent by 5 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead5d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5);

/*!
 * \brief read a message represent by 6 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead6d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6);

/*!
 * \brief read a message represent by 7 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead7d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7);

/*!
 * \brief read a message represent by 8 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead8d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8);

/*!
 * \brief read a message represent by 9 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead9d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8, double* data9);

/*!
 * \brief read a message represent by 10 decimal numbers on the VEN.
 * \param messageName message name, used as message unique identifier.
 * \return != 0 in case of error.
 */
VEN1_API int VEN1MessageRead10d(const char* srcName, const char* messageName, double* data1, double* data2, double* data3, double* data4, double* data5, double* data6, double* data7, double* data8, double* data9, double* data10);


#ifdef __cplusplus 
}
#endif
