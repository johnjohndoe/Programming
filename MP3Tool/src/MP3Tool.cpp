/**
 * \file	src\MP3Tool.cpp
 *
 * \brief	Main project file.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 *
**/

#define BOOST_FILESYSTEM_NO_DEPRECATED

#include <iostream>
#include <string>
#include "ITrackManager.h"
#include "TrackManagerFactory.h"
#include "stdafx.h"
#include "boost/thread.hpp"
#include "boost/thread/mutex.hpp"
#include "ThreadTest.h"
#include "TrackManager.h"

#include <vector>


boost::mutex io_mutex;


void addTrackWithoutThread(TrackManager * trckMngr, const std::string file)
{
	CTrackInfo * trackInfo = new CTrackInfo;
	trckMngr->addTrack(file, *trackInfo);
}

void addTrackWithThread(TrackManager * trckMngr, std::string file)
{
	CTrackInfo * trackInfo = new CTrackInfo;
	trckMngr->addTrack(file, *trackInfo);
}

void testOne(TrackManager * trckMngr, TrackManager * trckMngrCmpr,  vector<const std::string> * musicFiles)
{
	
	std::string * t_filename = new std::string("");;
	// Erstellen von zwei Trackmanaer
	for( unsigned i=0; i<musicFiles->size(); i++ )
    {
		// Diesen Vorgang in einen Thread auslagern
		addTrackWithThread(trckMngr, musicFiles->at(i));
		// Das selbe ohne Thread in einen zweiten Manager einfügen
		addTrackWithoutThread(trckMngrCmpr, musicFiles->at(i));

		std::cout << "Hinzugefügt + "  << std::endl;

	}
	
	// Ausgabe ob vergleich Funktioniert hat
	if (trckMngr->isEqual(trckMngrCmpr))
	{
		std::cout << "Die beiden Listen sind gleich" << std::endl;
	}
	else
	{
		std::cout << "Die beiden Listen sind ungleich" << std::endl;
	}
}

int main( int argc, char* argv[])
{

	//vector<const std::string> * musicFiles = new vector<const std::string>;
	//musicFiles->push_back("c:\\a3b.mp3");
	//musicFiles->push_back("c:\\a3a.mp3");
	//musicFiles->push_back("c:\\a4.mp3");
	//musicFiles->push_back("c:\\a4-2.mp3");
	
	ThreadTest * t_test = new ThreadTest("c:\\");
	t_test->processAllTests();


	//boost::thread thrd1(count2(0));
	//thrd1.join();

	return 0;

} // eo main
