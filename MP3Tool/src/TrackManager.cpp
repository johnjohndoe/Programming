#include "StdAfx.h"
#include "TrackManager.h"



TrackManager::TrackManager(void)
{
	myController = new MP3Controller();
	
}

int TrackManager::addTrack( const string pFileName, CTrackInfo &pTrackData )
{
	int index =  myController.addMP3(pFileName.c_str());
	// Wie bekommen wir nach einer Einfüge-Operation sowohl den index des letzten Eintrages UND den letzten Eintrag?
	// Wir können uns als return den Index-Wert geben und dann ein myController.TrackList.at(int) das objekt zurpück geben lassen

	pTrackData = myController.getItemFromTrackList(index);
	return index;

	
}

bool TrackManager::removeTrack( int pIndex )
{
	myController.trackList->removeObj(pIndex);

	return true;
}

int TrackManager::trackGetNext( TSearchID pID, CTrackInfo &pNextTrack )
{

return 0;
}

bool TrackManager::trackSearchStart( const string &pTitleBeginn, TSearchID &pID )
{

	return true;
}

void TrackManager::trackSearchStop( TSearchID pID )
{


}