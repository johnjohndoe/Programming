#pragma once
#include "MP3Connector.h"
#include <set>

/**
 * \file	src\MP3Connector.h
 *
 * \brief	Class to store the several mp3-files-data.
 * \author	Tobias Preuss / Alexander Kramer
 * \date	20091026_0025
 * \see		http://id3lib.sourceforge.net/api/index.html
 *
**/

class MP3Container
{
	public:

	/**
	 * \fn		MP3Connector( void)
	 * \brief	Default constructor. 
	**/
	MP3Container( void);

	/**
	 * \fn		~MP3Connector( void)
	 * \brief	Destructor. 
	**/
	~MP3Container( void);

	std::set<MP3Connector*>* mySet;

	void MP3Container::add(const char* pathString);
	

};