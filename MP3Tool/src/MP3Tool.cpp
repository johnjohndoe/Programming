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
#include "ThreadTest.h"
#include "TrackManager.h"



int main( int argc, char* argv[])
{	
	ThreadTest * t_test = new ThreadTest("c:\\mp3\\");
	t_test->processAllTests();
	return 0;

} // eo main
