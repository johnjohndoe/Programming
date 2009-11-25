#pragma once
#if !defined ( MP3DATAGENERATOR_H )
#define MP3DATAGENERATOR_H


#include "id3/tag.h"
#include "MP3Data.h"
#include <string>
#include <set>


class MP3DataGenerator
{

public:

	/// \brief	Default constructor. 
	MP3DataGenerator( void);
	/// \brief	Destructor.
	~MP3DataGenerator( void);

	MP3Data * readMetadata( const char * pPath);

private:

	/// \brief Handler for the mp3 file.
	ID3_Tag myID3_Tag;
	/// \brief Stores the text encoding type of the frames read in.
	std::string encoding;
	/**
	 * \fn		std::string getEncoding( void)
	 * \brief	Returns the text encoding type. 
	 * \return	A string. 
	**/
	std::string getEncoding();
	/// \brief Container stores frame ids of the metadata of interest.
	std::set<ID3_FrameID> * interestingID3_FrameIDs;
	/// \brief Removes the round brackets surrounding the text (array index).
	unsigned int removeBrackets( const char * text);
};

#endif;