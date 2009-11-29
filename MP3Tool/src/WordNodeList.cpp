#include "StdAfx.h"
#include "WordNodeList.h"
#include "Helper.h"


WordNodeList::WordNodeList( void)
{
	root = new WordNode();
	root->wordData = NULL;
	root->next = root;
	root->prev = root;
	lastNode =  root;
	currentNode = root;
}
WordNodeList::~WordNodeList( void)
{
	delete currentNode;
	delete lastNode;
	delete root;
}
void WordNodeList::insert( const char * p_word, MP3Data * p_associate)
{
	WordNode * found = contains( p_word);
	if( found)
	{
		// Extend the list of associates of the existing word node.
		found->wordData->associates->insert( p_associate);
	}
	else
	{
		// Otherwise insert new word node.
		WordNode * node = root->next;
		while( node != root && Helper::compareCaseSensitive( node->wordData->word, p_word) == Helper::SMALLER)
			node = node->next;
		WordNode * newNode = new WordNode( p_word, p_associate);
		newNode->mp3DataList->insert(p_mp3data);
		newNode->data = p_word;
		lastNode = newNode;
		node->prev->next = newNode;
		newNode->prev = node->prev;
		newNode->next = node;
		node->prev = newNode;
	}
}
WordNode * WordNodeList::contains( const char * p_word)
{
	WordNode * node = root->next;
	while( node != root && !( Helper::compareCaseSensitive( node->wordData->word, p_word) == Helper::EQUAL))
		node = node->next;	// Set to next node. Last would point back to root.
	// Not found.
	if( node == root)
		return NULL;
	// Return the word node.
	return node;
}
NodeList * WordNodeList::find( const char * p_word)
{
	WordNode * node = root->next;
	while( node != root && !( Helper::compareCaseSensitive( node->wordData->word, p_word) == Helper::EQUAL))
		node = node->next;	// Set to next node. Last would point back to root.
	// Not found.
	if( node == root)
		return NULL;
	// Return the list of associated MP3Data objects.
	return node->wordData->associates;
}
void WordNodeList::remove( const char * p_word)
{
	WordNode * node = root->next;
	while( node != root && !( Helper::compareCaseSensitive( node->wordData->word, p_word) == Helper::EQUAL))
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
	while( node->wordData)
	{
		os << count << ": " << node->wordData->word << "\n";
		node = node->next;
		count++;
	}
	os << std::endl;
}
<<<<<<< HEAD

NodeList * WordNodeList::getFirst()
{
 	currentNode = root->next;
	return currentNode->mp3DataList;
}

NodeList * WordNodeList::getNext()
{
	if(currentNode->next->next != NULL)
	{
		currentNode = currentNode->next;
		return currentNode->mp3DataList;
	}
	else
	{
		return NULL;
	}
}

=======
>>>>>>> df0899dc614964cace391f355741afa74f70bf29
bool WordNodeList::hasNext()
{
	return ( !currentNode->next->wordData->word) ? true : false;
}