#pragma once
#if !defined ( MP3CONTROLLER_H )
#define MP3CONTROLLER_H

#include <string>
#include "NodeList.h"
#include "WordNodeList.h"
#include "MP3DataGenerator.h"


class MP3Controller
{

// Form1 can access members.
//friend class Form1;

public:

	/// \brief	Default constructor.
	MP3Controller( void);
	/// \brief	Destructor.
	~MP3Controller( void);

	/// \brief Adds a MP3Data object to the track list.
	void addMP3( const char * p_filePath);
	/// \brief Returns the last search result.
	NodeList * getSearchResult( const char * searchString = NULL); 
	/// \brief Returns the track list.
	NodeList * getTrackList( void);
	/// \brief Builds an index of all words contained in the title field of all track list elements.
	void createIndex();
	/// \brief Removes all elements from the track list and the index.
	void clearLists();
	/// \brief Removes all indexed words.
	void resetIndexList( void);
	/// \brief Removes all elements from the track list.
	void resetTracklist( void);
	/// \brief Removes all elements from the search result.
	void resetSearchResult( void);
	/// \brief Print method offers to print to output stream, f.e. a file.
	void print( void);

private:

	/// \brief Local representation of the MP3DataGenerator.
	MP3DataGenerator * myGenerator;
	/// \brief Stores a temporary subset of the track list.
	NodeList * searchResult;
	/// \brief Stores all MP3Data objects.
	NodeList * trackList;
	/// \brief Stores the index of all title words.
	WordNodeList * indexList;

};
#endif;