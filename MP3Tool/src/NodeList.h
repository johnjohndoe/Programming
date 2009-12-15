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
	/// \brief Adds a node in respect to the lexical order of the title string. Existing nodes are identified by their file paths.
	void insertByFilePath( MP3Data * p_mp3Data);
	/// \brief Adds a node in respect to the lexical order of the title string. Existing nodes are identified by their id.
	void insertById( MP3Data * p_mp3Data);
	/// \brief Returns the MP3Data object or NULL.
	MP3Data * findByFilePath( const char * p_filePath);
	/// \brief Returns the MP3Data object or NULL.
	MP3Data * findById( int p_id);
	/// \brief Removes a node from the list. The node is identified by its file path.
	void removeObjByFilePath( MP3Data * p_mp3Data);
	/// \brief Removes a node from the list. The node is identified by its id.
	bool removeObjById( int p_id);
	/// \brief Returns the root node.
	MP3Data * getFirst();
	/// \brief Sets the Pointer to the first Node
	void begin();
	/// \brief Returns the next node.
	MP3Data * getNext();
	/// \brief Returns the MP3Data object at a certain position.
	MP3Data * at( unsigned int pos);
	/// \brief Checks if there is a next item in the list.
	bool hasNext();
	/// \brief Returns true if the node list is empty.
	bool isEmpty();
	/// \brief All elements of the bypassed node list become integrated into this node list.
	void merge( NodeList * p_nodeList);
	/// \brief Returns the current length.
	unsigned int getLength( void);

	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\nodelist.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:

	/// \brief Base node to build a linked list.
	Node * root;
	/// \brief Current node for the iterator.
	Node * currentNode; 
	/// \brief Length of the linked list.
	unsigned int length;
	/// \brief Unique identifier for a node.
	unsigned int nodeId;

};

#endif;