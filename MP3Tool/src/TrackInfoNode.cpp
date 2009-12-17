#include "StdAfx.h"
#include "TrackInfoNode.h"


TrackInfoNode::TrackInfoNode( CTrackInfo & p_trackInfo)
{
	trackInfo = new CTrackInfo();
	trackInfo->mIndex = p_trackInfo.mIndex;
	trackInfo->mInterpret = p_trackInfo.mInterpret;
	trackInfo->mTitle = p_trackInfo.mTitle;
	trackInfo->mAlbum = p_trackInfo.mAlbum;
}
TrackInfoNode::~TrackInfoNode( void)
{
	delete trackInfo;
}
CTrackInfo * TrackInfoNode::getTrackInfo( void)
{
	return trackInfo;
}
System::String ^ TrackInfoNode::ToString( void)
{
	return gcnew System::String( trackInfo->mTitle.c_str());
}
