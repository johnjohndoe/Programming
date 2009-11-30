#pragma once
#if !defined ( WORDNODELIST_H )
#define WORDNODELIST_H


#include <ostream>	// Only needed for print method.
#include <iostream>	// Only needed for print method.
#include "MP3Data.h"
#include "WordNode.h"


/**
 * \class	WordNodeList
 * \brief	List of nodes.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 **/
class WordNodeList
{

public:

	/// \brief Default constructor.
	WordNodeList( void);
	/// \brief Destructor.
	~WordNodeList( void);
	/// \brief Adds a node in respect to the lexical order of the string.
	void insert( const char * p_word, MP3Data * p_associate);
	/// \brief Return the list of associated MP3Data objects or NULL.
	NodeList * find( const char * p_word);
	/// \brief Removes a node from the list.
	void remove( const char * p_word);
	/// \brief Checks if next node is available.
	bool hasNext();
	/// \brief search-method for finding a substring in the Titel-Words; uses the Devide 
	NodeList * searchForSubstring(const char * p_word);

	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\nodelist.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:

	/// \brief Base node to build a linked list.
	WordNode * root;
	/// \brief The current node for the iterator.
	WordNode * currentNode;
	// @TODO Remove later if unused
	/// \brief The last node in the linked list.
	WordNode * lastNode;
	/// \brief length of the LinkedList (containing Words)
	unsigned int length;
	/// \brief Search-Result with a unique List of found MP3Datas
	NodeList * searchResult;

	/// \brief Returns a word node if it already exists.
	WordNode * contains( const char * p_word);
};

#endif;