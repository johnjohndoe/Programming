#pragma once
#if !defined ( MP3CONNECTOR_H )
#define MP3CONNECTOR_H


#include "id3/tag.h"
#include <string>
#include <set>
#include <map>

/**
 * \file	src\MP3Connector.h
 *
 * \brief	Class to access the MP3 file.
 * \author	Tobias Preuss
 * \date	20091026_2119
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

	void init( void);

	/**
	 * \fn						bool getFile( const char * pPath)
	 * \brief					Gets a file. 
	 * \param [in,out]	pPath	Full pathname of the file. 
	 * \return					true if it succeeds, false if it fails. 
	**/
	bool getFile( const char * pPath);

	/**
	 * \fn	std::map<ID3_FrameID, std::string> * getMetadata( void)
	 * \brief	Gets the metadata. 
	 * \return	Returns the metadata or null.
	**/
	std::map<ID3_FrameID, std::string> * getMetadata( void);

private:

	// \brief Handler for the mp3 file
	ID3_Tag myTag;
	// \brief Container stores frame ids of the metadata of interest
	std::set<ID3_FrameID> * interestingID3_FrameIDs;
	// \brief Container stores frame id as key and its value
	std::map<ID3_FrameID, std::string> * metadata;
};

#endif;