#pragma once
#if !defined ( TRACKINFONODE_H )
#define TRACKINFONODE_H


#include <string>
#include "ITrackManager.h"


/**
 * \class	TrackInfoNode
 * \brief	Encapsulates the track information to be used as an gui object.
**/
class TrackInfoNode
{

public:

	/// \brief Constructor.
	TrackInfoNode( CTrackInfo & p_trackInfo);
	/// \brief Destructor.
	~TrackInfoNode( void);
	/// \brief Return the track info object.
	CTrackInfo * getTrackInfo( void);
	/// \brief Overrides the Object method.
	//virtual System::String ^ ToString( void) override;

private:

	/// \brief Stores the track information.
	CTrackInfo * trackInfo;

};

#endif;