#include "StdAfx.h"
#include "MP3DataGenerator.h"
#include "ID3_FrameID_LUT.h"
#include "MP3Data.h"
#include "Helper.h"
#include <sstream>


MP3DataGenerator::MP3DataGenerator( void)
{
	myID3_Tag = NULL;
	encoding = "Text encoding: ";
	interestingID3_FrameIDs = new std::set<ID3_FrameID>();
	interestingID3_FrameIDs->insert( ID3FID_LEADARTIST);	// Artist
	interestingID3_FrameIDs->insert( ID3FID_TITLE);
	interestingID3_FrameIDs->insert( ID3FID_ALBUM);
	interestingID3_FrameIDs->insert( ID3FID_CONTENTTYPE);	// Genre
	interestingID3_FrameIDs->insert( ID3FID_YEAR);
	interestingID3_FrameIDs->insert( ID3FID_TRACKNUM);
}
MP3DataGenerator::~MP3DataGenerator( void)
{
	delete interestingID3_FrameIDs;
}
MP3Data * MP3DataGenerator::readMetadata( const char * p_filePath)
{

	myID3_Tag = new ID3_Tag();
	myID3_Tag->Link( p_filePath);
	MP3Data * myMP3Data = new MP3Data();
	myMP3Data->setAll( "<undefinded>");


	ID3_FieldID fieldId = ID3FN_TEXT;

	std::set<ID3_FieldID> * myFields = new std::set<ID3_FieldID>();
	myFields->insert( ID3FN_TEXT);

	ID3_Tag::Iterator * tagIter = myID3_Tag->CreateIterator();
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
						if( genreIntegerAlias < ID3_NR_OF_V1_GENRES && genre[0] == '(')
							myMP3Data->setGenre( ID3_v1_genre_description[ genreIntegerAlias]);
						else 
							myMP3Data->setGenre( genre.c_str());
					}
					// All other tags
					else if( myFrame->GetID() == ID3FID_TITLE)
						myMP3Data->setTitle( myField->GetRawText());
					else if( myFrame->GetID() == ID3FID_ALBUM)
						myMP3Data->setAlbum( myField->GetRawText());
					else if( myFrame->GetID() == ID3FID_YEAR)
						myMP3Data->setYear( myField->GetRawText());
					else if( myFrame->GetID() == ID3FID_TRACKNUM)
						myMP3Data->setTracknumber( myField->GetRawText());
					else if( myFrame->GetID() == ID3FID_LEADARTIST)
						myMP3Data->setArtist( myField->GetRawText());
				}
				else if( myField->GetEncoding() == ID3TE_UTF8)
				{
					encoding += frameRealname + ": utf8 , ";
					myMP3Data->setAll( "<unicode utf8 encoding>");
				}
				else if( myField->GetEncoding() == ID3TE_UNICODE || ID3TE_UTF16)
				{
					encoding += frameRealname + ": utf16 ,";
					// @TODO Conversion to std::string ... myField->GetRawUnicodeText();
					myMP3Data->setAll( "<unicode utf16 encoding>");
				}
				else if( myField->GetEncoding() == ID3TE_UTF16BE)
				{
					encoding += frameRealname + ": utf16be , ";
					myMP3Data->setAll( "<unicode utf16be encoding>");
				}
				else if( myField->GetEncoding() == ID3TE_NUMENCODINGS)
				{
					encoding += frameRealname + ": numencodings , ";
					myMP3Data->setAll( "<numencoding>");
				}
				else
				{
					encoding += frameRealname + ": unknown , ";
					myMP3Data->setAll( "<<unknown encoding>");
				}
			}
		}
	}
	myMP3Data->setFilepath( p_filePath);
	std::string t_fileName = getFilename( p_filePath).c_str();
	myMP3Data->setFilename( t_fileName.c_str());
	return myMP3Data;
}
std::string MP3DataGenerator::getEncoding()
{
	return encoding.substr( 0, encoding.length()-2);
}
unsigned int MP3DataGenerator::removeBrackets( const char * p_text)
{
	std::string s = p_text;
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
std::string MP3DataGenerator::getFilename( const char * p_filePath)
{
	std::string t_path = p_filePath;
	std::string::size_type lastPos = t_path.find_last_of( "\\");
	std::string::size_type t_length = t_path.size();
	std::string t_string = t_path.substr( lastPos+1, ( t_length-lastPos));
	return t_string;
}