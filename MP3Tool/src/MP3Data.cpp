#include "StdAfx.h"
#include "MP3Data.h"




MP3Data::MP3Data( void)
{
	this->index = -1;
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

void MP3Data::setIndex( int pIndex)							{	this->index = pIndex;				}
void MP3Data::setTitle( const char * pTitle)				{	this->title = pTitle;				}
void MP3Data::setArtist( const char * pArtist)				{	this->artist = pArtist;				}
void MP3Data::setAlbum( const char * pAlbum)				{	this->album = pAlbum;				}
void MP3Data::setYear( const char * pYear)					{	this->year = pYear;					}
void MP3Data::setTracknumber( const char * pTracknumber)	{	this->tracknumber = pTracknumber;	}
void MP3Data::setGenre( const char * pGenre)				{	this->genre = pGenre;				}
void MP3Data::setAll( const char * pValue)
{
	this->title = pValue;
	this->artist= pValue;
	this->album = pValue;
	this->year = pValue;
	this->tracknumber = pValue;
	this->genre = pValue;
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