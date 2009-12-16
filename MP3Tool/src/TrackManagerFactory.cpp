#include "StdAfx.h"
#include "TrackManagerFactory.h"
#include "TrackManager.h"


ITrackManager * TrackManagerFactory::getTrackManager( TrackManagerType type)
{
	if( type == KRAMERPREUSS)
		return new TrackManager();
	else
		return new TrackManager();
}