#pragma once
#include <string>
#include "MP3List.h"


class MP3Controller
{
public:
	MP3Controller(void);

	MP3List * myList;

	void addMP3(char* fPath);
	void removeMP3(int index);
	bool deleteTrack(int position); // Nimmt die Position aus der ListBox und löscht 
	// entsprechendes Element aus der SearchList und TrackList

	std::string* search(std::string* searchString); 
	




	~MP3Controller(void);

};
