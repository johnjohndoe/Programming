#pragma once
#if !defined ( WORDNODE_H )
#define WORDNODE_H


#include "NodeList.h"


/**
 * \class	WordNode
 * \brief	Wrapper to store a word and the relationship between its neighbors.
**/
class WordNode
{

public:

	/// \brief Default constructor.
	WordNode( void);
	/// \brief Destructor.
	~WordNode( void);
	/// \brief Stores a single word.
	const char * data;
	/// \brief Stores a list of the associated MP3Data objects.
	NodeList * mp3DataList;
	/// \brief Pointer to the next node.
	WordNode * next;
	/// \brief Pointer to the previous node.
	WordNode * prev;

private:


};

#endif;