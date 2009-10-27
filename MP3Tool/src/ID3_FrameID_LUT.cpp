#include "StdAfx.h"
#include "ID3_FrameID_LUT.h"


ID3_FrameID_LUT::ID3_FrameID_LUT( void)
{
	frameIdRealnames = new std::map<ID3_FrameID, std::string>();
	frameIdRealnames->insert( std::make_pair( ID3FID_LEADARTIST, "Artist"));
	frameIdRealnames->insert( std::make_pair( ID3FID_TITLE, "Title"));
	frameIdRealnames->insert( std::make_pair( ID3FID_ALBUM, "Album"));
	frameIdRealnames->insert( std::make_pair( ID3FID_CONTENTTYPE, "Genre"));
	frameIdRealnames->insert( std::make_pair( ID3FID_YEAR, "Year"));
	frameIdRealnames->insert( std::make_pair( ID3FID_TRACKNUM, "Track #"));
}
ID3_FrameID_LUT::~ID3_FrameID_LUT( void)
{
	delete frameIdRealnames;
}
const char * ID3_FrameID_LUT::getRealname( ID3_FrameID id)
{
	std::map<ID3_FrameID, std::string>::iterator found = frameIdRealnames->find( id);
	if( found != frameIdRealnames->end())
		return ( found->second).c_str();
	else
		return NULL;
}
