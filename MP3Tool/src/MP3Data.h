#pragma once
#if !defined ( MP3DATA_H )
#define MP3DATA_H


#include <ostream>
#include <iostream>
#include <string>


class MP3Data
{

public:

	/// \brief	Default constructor. 
	MP3Data( void);
	/// \brief	Destructor. 
	~MP3Data( void);

	void setIndex( int pIndex);
	void setTitle( const char * pTitle);
	void setArtist( const char * pArtist);
	void setAlbum( const char * pAlbum);
	void setYear( const char * pYear);
	void setTracknumber( const char * pTracknumber);
	void setGenre( const char * pGenre);
	void setAll( const char * pValue);

	int getIndex( void);
	const char * getTitle( void);
	const char * getArtist( void);
	const char * getAlbum( void);
	const char * getYear( void);
	const char * getTracknumber( void);
	const char * getGenre( void);

	void print( std::ostream & os = std::cout);

private:

	int index;
	const char * title;
	const char * artist;
	const char * album;
	const char * year;
	const char * tracknumber;
	const char * genre;
};

#endif;
