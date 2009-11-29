#pragma once
#if !defined ( NODELIST_H )
#define NODELIST_H


#include <ostream>	// Only needed for print method.
#include <iostream>	// Only needed for print method.
#include "MP3Data.h"
#include "Node.h"


/**
 * \class	NodeList
 * \brief	List of nodes.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 **/
class NodeList
{

public:

	/// \brief Default constructor.
	NodeList( void);
	/// \brief Destructor.
	~NodeList( void);
	/// \brief Adds a node in respect to the lexical order of the title string.
	void insert( MP3Data * p_data);
	/// \brief Returns the MP3Data object or NULL.
	MP3Data * find( const char * p_title);
	/// \brief Removes a node from the list by identifying it via the title.
	void remove( const char * p_title);
	/// \brief Returns the Root-Node
	MP3Data * getFirst();
	/// returns the next Node
	MP3Data * getNext();
	/// returns the last inserted Item
	MP3Data * getLast();
	// Returns the MP3Data at a certain position
	MP3Data * at(int i);
	/// if there is a next Item in the List
	bool NodeList::hasNext();
	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\nodelist.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:

	/// \brief Base node to build a linked list.
	Node * root;
	/// \brief current Node for the iterator;
	Node * currentNode; 
	// The Last Node in the Linked List
	Node * lastNode;

};

#endif;