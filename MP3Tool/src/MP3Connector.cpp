#include "StdAfx.h"
#include "MP3Connector.h"
#include "MP3Data.h"
#include "ID3_FrameID_LUT.h"
#include <id3/tag.h>
#include <iostream>
#include <sstream>


MP3Connector::MP3Connector( void)
{
	encoding = "Text encoding: ";
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
				ID3_FrameID_LUT * myLUT = new ID3_FrameID_LUT();
				std::string frameRealname = std::string( myLUT->getRealname( myFrame->GetID()));
				// @TODO Show encoding in gui (optional)
				if( myField->GetEncoding() == ID3TE_ASCII || ID3TE_ISO8859_1)
				{
					encoding += frameRealname + ": ISO8859_1 , ";
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
				else if( myField->GetEncoding() == ID3TE_UTF8)
				{
					encoding += frameRealname + ": utf8 , ";
					metadata->insert( std::make_pair( myFrame->GetID(), "<unicode utf8 encoding>"));
				}
				else if( myField->GetEncoding() == ID3TE_UNICODE || ID3TE_UTF16)
				{
					encoding += frameRealname + ": utf16 ,";
					// @TODO Conversion to std::string ... myField->GetRawUnicodeText();
					metadata->insert( std::make_pair( myFrame->GetID(), "<unicode utf16 encoding>: "));
				}
				else if( myField->GetEncoding() == ID3TE_UTF16BE)
				{
					encoding += frameRealname + ": utf16be , ";
					metadata->insert( std::make_pair( myFrame->GetID(), "<unicode utf16be encoding>"));
				}
				else if( myField->GetEncoding() == ID3TE_NUMENCODINGS)
				{
					encoding += frameRealname + ": numencodings , ";
					metadata->insert( std::make_pair( myFrame->GetID(), "<numencoding>"));
				}
				else
				{
					encoding += frameRealname + ": unknown , ";
					metadata->insert( std::make_pair( myFrame->GetID(), "<unknown encoding>"));
				}
			}
		}
	}
	return metadata;
}
std::string MP3Connector::getEncoding()
{
	return encoding.substr( 0, encoding.length()-2);
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