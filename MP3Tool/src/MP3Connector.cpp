#include "StdAfx.h"
#include "MP3Connector.h"
#include <id3/tag.h>
#include <iostream>


MP3Connector::MP3Connector( void)
{
	interestingID3_FrameIDs = new std::set<ID3_FrameID>();
	interestingID3_FrameIDs->insert( ID3FID_LEADARTIST);	// Artist
	interestingID3_FrameIDs->insert( ID3FID_TITLE);
	interestingID3_FrameIDs->insert( ID3FID_ALBUM);
	interestingID3_FrameIDs->insert( ID3FID_CONTENTTYPE);	// Genre
	interestingID3_FrameIDs->insert( ID3FID_YEAR);
	interestingID3_FrameIDs->insert( ID3FID_TRACKNUM);
}
MP3Connector::~MP3Connector( void)
{
	delete interestingID3_FrameIDs;
}
bool MP3Connector::getFile( const char * pPath)
{
	// Check if path is given
	if( pPath)
	{
		// @TODO Check if file is accessible
		myTag.Link( pPath);
		return true;
	}
	else
		return false;
	
}
std::map<ID3_FrameID, std::string> * MP3Connector::getMetadata( void)
{
	metadata = new std::map<ID3_FrameID, std::string>();
	ID3_FieldID fieldId = ID3FN_TEXT;

	std::set<ID3_FieldID> * myFields = new std::set<ID3_FieldID>();
	myFields->insert( ID3FN_TEXT);

	ID3_Tag::Iterator * tagIter = myTag.CreateIterator();
	ID3_Frame * myFrame = NULL;
	while( NULL != ( myFrame = tagIter->GetNext()))
	{			
		if( NULL != myFrame)
		{
			ID3_Field * myField = myFrame->GetField( fieldId);
			// Check if current frame is part of the set aka a field of interest
			std::set<ID3_FrameID>::iterator current = interestingID3_FrameIDs->find( myFrame->GetID());
			if ( NULL != myField && current != interestingID3_FrameIDs->end())
			{
				metadata->insert( std::make_pair( myFrame->GetID(), myField->GetRawText()));
			}
		}
	}
	return metadata;
}