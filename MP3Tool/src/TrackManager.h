#pragma once
#if !defined ( TRACKMANAGER_H )
#define TRACKMANAGER_H

#include "ITrackManager.h"
#include "MP3Controller.h"


class TrackManager : public ITrackManager
{

public:
	MP3Controller myController;

	TrackManager(void);
	int addTrack( const string pFileName, /*out*/ CTrackInfo &pTrackData ) = 0;
	bool removeTrack( int pIndex ) = 0;
	int trackSearchStart( const string &pTitleBeginn, /*out*/ TSearchID &pID ) = 0;
	bool trackGetNext( TSearchID pID, /*out*/ CTrackInfo &pNextTrack ) = 0;
	void trackSearchStop( TSearchID pID ) = 0;


};
#endif