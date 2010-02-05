#include "StdAfx.h"
#include "TrackManager.h"
#include <boost/thread.hpp>
#include <map>


boost::shared_mutex mySharedMutex;


TrackManager::TrackManager( void)
{
	myController = new MP3Controller();	
	searchResultCount = 1;
	
}
TrackManager::~TrackManager( void)
{
	// iterates over the std::map with the search-result NodeLists, deallocates all collected searchresults
	for(std::map<int, NodeList*>::const_iterator i = searchResultList.begin(); i != searchResultList.end(); ++i)
	{
		if(i->second != NULL) delete i->second;
	}
	delete myController;

}
int TrackManager::addTrack( const string pFileName, CTrackInfo & pTrackData)
{
	mySharedMutex.lock();
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
	mySharedMutex.unlock();	
	return id;
}
bool TrackManager::removeTrack( int pIndex)
{
	mySharedMutex.lock();
	bool isRemoved = myController->getTrackList()->removeObjById( pIndex);
	myController->createIndex();
	mySharedMutex.unlock();
	return isRemoved;
}
int TrackManager::trackSearchStart( const string & pTitleBeginn, TSearchID & pID)
{
	if( pTitleBeginn == "")
	{
		myController->getTrackList()->begin();
		pID = ALL_TRACKS_SEARCH_ID;
		return myController->getTrackList()->getLength();
	}
	else
	{
		mySharedMutex.lock();
		searchResultCount++;
		searchResultList[searchResultCount] = myController->getSearchResult( pTitleBeginn.c_str());
		pID = searchResultCount;
		std::cout << "search started, searchID: " << pID << std::endl;
		unsigned int length = searchResultList[searchResultCount]->getLength();
		mySharedMutex.unlock();
		return length;
	}
}
bool TrackManager::trackGetNext( TSearchID pID, CTrackInfo & pNextTrack)
{
	MP3Data * t_Data = NULL;
	mySharedMutex.lock_shared();
	if(pID == ALL_TRACKS_SEARCH_ID) // Get whole track list
	{
		t_Data = myController->getTrackList()->getNext();
	
		if(t_Data != NULL)	// returns current iterator-item
		{
			pNextTrack.mAlbum = t_Data->getAlbum();
			pNextTrack.mInterpret = t_Data->getArtist();
			pNextTrack.mTitle = t_Data->getTitle();
			pNextTrack.mIndex = t_Data->getId();
			mySharedMutex.unlock_shared();
			return true;	// successfully retrieved item
		}
		else	// current iterator-item is NULL
		{
			mySharedMutex.unlock_shared();
			return false;
		}
	}
	else // get node list for the search-ID
	{	
		NodeList * t_searchResult = searchResultList[pID];

		if(t_searchResult)
		{
			t_Data = t_searchResult->getNext();

			if(t_Data != NULL) 
			{
				pNextTrack.mAlbum = t_Data->getAlbum();
				pNextTrack.mInterpret = t_Data->getArtist();
				pNextTrack.mTitle = t_Data->getTitle();
				pNextTrack.mIndex = t_Data->getId();
				mySharedMutex.unlock_shared();
				return true;
			}
			else
			{
				mySharedMutex.unlock_shared();
				return false;
			}
		}
		else
		{
			mySharedMutex.unlock_shared();
			return false;
		}

	}
}
void TrackManager::trackSearchStop( TSearchID pID)
{
}
