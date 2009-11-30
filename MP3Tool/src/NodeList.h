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
	void insert( MP3Data * p_mp3Data);
	/// \brief Returns the MP3Data object or NULL.
	MP3Data * findByFilePath( const char * p_filePath);
	/// \brief Removes a node from the list by it's index.
	void removeObj( MP3Data * p_mp3Data);
	/// \brief Returns the root node.
	MP3Data * getFirst();
	/// \brief Returns the next node.
	MP3Data * getNext();
	/// \brief Returns the MP3Data object at a certain position.
	MP3Data * at( unsigned int pos);
	/// \brief Checks if there is a next item in the list.
	bool hasNext();
	/// \returns True if the NodeList is empty
	bool isEmpty();
	/// \brief All elements of the bypassed node list become integrated into this node list.
	void merge( NodeList * p_nodeList);

	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\nodelist.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:

	/// \brief Base node to build a linked list.
	Node * root;
	/// \brief Current node for the iterator.
	Node * currentNode; 
	/// \brief Length of the LinkedList
	unsigned int length;

};

#endif;