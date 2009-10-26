#pragma once
#if !defined ( ID3_FRAMEID_LUT_H )
#define ID3_FRAMEID_LUT_H

#include <map>
#include "id3/tag.h"

/**
 * \class	ID3_FrameID_LUT
 *
 * \brief	Stores the realnames associated with the ID3_FrameIDs
 * \author	Tobias Preuss
 * \date	20091026_2130
**/
class ID3_FrameID_LUT
{

public:
	ID3_FrameID_LUT(void);

	const char * getRealname( ID3_FrameID);

private:
	std::map<ID3_FrameID, std::string> * frameIdRealnames;

};

#endif;