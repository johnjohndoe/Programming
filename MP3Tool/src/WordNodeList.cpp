#include "StdAfx.h"
#include "WordNodeList.h"
#include "Helper.h"


WordNodeList::WordNodeList( void)
{
	root = new WordNode();
	root->next = root;
	root->prev = root;
	root->data = NULL;
	lastNode =  root;
	currentNode = root;
}

WordNodeList::~WordNodeList( void)
{
	delete root;
}
void WordNodeList::insert( const char * p_word, MP3Data * p_mp3data)
{
	WordNode * node = root->next;
	while( node != root && Helper::compareCaseSensitive( node->data, p_word) == Helper::SMALLER)
		node = node->next;
	WordNode * newNode = new WordNode();
	newNode->data = p_word;
	newNode->mp3Data = p_mp3data;
	lastNode = newNode;
	node->prev->next = newNode;
	newNode->prev = node->prev;
	newNode->next = node;
	node->prev = newNode;
}
MP3Data * WordNodeList::find( const char * p_word)
{
	WordNode * node = root->next;
	while( node != root && !(Helper::compareCaseSensitive( node->data, p_word) == Helper::EQUAL))
		node = node->next;	// Set to next node. Last would be back to root.
	// Not found.
	if( node == root)
		return NULL;
	// Return the object found.
	return node->mp3Data;
}
void WordNodeList::remove( const char * p_word)
{
	WordNode * node = root->next;
	while( node != root && !(Helper::compareCaseSensitive( node->data, p_word) == Helper::EQUAL))
		node = node->next;
	// Not found.
	if( node == root)
		return;
	// Relink neighbors and remove the object found.
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}

void WordNodeList::print( std::ostream & os)
{
	unsigned int count = 1;
	WordNode * node = root->next;
	while( node->data != NULL)
	{
		os << count << ": " << node->data << "\n";
		node = node->next;
		count++;
	}
	os << std::endl;
}

MP3Data * WordNodeList::getFirst()
{
	currentNode = root->next;
	return currentNode->mp3Data;
}

MP3Data * WordNodeList::getNext()
{
	if(currentNode->next->next != NULL)
	{
		currentNode = currentNode->next;
		return currentNode->mp3Data;
	}
	else
	{
		return NULL;
	}
}

bool WordNodeList::hasNext()
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