#pragma once
#if !defined ( THREADTEST_H )
#define THREADTEST_H


#include <vector>
#include <string>
#include "TrackManager.h"


/**
 * \class	ThreadTest
 * \brief	Runs a various set of tests.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
**/
class ThreadTest
{

public:

	/// \brief Default constructor.
	ThreadTest( const char * p_path);
	/// \brief Destructor.
	~ThreadTest( void);
	/// \brief Processes all tests.
	void processAllTests( void);

private:

	/// \brief Stores the test files.
	std::vector<std::string> * files;
	/// \brief Processes the threaded information.
	TrackManager * threadedTrackManager;
	/// \brief Processes the unthreaded information.
	TrackManager * unthreadedTrackManager;

};

#endif