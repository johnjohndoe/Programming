#include "StdAfx.h"
#include "MP3Connector.h"
#include <id3/tag.h>
#include <iostream>
#include <set>

// Constructor
MP3Connector::MP3Connector( void)
{
}

// Constructor
MP3Connector::MP3Connector( const char * temp_String)
{
	this->getFile(temp_String);
}

// Destructor
MP3Connector::~MP3Connector( void)
{
}

bool MP3Connector::getFile( const char * pPath)
{
	if( pPath)
	{
		myTag.Link( pPath);
		return true;
	}
	else
		return false;
	
}
void MP3Connector::retrieveTitle( void)
{
	ID3_FrameID frameId = ID3FID_TITLE;
	ID3_FieldID fieldId = ID3FN_TEXT;
	
	ID3_Frame * myFrame = myTag.Find( frameId);
	if ( NULL != myFrame)
	{
		ID3_Field * myField = myFrame->GetField( fieldId);
		if ( NULL != myField)
		{
			mTitle = myField->GetRawText();
		}
	}
}
void MP3Connector::retrieveMetadata( void)
{
	ID3_FrameID frameId = ID3FID_TITLE;
	ID3_FieldID fieldId = ID3FN_TEXT;

	std::set<ID3_FrameID> * myFrames = new std::set<ID3_FrameID>();
	myFrames->insert( ID3FID_TITLE);
	myFrames->insert( ID3FID_ALBUM);
	myFrames->insert( ID3FID_LEADARTIST);
	myFrames->insert( ID3FID_YEAR);
	myFrames->insert( ID3FID_TRACKNUM);
	//myFrames->insert( ID3FID_); Genre?

	std::set<ID3_FieldID> * myFields = new std::set<ID3_FieldID>();
	myFields->insert( ID3FN_TEXT);

	ID3_Tag::Iterator * tagIter = myTag.CreateIterator();
	ID3_Frame * myFrame = NULL;
	while( NULL != ( myFrame = tagIter->GetNext()))
	{			
		if( NULL != myFrame)
		{
			ID3_Field * myField = myFrame->GetField( fieldId);
			if ( NULL != myField)
			{
				if( myFrame->GetID() == ID3FID_TITLE)
					mTitle = myField->GetRawText();
				else if( myFrame->GetID() == ID3FID_ALBUM)
					mAlbum = myField->GetRawText();
			}
		}
	}
}

const char *MP3Connector::getTitle() const	{	return mTitle;	}
const char *MP3Connector::getAuthor() const	{	return mAuthor.c_str();	}
const char *MP3Connector::getAlbum() const	{	return mAlbum.c_str();	}
const char *MP3Connector::getGenre() const	{	return mGenre.c_str();	}
int MP3Connector::getYear() const			{	return mYear;			}
int MP3Connector::getTrack() const			{	return mTrack;			}
