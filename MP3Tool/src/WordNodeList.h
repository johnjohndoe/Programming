#pragma once
#if !defined ( WORDNODELIST_H )
#define WORDNODELIST_H


#include <ostream>	// Only needed for print method.
#include <iostream>	// Only needed for print method.
#include "WordNode.h"
#include "MP3Data.h"


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
	void insert( const char * p_word, MP3Data * p_mp3Data);
	/// \brief Returns the word or NULL.
	WordNode * find( const char * p_word);
	/// \brief Removes a node from the list.
	void remove( const char * p_word);
	/// \brief Returns the first node.
	MP3Data * getFirst();
	/// \brief Return the following node.
	MP3Data * getNext();
	/// \brief Checks if next node is available.
	bool hasNext();

	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\nodelist.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:

	/// \brief Base node to build a linked list.
	WordNode * root;
	/// \brief current Node for the iterator;
	WordNode * currentNode; 
	// The Last Node in the Linked List
	WordNode * lastNode;

};

#endif;