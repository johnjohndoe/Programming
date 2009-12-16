#pragma once
#if !defined ( TRACKMANAGERFACTORY_H )
#define TRACKMANAGERFACTORY_H


#include "ITrackManager.h"


/**
 * \class	TrackManagerFactory
 * \brief	Factory class to provide different types of track manager.
**/
class TrackManagerFactory
{

public:

	/// \brief Specifies the types of track managers that are available.
	enum TrackManagerType { KRAMERPREUSS};
	/// \brief Returns a track manager.
	static ITrackManager * getTrackManager( TrackManagerType type = KRAMERPREUSS);

private:

	/// \brief Default constructor.
	TrackManagerFactory( void);
	/// \brief Destructor.
	~TrackManagerFactory( void);

};

#endif;
