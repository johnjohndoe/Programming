#include "StdAfx.h"
#include "MP3Connector.h"
#include <id3/tag.h>
#include <iostream>
#include <sstream>

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
	// @TODO Files without or with some frames need to be covered
	while( NULL != ( myFrame = tagIter->GetNext()))
	{			
		if( NULL != myFrame)
		{
			ID3_Field * myField = myFrame->GetField( fieldId);
			// Check if current frame is part of the set aka a field of interest
			std::set<ID3_FrameID>::iterator current = interestingID3_FrameIDs->find( myFrame->GetID());
			if ( NULL != myField && current != interestingID3_FrameIDs->end())
			{
				ID3_FrameID fid = myFrame->GetID();
				ID3_FieldID id = myField->GetID();
				// Genre needs to be converted
				if( myFrame->GetID() == ID3FID_CONTENTTYPE) // ID3_FrameID = 32
				{
					std::string genre = myField->GetRawText();
					// ID3V1 genre has is an int surrounded by round brackets; ID3V2 genre is text
					unsigned int genreIntegerAlias = removeBrackets( genre.c_str());
					if( genreIntegerAlias < ID3_NR_OF_V1_GENRES)
						metadata->insert( std::make_pair( myFrame->GetID(), ID3_v1_genre_description[ genreIntegerAlias] ));
					else
						metadata->insert( std::make_pair( myFrame->GetID(), genre));
				}
				// All other tags
				else
					metadata->insert( std::make_pair( myFrame->GetID(), myField->GetRawText()));
			}
		}
	}
	return metadata;
}
unsigned int MP3Connector::removeBrackets( const char * text)
{
	std::string s = text;
	if( s[0] == '(')
		s = s.substr(1);
	if( s[s.length()-1] == ')')
		s = s.substr( 0, s.length()-1);
	std::stringstream ss;
	ss << s;
	unsigned int i;
	ss >> i;
	return i;
}