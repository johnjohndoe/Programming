/**
 * \file	src\MP3Tool.cpp
 *
 * \brief	Main project file.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
 *
**/

#define BOOST_FILESYSTEM_NO_DEPRECATED

#include <iostream>
#include "boost/thread/mutex.hpp"
#include "stdafx.h"
//#include "MP3ToolGUI.h"
#include "pthread.h"
#include "boost/thread.hpp"

boost::mutex io_mutex;
// using namespace MP3Tool;

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

	boost::thread thrd1(count(0));

	thrd1.join();


	return 0;

} // eo main

