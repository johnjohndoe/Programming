#pragma once
#if !defined ( NODE_H )
#define NODE_H


#include "MP3Data.h"


/**
 * \class	Node
 * \brief	Wrapper to store relationship between nodes of MP3Data.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
**/
class Node
{

// NodeList can access members.
friend class NodeList;

public:

	/// \brief Default constructor.
	Node( void);
	/// \brief Destructor.
	~Node( void);
	/// \brief Stores the metadata object.
	MP3Data * data;
private:


	/// \brief Pointer to the next node.
	Node * next;
	/// \brief Pointer to the previous node.
	Node * prev;
	friend bool operator== ( const MP3Data & lhs, const MP3Data & rhs);


};

inline bool operator== ( const Node & lhs, const Node & rhs)
{
	if( lhs.data == rhs.data) return true;
	else return false;
}

#endif;