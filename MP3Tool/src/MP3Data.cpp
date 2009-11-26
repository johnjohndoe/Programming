#include "StdAfx.h"
#include "MP3Data.h"


MP3Data::MP3Data( void)
{
	this->index = -1;		// Default value.
	this->title = NULL;
	this->artist = NULL;
	this->album = NULL;
	this->year = NULL;
	this->tracknumber = NULL;
	this->genre = NULL;
}
MP3Data::~MP3Data( void)
{
	// Nothing to destroy.
}
int MP3Data::getIndex()					{	return this->index;										}
const char * MP3Data::getTitle()		{	return ( title) ? title : "<undefined>";				}
const char * MP3Data::getArtist()		{	return ( artist) ? artist : "<undefined>";				}
const char * MP3Data::getAlbum()		{	return ( album) ? album : "<undefined>";				}
const char * MP3Data::getYear()			{	return ( year) ? year : "<undefined>";					}
const char * MP3Data::getTracknumber()	{	return ( tracknumber) ? tracknumber : "<undefined>";	}
const char * MP3Data::getGenre()		{	return ( genre) ? genre : "<undefined>";				}

void MP3Data::setIndex( int p_index)						{	this->index = p_index;				}
void MP3Data::setTitle( const char * p_title)				{	this->title = p_title;				}
void MP3Data::setArtist( const char * p_artist)				{	this->artist = p_artist;			}
void MP3Data::setAlbum( const char * p_album)				{	this->album = p_album;				}
void MP3Data::setYear( const char * p_year)					{	this->year = p_year;				}
void MP3Data::setTracknumber( const char * p_tracknumber)	{	this->tracknumber = p_tracknumber;	}
void MP3Data::setGenre( const char * p_genre)				{	this->genre = p_genre;				}
void MP3Data::setAll( const char * p_value)
{
	this->title = p_value;
	this->artist= p_value;
	this->album = p_value;
	this->year = p_value;
	this->tracknumber = p_value;
	this->genre = p_value;
}

void MP3Data::print( std::ostream & os)
{
	os << "Index: " << getIndex() << "\n";
	os << "Title: " << getTitle() << "\n";
	os << "Artist: " << getArtist()<< "\n";
	os << "Album: " << getAlbum() << "\n";
	os << "Year: " << getYear() << "\n";
	os << "Track number: " << getTracknumber() << "\n";
	os << "Genre: " << getGenre() << std::endl;
}