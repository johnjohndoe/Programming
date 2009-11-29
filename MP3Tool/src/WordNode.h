#pragma once
#if !defined ( WORDNODE_H )
#define WORDNODE_H

#include "MP3Data.h"

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
	MP3Data * mp3Data;
	/// \brief Pointer to the next node.
	WordNode * next;
	/// \brief Pointer to the previous node.
	WordNode * prev;

private:


};

#endif;