#include "StdAfx.h"
#include "MP3Data.h"


MP3Data::MP3Data( void)
{
	this->id = -1;
	this->title = NULL;
	this->artist = NULL;
	this->album = NULL;
	this->year = NULL;
	this->tracknumber = NULL;
	this->genre = NULL;
	this->filepath = NULL;
	this->filename = NULL;
}
MP3Data::~MP3Data( void)
{
	if( filename) delete[] filename;
	if( filepath) delete[] filepath;
	if( genre) delete[] genre;
	if( tracknumber) delete[] tracknumber;
	if( year) delete[] year;
	if( album) delete[] album;
	if( artist) delete[] artist;
	if( title) delete[] title;
}
int MP3Data::getId()					{	return id;												}
const char * MP3Data::getTitle()		{	return ( title) ? title : "<undefined>";				}
const char * MP3Data::getArtist()		{	return ( artist) ? artist : "<undefined>";				}
const char * MP3Data::getAlbum()		{	return ( album) ? album : "<undefined>";				}
const char * MP3Data::getYear()			{	return ( year) ? year : "<undefined>";					}
const char * MP3Data::getTracknumber()	{	return ( tracknumber) ? tracknumber : "<undefined>";	}
const char * MP3Data::getGenre()		{	return ( genre) ? genre : "<undefined>";				}
const char * MP3Data::getFilepath()		{	return ( filepath) ? filepath : "<undefined>";			}
const char * MP3Data::getFilename()		{	return ( filename) ? filename : "<undefined>";			}


void MP3Data::setId( int p_Id)
{
	id = p_Id;
}
void MP3Data::setTitle( const char * p_title)				
{
	unsigned int numBytes = Helper::length( p_title);
	if( title) delete[] title;
	title = new char[ numBytes + 1];
	memmove( title, p_title, numBytes + 1);
}
void MP3Data::setArtist( const char * p_artist)				
{
	unsigned int numBytes = Helper::length( p_artist);
	if( artist) delete[] artist;
	artist = new char[ numBytes + 1];
	memmove( artist, p_artist, numBytes + 1);	
}
void MP3Data::setAlbum( const char * p_album)				
{
	unsigned int numBytes = Helper::length( p_album);
	if( album) delete[] album;
	album = new char[ numBytes + 1];
	memmove( album, p_album, numBytes + 1);				
}
void MP3Data::setYear( const char * p_year)					
{
	unsigned int numBytes = Helper::length( p_year);
	if( year) delete[] year;
	year = new char[ numBytes + 1];
	memmove( year, p_year, numBytes + 1);			
}
void MP3Data::setTracknumber( const char * p_tracknumber)	
{
	unsigned int numBytes = Helper::length( p_tracknumber);
	if( tracknumber) delete[] tracknumber;
	tracknumber = new char[ numBytes + 1];
	memmove( tracknumber, p_tracknumber, numBytes + 1);
}
void MP3Data::setGenre( const char * p_genre)				
{	
	unsigned int numBytes = Helper::length( p_genre);
	if( genre) delete[] genre;
	genre = new char[ numBytes + 1];
	memmove( genre, p_genre, numBytes + 1);
}
void MP3Data::setFilepath( const char * p_filepath)			
{	
	unsigned int numBytes = Helper::length( p_filepath);
	if( filepath) delete[] filepath;
	filepath = new char[ numBytes + 1];
	memmove( filepath, p_filepath, numBytes + 1);	
}
void MP3Data::setFilename( const char * p_filename)			
{	
	unsigned int numBytes = Helper::length( p_filename);
	if( filename) delete[] filename;
	filename = new char[ numBytes + 1];
	memmove( filename, p_filename, numBytes + 1);		
}
void MP3Data::setAll( const char * p_value)
{
	unsigned int numBytes = Helper::length( p_value);

	if( title) delete[] title;
	title = new char[ numBytes + 1];
	memmove( title, p_value, numBytes + 1);

	if( artist) delete[] artist;
	artist = new char[ numBytes + 1];	
	memmove( artist, p_value, numBytes + 1);

	if( album) delete[] album;
	album = new char[ numBytes + 1];
	memmove( album, p_value, numBytes + 1);

	if( year != NULL) delete[] year;
	year = new char[ numBytes + 1 ];
	memmove( year, p_value, numBytes + 1);

	if( tracknumber) delete[] tracknumber;
	tracknumber = new char[ numBytes + 1];
	memmove( tracknumber, p_value, numBytes + 1);

	if( genre) delete[] genre;
	genre = new char[ numBytes + 1];
	memmove( genre, p_value, numBytes + 1);

	if( filepath) delete[] filepath;
	filepath = new char[ numBytes + 1];
	memmove( filepath, p_value, numBytes + 1);

	if( filename) delete[] filename;
	filename = new char[ numBytes + 1];
	memmove( filename, p_value, numBytes + 1);
}

void MP3Data::print( std::ostream & os)
{
	os << "Title: " << getTitle() << "\n";
	os << "Artist: " << getArtist()<< "\n";
	os << "Album: " << getAlbum() << "\n";
	os << "Year: " << getYear() << "\n";
	os << "Track number: " << getTracknumber() << "\n";
	os << "Genre: " << getGenre() << "\n";
	os << "Filename: " << getFilename() << "\n";
	os << "Filepath: " << getFilepath() << std::endl;
}