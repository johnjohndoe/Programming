#include "StdAfx.h"
#include "MP3Data.h"
#include <iostream>

MP3Data::MP3Data(void)
{
}
	//Getter
	std::string MP3Data::getTitle(void)
	{
		return this->title;
	}
	std::string MP3Data::getInterpret(void)
	{
		return this->interpret;
	}
	std::string MP3Data::getAlbum(void)
	{
		return this->album;
	}
	int MP3Data::getTrack(void)
	{
		return this->track;
	}
	int MP3Data::getYear(void)
	{
		return this->year;
	}
	std::string MP3Data::getGenre(void)
	{
		return this->genre;
	}


// Setter
	void MP3Data::setTitle(std::string title)
	{
		this->title = title;
	}

	void MP3Data::setInterpret(std::string interpret)
	{
		this->interpret = interpret;
	}
	void MP3Data::setAlbum(std::string album)
	{
		this->album = album;
	}
	void MP3Data::setTrack(int track)
	{
		this->track = track;
	}
	void MP3Data::setYear(int year)
	{
		this->year = year;
	}
	void MP3Data::setGenre(std::string genre)
	{
		this->genre = genre;
	}

	//void MP3Data::printOut(void)
	//{
	//	std::cout << "Bla Bla Bla " << this->title << std::endl;
	//}


MP3Data::~MP3Data(void)
{
}
