#include "StdAfx.h"
#include "TrackManager.h"


TrackManager::TrackManager( void)
{
	myController = new MP3Controller();	
}
TrackManager::~TrackManager( void)
{
	delete myController;
}
int TrackManager::addTrack( const string pFileName, CTrackInfo & pTrackData)
{
	MP3Data * currentMP3Data = myController->addMP3( pFileName.c_str());
	int id = currentMP3Data->getId();
	if( id != INVALID_INDEX)
	{
		pTrackData.mIndex = currentMP3Data->getId();
		pTrackData.mAlbum = currentMP3Data->getAlbum();
		pTrackData.mInterpret = currentMP3Data->getArtist();
		pTrackData.mTitle = currentMP3Data->getTitle();
	}
	return id;
}
bool TrackManager::removeTrack( int pIndex)
{
	myController->getTrackList()->removeObjById( pIndex);
	return false;
}
int TrackManager::trackSearchStart( const string & pTitleBeginn, TSearchID & pID)
{
	return false;
}
bool TrackManager::trackGetNext( TSearchID pID, CTrackInfo & pNextTrack)
{
	return false;
}
void TrackManager::trackSearchStop( TSearchID pID)
{

}