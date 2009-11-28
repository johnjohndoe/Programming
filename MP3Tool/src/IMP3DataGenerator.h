#pragma once
#if !defined ( IMP3DATAGENERATOR_H )
#define IMP3DATAGENERATOR_H


#include "MP3Data.h"


/**
 * \class	IMP3DataGenerator
 * \brief	Interface to access mp3 library functions.
**/
class IMP3DataGenerator
{

public:

	/// \brief Retrieves the metadata of the file specified.
	virtual MP3Data * readMetadata( const char * pPath) = 0;

};

#endif;
