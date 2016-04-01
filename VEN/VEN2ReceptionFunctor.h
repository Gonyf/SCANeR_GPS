#pragma once
#include "VEN/VEN2.h"

///=================================================================================================
/// \brief	Object functor called on each received message.
/// \see #operator()
///=================================================================================================
class VENReceptionFunctor
{
public:

	///=================================================================================================
	/// \brief	function called on each received message. 
	/// \param 	messgeKey		The message key, compose by Reciver_name/Message_name. 
	/// \param	type			The data type of the message. 
	/// \param  data			The data. 
	/// \param	elementNumber	The number of element. 
	///=================================================================================================
	virtual void operator()(const char* messgeKey, VENType type, const void* data, unsigned int elementNumber) = 0;
};
