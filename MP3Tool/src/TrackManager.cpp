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
	boost::mutex::scoped_lock add_lock(boost::mutex);
	MP3Data * currentMP3Data = myController->addMP3( pFileName.c_str());
	int id = currentMP3Data->getId();
	if( id != INVALID_INDEX)
	{
		pTrackData.mIndex = currentMP3Data->getId();
		pTrackData.mAlbum = currentMP3Data->getAlbum();
		pTrackData.mInterpret = currentMP3Data->getArtist();
		pTrackData.mTitle = currentMP3Data->getTitle();
	}
	myController->createIndex();
	return id;
}
bool TrackManager::removeTrack( int pIndex)
{
	boost::mutex::scoped_lock remove_lock(boost::mutex);
	bool isRemoved = myController->getTrackList()->removeObjById( pIndex);
	myController->createIndex();
	return isRemoved;
}
int TrackManager::trackSearchStart( const string & pTitleBeginn, TSearchID & pID)
{
	if(pTitleBeginn == "")
	{
		myController->getTrackList()->begin();
		return myController->getTrackList()->getLength();
	}
	else
	{
		myController->getSearchResult( pTitleBeginn.c_str());
		pID = 2;
		return myController->getSearchResult()->getLength();
	}
}
bool TrackManager::trackGetNext( TSearchID pID, CTrackInfo & pNextTrack)
{
	MP3Data * t_Data = NULL;

	if(pID == INVALID_SEARCH_ID) // Get whole track list
	{
		t_Data = myController->getTrackList()->getNext();
		if(t_Data != NULL)	// returns current iterator-item
		{
			pNextTrack.mAlbum = t_Data->getAlbum();
			pNextTrack.mInterpret = t_Data->getArtist();
			pNextTrack.mTitle = t_Data->getTitle();
			pNextTrack.mIndex = t_Data->getId();
			return true;	// successfully retrieved item
		}
		else	// current iterator-item is NULL
		{
			return false;
		}
	}
	else // get node list for the search-ID
	{
		NodeList * t_searchResult = myController->getSearchResult();
		if(t_searchResult)
		{
			t_Data = t_searchResult->getNext();

			if(t_Data != NULL) 
			{
				pNextTrack.mAlbum = t_Data->getAlbum();
				pNextTrack.mInterpret = t_Data->getArtist();
				pNextTrack.mTitle = t_Data->getTitle();
				pNextTrack.mIndex = t_Data->getId();
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}
void TrackManager::trackSearchStop( TSearchID pID)
{
}

bool TrackManager::isEqual(TrackManager* trkMngr)
{
	if(this->myController->trackList->equals(trkMngr->myController->trackList))
	{
		return true;
	}
	else
	{
		return false;
	}
}
