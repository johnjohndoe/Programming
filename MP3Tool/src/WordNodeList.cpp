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
	length = 0;
}
WordNodeList::~WordNodeList( void)
{
	WordNode * node = root;
	while( node != NULL)
	{
		WordNode * tmpNode = NULL;
		if( node != root)
			tmpNode = node->next;
		delete node;
		node = tmpNode;
	}
}
void WordNodeList::insert( const char * p_word, MP3Data * p_associate)
{
	std::string * t_word = new std::string(p_word);
	Helper::toLowerCase( *t_word);
	
	WordNode * found = contains( t_word->c_str());
	if( found)
	{
		// Extend the list of associates of the existing word node.
		found->wordData->associates->insert( p_associate);
	}
	else
	{
		// Otherwise insert new word node.
		WordNode * node = root->next;
		while( node != root && Helper::compareCaseSensitive( node->wordData->word, t_word->c_str()) == Helper::SMALLER)
			node = node->next;
		WordNode * newNode = new WordNode( t_word->c_str(), p_associate);
		lastNode = newNode;
		node->prev->next = newNode;
		newNode->prev = node->prev;
		newNode->next = node;
		node->prev = newNode;
		length++;
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
	if( !p_word) return NULL;
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
	if( this->root->wordData == NULL) return;
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
void  WordNodeList::printExtensive( std::ostream & os)
{
	currentNode = root->next; // Set to 1
	while( currentNode->wordData)
	{
		os << "Node name: " << currentNode->wordData->word << "\n";
		currentNode->wordData->associates->print(os);
		currentNode = currentNode->next;
	}

}
bool WordNodeList::hasNext()
{
	return ( !currentNode->next->wordData->word) ? true : false;
}
void WordNodeList::searchForSubstring(  NodeList * p_searchResult, const char * p_word)
{
	std::string * inputString = new std::string( p_word);
	currentNode = root;
	size_t foundAtPosition = -1;

	if ( length <= 0)
	{
		return;
	} 
	else
	{
		// Iterative search using the word index.
		if( true)
		{
			while( currentNode->next->wordData != NULL)
			{
				std::string * aktSearchString = new std::string( currentNode->next->wordData->word);
				foundAtPosition = aktSearchString->find( inputString->c_str());
				if( foundAtPosition == 0) 
				{
					p_searchResult->merge( currentNode->next->wordData->associates);
					foundAtPosition = -1;
				}
				currentNode = currentNode->next;
			}
		}
		// Binary search - not fully functional beta-version and therefore skipped by "if( true)"
		else
		{
			int UpperBound = length;
			int LowerBound = -1;
			int diff = (int)( ( UpperBound - LowerBound) / 2);
			bool up = true;
			while( diff != 0)
			{
				for ( int g = 0; g < diff; g++)
				{
					if( up) currentNode = currentNode->next; 
					else currentNode = currentNode->prev;
				}
				if( currentNode->wordData == NULL) break;
				std::string * wordInCurrentNode = new std::string( currentNode->wordData->word);
				foundAtPosition = wordInCurrentNode->find( inputString->c_str()); 

				if( foundAtPosition == 0) //Found the search-string at position 0 in the current node-word
				{
					p_searchResult = currentNode->wordData->associates;
					WordNode * runner = currentNode->next;
					while( runner->wordData != NULL)
					{
						wordInCurrentNode = new std::string( runner->wordData->word);
						int foundAtNextPosition = wordInCurrentNode->find( inputString->c_str());
						if( foundAtNextPosition == 0)
						{
							p_searchResult->merge( runner->wordData->associates);
							runner = runner->next;
							foundAtNextPosition = -1;
						}
						else
						{
							break;
						}
					}
					runner = currentNode->prev; // reset startNode
					while( runner->wordData != NULL)
					{
						wordInCurrentNode = new std::string( runner->wordData->word);
						int foundAtPrevPosition = wordInCurrentNode->find( inputString->c_str());
						if( foundAtPrevPosition == 0)
						{
							p_searchResult->merge( runner->wordData->associates);
							runner = runner->prev;
							foundAtPrevPosition = -1;
						}
						else
						{
							break;
						}
					}
				}
				else
				{ 
					if( Helper::compareCaseSensitive( wordInCurrentNode->c_str(), inputString->c_str()) == Helper::SMALLER)
					{
						LowerBound = LowerBound + diff;
						up=true;
					} 
					else 
					{
						UpperBound = UpperBound - diff;
						up=false;
					}
					diff = (int)( ( UpperBound - LowerBound) / 2);
				}
			}
		}
	}
}