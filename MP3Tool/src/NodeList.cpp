#include "StdAfx.h"
#include "NodeList.h"


NodeList::NodeList( void)
{
	root = new Node();
	root->next = root;
	root->prev = root;
	root->data = NULL;
	currentNode = root;
	length = 0;

}

NodeList::~NodeList( void)
{
	delete currentNode;
	delete root;
}

MP3Data* NodeList::getFirst()
{
	currentNode = root->next;
	return currentNode->data;
}

MP3Data* NodeList::getNext()
{
	if(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		return currentNode->data;
	}
	else
	{
		return NULL;
	}
}

MP3Data * NodeList::at( unsigned int i)
{
	currentNode = root;
	for ( unsigned int j = 0; j <= i ; j++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

bool NodeList::hasNext()
{
	if(currentNode->next->data == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool NodeList::isEmpty()
{
	if (length == 0)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void NodeList::insert( MP3Data * p_data)
{
	// Skip insert if node already exists.
	MP3Data * found = find( p_data->getTitle());
	if( found) return;

	Node * node = root->next;
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != root && *node->data < *p_data)
		node = node->next;
	Node * newNode = new Node();
	newNode->data = new MP3Data( * p_data);
	node->prev->next = newNode;
	newNode->prev = node->prev;
	newNode->next = node;
	node->prev = newNode;
	length++;
}
MP3Data * NodeList::find( const char * p_title)
{
	Node * node = root->next;
	// Wrap title in a temporary object to compare it.
	MP3Data * interest = new MP3Data();
	interest->setTitle( p_title);
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != root && *node->data != *interest)
		node = node->next;	// Set to next node. Last would be back to root.
	// Not found.
	if( node == root)
		return NULL;
	// Return the object found.
	return node->data;
}
void NodeList::remove( const char * p_title)
{
	Node * node = root->next;
	// Wrap title in a temporary object to compare it.
	MP3Data * odd = new MP3Data();
	odd->setTitle( p_title);
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != root && *node->data != *odd)
		node = node->next;
	// Not found.
	if( node == root)
		return;
	// Relink neighbors and remove the object found.
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node->data;
	delete node;
}
void NodeList::print( std::ostream & os)
{
	unsigned int count = 1;
	Node * node = root->next;
	while( node->data != NULL)
	{
		os << count << ": " << node->data->getTitle() << "\n";
		node = node->next;
		count++;
	}
	os << std::endl;
}
