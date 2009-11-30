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
	searchResult = NULL;
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
bool WordNodeList::hasNext()
{
	return ( !currentNode->next->wordData->word) ? true : false;
}
NodeList * WordNodeList::searchForSubstring(const char * p_word)
{
	searchResult = new NodeList();
	std::string * inputString = new std::string(p_word);
	currentNode = root->next;
	size_t findPos = -1;
	int count = 0;
	int aktSearchPosition = 0;
	int lastSearchJump = 0;
	int aktSearchJump = 0;
	// Wenn Die WordListe Keinen Eintrag enthält dann kann auch nix gesucht werden.
	if (length<=0)
	{
		return NULL;
	} 
	else
	{
		// Darunter mach D&C keinen Sinn
		if(length<10)
		{
			while(currentNode->next->wordData != NULL)
			{
				std::string * aktSearchString = new std::string(currentNode->wordData->word);
				findPos = aktSearchString->find(inputString);

				
				if(findPos == 0) // SuchString soll nur am Anfang sein
				{
					searchResult->insert(currentNode->wordData->associates->getFirst());
					while(currentNode->wordData->associates->hasNext())
					{
						searchResult->insert(currentNode->wordData->associates->getNext());

					}
					findPos = -1;
				}
				count++; // Debugg
				currentNode = currentNode->next;
			}

		}
		else
		{
			int UpperBound = length;
			int LowerBound = 0;
			int currentIndex = 0;
			int diff = 0;

			diff = int((UpperBound - LowerBound)/2-.5);
			if(currentIndex == 0) // Wenn der Suchsprung 0 ist
			{
				break;
			}
			else
			{
				// Wenn der Suchsprung grösser als 0 ist. 
				// Diff ist die Grösse des Sprunges
				// currentIndex ist die Untere Grenze  + der Größe des Sprunges
				currentIndex = diff + LowerBound;
				for (int g = 0; g < diff; g++) // Springe um die Menge der Srpünge an die richtige Node
				{
					currentNode = currentNode->next;
				}
				std::string * aktSearchString = new std::string(currentNode->wordData->word);
				findPos = aktSearchString->find(inputString);
				if(findPos == 0) // SuchString soll nur am Anfang sein
				{
					// Sachen die er machen muss wenn er Gefunden hat.

				}
				else
				{
					if(aktSearchString<inputString)
					{
						// suchstring ist groesser - > ergo halbiere den Sprung
						LowerBound = currentIndex;

					} 
					else // gibt nur noch nen kleiner. Bei gleich würde die Regel für findPos = 0 gelten
					{
						
						UpperBound = currentIndex; // Um wieviel Schritte muss gewechselt werden?

					}

				}
				
				
			}





			if(length%2=0)
			{
				aktSearchJump = length / 2;
				for(int i = 0; i < length/2 ; i++)
				{
					currentNode = currentNode->next;
					
				}
				std::string * aktSearchString = new std::string(currentNode->wordData->word);
				findPos = aktSearchString->find(p_word);
				if(findPos == 0) // SuchString soll nur am Anfang sein
				{
					// searchResult Füge das Ergebniss der Aktuellen Suche dem Ergebniss hinzu
					findPos = aktSearchString->find(currentNode->prev->wordData->word); // Wenn der VOrgänger auch ein Ergebniss hat
					while()
				}

			}

		}
		
	}
	if(searchResult->isEmpty())return NULL;
	else return searchResult;
	// sporinge zur Mitte des Suchergebnisses (immer auf untere ganze Zahl runden)
	// Runden unter C: int erg = int(a+0.5);


	// Schau ob das akt Element den Suchstring enthält. Wenn ja dann füge es dem
	// Suchergebniss hinzu und gehe nach prevNode und nach nextNode solange wie der Titel 
	// auch das  ergebniss enthält


	// Wenn nein dann schau ob der Suchstring kleiner oder Grösser als das aktuelle Objekt ist

	// Wenn grösser dann halbiere den aktuellen String und springe nach "unten"

	// wenn kleiner die Hälfte des letzten Suchsprunges auf den letzten Sprungwert draufaddieren


	// Return die Suchergebnisse


 
#

}