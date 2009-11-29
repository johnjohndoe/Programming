#pragma once
#if !defined ( MP3DATA_H )
#define MP3DATA_H


#include <ostream>	// Only needed for print method.
#include <iostream>	// Only needed for print method.
#include <string>
#include "Helper.h"


/**
 * \class	MP3Data
 * \brief	Holds all metadata that make up the track.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
**/
class MP3Data
{

public:

	/// \brief	Default constructor.
	MP3Data( void);
	/// \brief	Destructor. 
	~MP3Data( void);

	// Setter
	void setIndex( int p_index);
	void setTitle( const char * p_title);
	void setArtist( const char * p_artist);
	void setAlbum( const char * p_album);
	void setYear( const char * p_year);
	void setTracknumber( const char * p_tracknumber);
	void setGenre( const char * p_genre);
	void setFilepath (const char * p_filepath);
	void setFilename (const char * p_filename);
	void setAll( const char * p_value);

	// Getter
	int getIndex( void);
	const char * getTitle( void);
	const char * getArtist( void);
	const char * getAlbum( void);
	const char * getYear( void);
	const char * getTracknumber( void);
	const char * getGenre( void);
	const char * getFilepath( void);
	const char * getFilename( void);

	// Print method offers to print to output stream, f.e. a file
	// Example: print( std::ofstream("..\\data\\mp3data.log"));
	// #include <ostream> where function call takes place.
	void print( std::ostream & os = std::cout);

private:
	
	/// \brief Stores the index position of the object in a sorted list.
	int index;
	const char * title;
	const char * artist;
	const char * album;
	const char * year;
	const char * tracknumber;
	const char * genre;
	const char * filepath;
	const char * filename;

	/// \brief The smaller than operator implements a lexical comparison.
	friend bool operator< ( const MP3Data & lhs, const MP3Data & rhs);
	/// \brief The greater than operator implements a lexical comparison.
	friend bool operator> ( const MP3Data & lhs, const MP3Data & rhs);
	/// \brief The equals operator implements a lexical comparison.
	friend bool operator== ( const MP3Data & lhs, const MP3Data & rhs);

};


// Comparision operators implementation.

inline bool operator< ( const MP3Data & lhs, const MP3Data & rhs)
{
	if( Helper::compareCaseSensitive( lhs.title, rhs.title) == Helper::SMALLER) return true;
	else return false;
}
inline bool operator> ( const MP3Data & lhs, const MP3Data & rhs)
{
	return operator< ( rhs, lhs);
}
inline bool operator== ( const MP3Data & lhs, const MP3Data & rhs)
{
	if( Helper::compareCaseSensitive( lhs.title, rhs.title) == Helper::EQUAL) return true;
	else return false;
}
inline bool operator!= ( const MP3Data & lhs, const MP3Data & rhs)
{
	return !operator== ( lhs, rhs);
}
inline bool operator<= ( const MP3Data & lhs, const MP3Data & rhs)
{
	return !operator> ( lhs, rhs);
}
inline bool operator>= ( const MP3Data & lhs, const MP3Data & rhs)
{
	return !operator< ( lhs, rhs);
}

#endif;
