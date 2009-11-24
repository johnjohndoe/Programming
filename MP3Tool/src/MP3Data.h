#pragma once

#include <string>
#include <map>
class MP3Data
{
public:
	MP3Data(void);
	//void populate(const std::map<ID3_FrameID, std::string>*);
	

	std::string getInterpret(void);
	std::string getTitle(void);
	std::string getAlbum(void);
	int getTrack(void);
	int getYear(void);
	std::string getGenre(void);

	void setTitle(std::string);
	void setInterpret(std::string);
	void setAlbum(std::string);
	void setTrack(int);
	void setYear(int);
	void setGenre(std::string);

	//void printOut(void);
	~MP3Data(void);

private:
	std::string title; 
	std::string interpret;
	std::string album;
	int year; 
	int track;
	std::string genre;

};
