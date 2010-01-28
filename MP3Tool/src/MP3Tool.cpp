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
#include "stdafx.h"
#include "boost/thread.hpp"
#include "boost/thread/mutex.hpp"
#include "ThreadTest.h"


boost::mutex io_mutex;


struct count
{
  count(int id) : id(id) { }
  void operator()()
  {
    for (int i = 0; i < 10; ++i)
    {
      boost::mutex::scoped_lock lock(io_mutex);
      std::cout << id << ": " << i << std::endl;
    }
  }
  int id;
};



int main( int argc, char* argv[])
{
	/*
	if( argc < 2)
	{
		std::cout << "Please enter the path as the 1. argument for the executable." << std::endl;
		return 1;
	}
	*/
	std::string dummyPath = "C:\\01_MP3Test";	
	//ThreadTest myThreadTest( argv[ 1]);
	ThreadTest myThreadTest( dummyPath.c_str());



	boost::thread thrd1(count(0));

	thrd1.join();


	return 0;

} // eo main

