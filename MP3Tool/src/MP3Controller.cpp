#include "StdAfx.h"
#include "MP3Controller.h"

MP3Controller::MP3Controller(void)
{
	trackList = new NodeList();
	tempMP3Data = new MP3Data();
	myGenerator = new MP3DataGenerator();
	wordNodeList = new WordNodeList();
	searchResult = NULL;
}

void MP3Controller::addMP3(const char* fPath)
{
	tempMP3Data = myGenerator->readMetadata(fPath);
	trackList->insert(tempMP3Data);
}

void MP3Controller::print()
{
   trackList->print( std::ofstream("..\\data\\nodes.txt"));
}

MP3Data* MP3Controller::getFirst(void)
{
	return trackList->getFirst();
}
MP3Data* MP3Controller::getNext(void)
{
	return trackList->getNext();
}
bool MP3Controller::hasNext(void)
{
	return trackList->hasNext();
}

void MP3Controller::createIndex()
{
	this->wordNodeList = new WordNodeList();
	std::vector<std::string> *tokenVec = new std::vector<std::string>;
	Helper::tokenize( ( trackList->getFirst()->getTitle()), *tokenVec);
	std::vector<std::string>::iterator dIter( tokenVec->begin());
	for( unsigned int i = 0 ;  dIter != tokenVec->end(); i++, dIter++)
	{
		wordNodeList->insert( tokenVec->at( i).c_str(), trackList->getFirst());
	}

	
	while(trackList->hasNext())
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
NodeList * MP3Controller::getSearchResult(const char* searchString)
{
	if(searchString != NULL)
	{
		searchResult = wordNodeList->find(searchString);
	}
	return searchResult;

}
MP3Controller::~MP3Controller(void)
{
	delete searchResult;
	delete wordNodeList;
	delete myGenerator;
	delete tempMP3Data;
	delete trackList;
}

