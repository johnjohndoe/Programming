#pragma once
#if !defined ( MP3CONTROLLER_H )
#define MP3CONTROLLER_H

#include <string>
#include "MP3List.h"
#include "NodeList.h"
#include "MP3Data.h"
#include "MP3DataGenerator.h"


class MP3Controller
{
public:
	MP3Controller(void);

	MP3List * myList;
	NodeList * trackList;
	MP3Data * tempMP3Data;
	MP3DataGenerator * myGenerator;

	void addMP3(const char* fPath);

	void removeMP3(int index);
	bool deleteTrack(int position); 

	const char* search(const char* searchString); 
	
	MP3Data* getFirst(void);
	MP3Data* getNext(void);
	bool hasNext(void);
	void print(void);
	




	~MP3Controller(void);

};
#endif;