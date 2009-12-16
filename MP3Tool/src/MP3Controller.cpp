#include "StdAfx.h"
#include <iostream>
#include <ostream>
#include <exception>
#include "MP3Data.h"
#include "MP3Controller.h"


MP3Controller::MP3Controller( void)
{
	myGenerator = new MP3DataGenerator();
	trackList = new NodeList();
	indexList = new WordNodeList();
	searchResult = NULL;
}
MP3Controller::~MP3Controller( void)
{
	if( searchResult != NULL) delete searchResult;
	if( indexList != NULL) delete indexList;
	if( trackList != NULL) delete trackList;
	if( myGenerator != NULL) delete myGenerator;
}
MP3Data * MP3Controller::addMP3( const char * p_filePath)
{
	MP3Data * tempMP3Data = myGenerator->readMetadata( p_filePath);
	if( tempMP3Data)
		trackList->insertById( tempMP3Data);
	else
	{
		throw "Error: MP3Controller::addMP3(), MP3DataGenerator could not build metadata object.";
		exit( -1);
	}
	trackList->print(std::ofstream("..\\data\\nodelist.log"));
	return tempMP3Data;
}
void MP3Controller::createIndex( void)
{
	// Index all words of the first element in the track list
	this->indexList = new WordNodeList();
	std::vector<std::string> * tokenVec = new std::vector<std::string>;
	Helper::tokenize( ( trackList->getFirst()->getTitle()), *tokenVec);
	std::vector<std::string>::iterator dIter( tokenVec->begin());
	for( unsigned int i = 0 ;  dIter != tokenVec->end(); i++, dIter++)
	{
		indexList->insert( tokenVec->at( i).c_str(), trackList->getFirst());
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
			indexList->insert( tokenVec->at( i).c_str(), t_data);
		}
	}
}
void MP3Controller::clearLists( void)
{
	if( indexList != NULL) delete indexList;
	if( trackList != NULL) delete trackList;
	this->trackList = new NodeList();
	this->indexList = new WordNodeList();
}
void MP3Controller::resetIndexList( void)
{
	if( indexList != NULL) delete indexList;
	this->indexList = new WordNodeList();
}
void MP3Controller::resetTracklist( void)
{
	if( trackList != NULL) delete trackList;
	this->trackList = new NodeList();
}
void MP3Controller::resetSearchResult( void)
{
	if( searchResult != NULL) delete searchResult;
	this->searchResult = new NodeList();
}
NodeList * MP3Controller::getSearchResult( const char * searchString)
{
	if( searchString != NULL)
	{
		resetSearchResult();
		indexList->searchForSubstring( searchResult, searchString);
	}
	return searchResult;
}
NodeList * MP3Controller::getTrackList( void)
{
	return trackList;
}
