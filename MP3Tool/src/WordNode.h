#pragma once
#if !defined ( WORDNODE_H )
#define WORDNODE_H


#include "MP3Data.h"
#include "WordData.h"


/**
 * \class	WordNode
 * \brief	Wrapper to store a word and the relationship between its neighbors.
**/
class WordNode
{

// WordNodeList can access members.
friend class WordNodeList;

public:

	/// \brief Default constructor.
	WordNode( void);
	/// \brief Constructor
	WordNode( const char * p_word, MP3Data * p_associate);
	/// \brief Destructor.
	~WordNode( void);

private:

	/// \brief Stores a single word and a list of the associated MP3Data objects.
	WordData * wordData;
	/// \brief Pointer to the next node.
	WordNode * next;
	/// \brief Pointer to the previous node.
	WordNode * prev;

};

#endif;