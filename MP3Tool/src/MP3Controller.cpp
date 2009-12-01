#include "StdAfx.h"
#include <iostream>
#include <ostream>
#include <exception>
#include "MP3Data.h"
#include "MP3Controller.h"


MP3Controller::MP3Controller( void)
{
	trackList = new NodeList();
	myGenerator = new MP3DataGenerator();
	wordNodeList = new WordNodeList();
	searchResult = NULL;
}
MP3Controller::~MP3Controller( void)
{
	delete searchResult;
	delete wordNodeList;
	delete myGenerator;
	delete trackList;
}
void MP3Controller::addMP3( const char * p_filePath)
{
	MP3Data * tempMP3Data = myGenerator->readMetadata( p_filePath);
	if( tempMP3Data)
		trackList->insert( tempMP3Data);
	else
	{
		throw "Error: MP3Controller::addMP3(), MP3DataGenerator could not build metadata object.";
		exit( -1);
	}
}
void MP3Controller::createIndex()
{
	// Index all words of the first element in the track list
	this->wordNodeList = new WordNodeList();
	std::vector<std::string> * tokenVec = new std::vector<std::string>;
	Helper::tokenize( ( trackList->getFirst()->getTitle()), *tokenVec);
	std::vector<std::string>::iterator dIter( tokenVec->begin());
	for( unsigned int i = 0 ;  dIter != tokenVec->end(); i++, dIter++)
	{
		wordNodeList->insert( tokenVec->at( i).c_str(), trackList->getFirst());
	}

	// Index all words of the following elements in the track list
	while( trackList->hasNext())
	{
		tokenVec = new std::vector<std::string>;
		MP3Data * t_data = trackList->getNext();
		Helper::tokenize( ( t_data->getTitle()), *tokenVec);
		std::vector<std::string>::iterator dIter( tokenVec->begin());
		for( unsigned int i = 0 ;  dIter != tokenVec->end(); i++, dIter++)
		{
			wordNodeList->insert( tokenVec->at( i).c_str(), t_data);
		}
	}
}
void MP3Controller::clearLists()
{
	this->trackList = new NodeList();
	this->wordNodeList = new WordNodeList();
}
NodeList * MP3Controller::getSearchResult( const char * searchString)
{
	if( searchString != NULL)
	{
		//searchResult = wordNodeList->find(searchString);
		searchResult = wordNodeList->searchForSubstring(searchString);
	}
	if(searchResult) searchResult->print(std::ofstream("..\\data\\searchresult.log"));
	return searchResult;
}
void MP3Controller::print()
{
	trackList->print( std::ofstream("..\\data\\nodes.txt"));
}