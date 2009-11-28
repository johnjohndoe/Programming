#include "StdAfx.h"
#include "MP3Controller.h"

MP3Controller::MP3Controller(void)
{
	trackList = new NodeList();
	tempMP3Data = new MP3Data();
	myGenerator = new MP3DataGenerator();
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

const char* MP3Controller::search(const char* searchString)
{
	return searchString;

}


bool MP3Controller::deleteTrack(int position)
{
//	int ID = myIndex->deleteItem(position);
//	void myTrackList->deleteItem(trackID);
	return true;

}


MP3Controller::~MP3Controller(void)
{
}
