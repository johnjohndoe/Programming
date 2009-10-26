#pragma once

#include "id3/tag.h"
#include <string>

/**
 * \file	src\MP3Connector.h
 *
 * \brief	Class to access the MP3 file.
 * \author	Tobias Preuss
 * \date	20091026_0025
 * \see		http://id3lib.sourceforge.net/api/index.html
 *
**/
class MP3Connector
{
public:

	/**
	 * \fn		MP3Connector( void)
	 * \brief	Default constructor. 
	**/
	MP3Connector( void);

	/**
	 * \fn		~MP3Connector( void)
	 * \brief	Destructor. 
	**/
	~MP3Connector( void);

	const char * getTitle( void) const;
	const char * getAuthor( void) const;
	const char * getAlbum( void) const;
	const char * getGenre( void) const;
	int getYear( void) const;
	int getTrack( void) const;

	/**
	 * \fn						bool getFile( const char * pPath)
	 * \brief					Gets a file. 
	 * \param [in,out]	pPath	Full pathname of the file. 
	 * \return					true if it succeeds, false if it fails. 
	**/
	bool getFile( const char * pPath);
	
	void retrieveTitle( void);
	void retrieveMetadata( void);

private:
	const char * mTitle;
	std::string mAuthor;
	std::string mAlbum;
	std::string mGenre;
	int mYear;
	int mTrack;

	ID3_Tag myTag;
};
