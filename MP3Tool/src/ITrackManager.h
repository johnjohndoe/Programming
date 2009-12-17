#pragma once
#if !defined ( ITRACKMANAGER_H )
#define ITRACKMANAGER_H


//////////////////////////////////////////////////////////////////////////////
// Programming - Übung 3
// Schnittstelle ITrackManager.h
// Tim Wöhrle, 2009-12-07
//////////////////////////////////////////////////////////////////////////////

#include <string>
using namespace std;


/// \brief Stores track information.
struct CTrackInfo
{
   int mIndex;
   string mTitle;
   string mInterpret;
   string mAlbum;
};


/// \brief Handle for a search.
typedef int TSearchID;


/// \brief Constant for a invalid track index.
#define INVALID_INDEX -1
/// \brief Constant for a invalid search result id.
#define INVALID_SEARCH_ID -1


/**
 * \class	ITrackManager
 * \brief	Interface to manage all input and output processes concerning tracks.
**/
class ITrackManager
{
public:

	/// \brief Adds a track into the track list and returns the CTrackInfo object and the associated identifier.
	virtual int addTrack( const string pFileName, CTrackInfo & pTrackData) = 0;
	/// \brief Removes a track from the track list and response success or failure.
	virtual bool removeTrack( int pIndex) = 0;
	/// \brief Initiates a new search and returns an identifier for the search process.
	virtual int trackSearchStart( const string & pTitleBeginn, TSearchID & pID) = 0;
	/// \brief Returns the next CTrackInfo object of the search process specified by its identifier.
	virtual bool trackGetNext( TSearchID pID, CTrackInfo & pNextTrack) = 0;
	/// \brief Interrupts the search process specified by its identifier.
	virtual void trackSearchStop( TSearchID pID) = 0;

};

#endif;