#pragma once
#if !defined ( TRACKMANAGER_H )
#define TRACKMANAGER_H


#include "ITrackManager.h"
#include "MP3Controller.h"


/**
 * \class	TrackManager
 * \brief	Manages all input and output processes concerning tracks. 
**/
class TrackManager : public ITrackManager
{

public:

	/// \brief	Default constructor. 
	TrackManager( void);
	/// \brief	Destructor.
	~TrackManager( void);
	
	/// \brief Adds a track into the track list and returns the CTrackInfo object and the associated identifier.
	int addTrack( const string pFileName, CTrackInfo & pTrackData);
	/// \brief Removes a track from the track list and response success or failure.
	bool removeTrack( int pIndex);
	/// \brief Initiates a new search and returns an identifier for the search process.
	int trackSearchStart( const string & pTitleBeginn, TSearchID & pID);
	/// \brief Returns the next CTrackInfo object of the search process specified by its identifier.
	bool trackGetNext( TSearchID pID, CTrackInfo & pNextTrack);
	/// \brief Interrupts the search process specified by its identifier.
	void trackSearchStop( TSearchID pID);

private:

	/// \brief Local representation of the MP3Controller.
	MP3Controller * myController;

};

#endif;