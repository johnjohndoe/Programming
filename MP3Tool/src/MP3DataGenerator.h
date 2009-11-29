#pragma once
#if !defined ( MP3DATAGENERATOR_H )
#define MP3DATAGENERATOR_H


#include "id3/tag.h"
#include "MP3Data.h"
#include "IMP3DataGenerator.h"
#include <string>
#include <set>


/**
 * \class	MP3DataGenerator
 * \brief	Wrapper to access the id3lib functions. 
**/
class MP3DataGenerator : public IMP3DataGenerator
{

public:

	/// \brief	Default constructor. 
	MP3DataGenerator( void);
	/// \brief	Destructor.
	~MP3DataGenerator( void);
	/// \brief Retrieves the metadata of the file specified.
	MP3Data * readMetadata( const char * pPath);
	/// \brief extract the filename out of a path
	std::string getFilename( const char * text);
private:

	/// \brief Handler for the mp3 file.
	ID3_Tag myID3_Tag;
	/// \brief Stores the text encoding type of the frames read in.
	std::string encoding;
	/// \brief Stores the filename for splitting;
	std::string t_path;	
	/// \brief Returns the text encoding type.
	std::string getEncoding();
	/// \brief Container stores frame ids of the metadata of interest.
	std::set<ID3_FrameID> * interestingID3_FrameIDs;
	/// \brief Removes the round brackets surrounding the text (array index).
	unsigned int removeBrackets( const char * text);



};

#endif;