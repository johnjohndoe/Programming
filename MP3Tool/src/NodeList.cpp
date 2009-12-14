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
	Node * node = root;
	while( node != NULL)
	{
		Node * tmpNode = NULL;
		if( node != root)
		{
			MP3Data * data = node->data;
			delete data;	
			tmpNode = node->next;
		}
		delete node;
		node = tmpNode;
	}
}
MP3Data * NodeList::getFirst()
{
	currentNode = root->next;
	return currentNode->data;
}
MP3Data * NodeList::getNext()
{
	if( currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		return currentNode->data;
	}
	else
	{
		return NULL;
	}
}
MP3Data * NodeList::at( unsigned int pos)
{
	currentNode = root;
	for ( unsigned int j = 0; j <= pos ; j++)
	{
		currentNode = currentNode->next;
	}
	return currentNode->data;
}
bool NodeList::hasNext()
{
	if( currentNode->next->data == NULL)
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
	return ( length == 0) ? true : false;
}
int NodeList::insert( MP3Data * p_mp3Data)
{
	// Skip insert if node already exists.
	MP3Data * found = findByFilePath( p_mp3Data->getFilepath());
	if( found) return;

	Node * node = root->next;
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != NULL && node != root && *node->data < *p_mp3Data)
		node = node->next;
	Node * newNode = new Node();
	newNode->data = new MP3Data( * p_mp3Data);

	if( node == NULL) return;
	node->prev->next = newNode;
	newNode->prev = node->prev;
	newNode->next = node;
	node->prev = newNode;
	length++;
}
MP3Data * NodeList::findByFilePath( const char * p_filePath)
{
	Node * node = root->next;
	// Wrap title in a temporary object to compare it.
	MP3Data * interest = new MP3Data();
	interest->setFilepath( p_filePath);
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != NULL && node != root && *node->data != *interest)
		node = node->next;	// Set to next node. Last would be back to root.
	// Not found.
	if( node == NULL || node == root)
		return NULL;
	// Return the object found.
	return node->data;
}
void NodeList::removeObj( MP3Data * p_mp3Data)
{
	Node * node = root->next;
	// !Important: Dereference the pointer before using the comparison operator.
	while( node != NULL && node != root && *node->data != *p_mp3Data)
		node = node->next;
	// Not found.
	if( node == NULL || node == root)
		return;
	// Relink neighbors and remove the object found.
	node->prev->next = node->next;
	node->next->prev = node->prev;
	length--;
	delete node->data;
	delete node;
}
void NodeList::merge( NodeList * p_nodeList)
{
	if( p_nodeList->length <= 0) return;
	this->insert( p_nodeList->getFirst());
	while( p_nodeList->hasNext())
		this->insert( p_nodeList->getNext());
}
unsigned int NodeList::getLength( void)
{
	return length;
}
void NodeList::print( std::ostream & os)
{
	if( this->root->data == NULL) return;
	unsigned int count = 1;
	Node * node = root->next;
	while( node->data)
	{
		os << count << ": " << node->data->getTitle() << " | " << node->data->getFilepath() << "\n";
		node = node->next;
		count++;
	}
	os << std::endl;
}
