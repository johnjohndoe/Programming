#pragma once
#if !defined ( WORDDATA_H )
#define WORDDATA_H


#include "MP3Data.h"
#include "NodeList.h"


/**
 * \class	WordData
 * \brief	Wrapper to store the word itself and the associated MP3Data objects. 
**/
class WordData
{

// WordNode can access members.
friend class WordNode;
friend class WordNodeList;

public:

	/// \brief Constructor
	WordData( const char * p_word, MP3Data * p_associate);
	/// \brief Destructor.
	~WordData( void);

private:

	/// \brief Default constructor.
	WordData( void);

	/// \brief Stores a single word.
	const char * word;
	/// \brief Stores a list of the associated MP3Data objects.
	NodeList * associates;

};

#endif;