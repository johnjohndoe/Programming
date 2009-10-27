#pragma once
#if !defined ( ID3_FRAMEID_LUT_H )
#define ID3_FRAMEID_LUT_H

#include <map>
#include "id3/tag.h"

/**
 * \class	ID3_FrameID_LUT
 *
 * \brief	Stores the real names associated with the ID3_FrameIDs
 * \author	Tobias Preuss
 * \date	20091027
**/
class ID3_FrameID_LUT
{

public:

	/// \brief	Default constructor. 
	ID3_FrameID_LUT( void);

	/// \brief	Destructor. 
	~ID3_FrameID_LUT( void);

	/**
	 * \fn		const char * getRealname( ID3_FrameID)
	 * \brief	Returns the realname of a frame id. 
	 * \param	The key which is a enum respresenting the frame id. 
	 * \return	The realname or null. 
	**/
	const char * getRealname( ID3_FrameID);

private:

	/// \brief	Container stores frame id as key and its real name as value
	std::map<ID3_FrameID, std::string> * frameIdRealnames; 

};

#endif;