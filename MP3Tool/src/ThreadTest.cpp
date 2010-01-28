#include <iostream>
#include <boost/thread.hpp>
#include "ThreadTest.h"
#include "Helper.h"
#include "TrackManager.h"
#include "TrackManagerFactory.h"



static void addSingleFile( TrackManager * p_trackManager, std::vector<std::string> & p_files, unsigned int fromIndex, unsigned int toIndex)
{
	if( toIndex > p_files.size())
	{
		std::cerr << "Thread: Error accessing file collection." << std::endl;
		return;
	}
	for( unsigned int i = fromIndex; i < toIndex; ++i)
	{
		CTrackInfo trackInformation;
		const char * fileName = p_files.at( i).c_str();
		std::cout << "Thread: Adding " << fileName << ". --> " << p_trackManager->addTrack( fileName, trackInformation) << std::endl;		
	}
}
static bool testAddSingleFileMultipleTimes( std::vector<std::string> * p_files)
{
	TrackManager * trackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	std::vector<boost::thread *> threadCollection;

	threadCollection.push_back( new boost::thread( addSingleFile, trackManager, *p_files, 0, 1));
	threadCollection.push_back( new boost::thread( addSingleFile, trackManager, *p_files, 1, 2));
	threadCollection.push_back( new boost::thread( addSingleFile, trackManager, *p_files, 0, 1));

	std::vector<boost::thread *>::iterator iterBegin = threadCollection.begin();
	std::vector<boost::thread *>::iterator iterEnd = threadCollection.end();
	for( iterBegin; iterBegin != iterEnd; ++iterBegin)
	{
		(*iterBegin)->join();
	}
	return true;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 


ThreadTest::ThreadTest( const char * p_path)
{
	files = Helper::getFiles( p_path);
	if( files == NULL)
	{
		std::cerr << "Error retrieving files." << std::endl;
		return;
	}
	std::cout << "Successfully read " << files->size() << " files." << std::endl;
}
ThreadTest::~ThreadTest(void)
{
	delete files;
}
void ThreadTest::processAllTests( void)
{
	// Todo: Call individual tests here. A test factory would be suitable also.
	testAddSingleFileMultipleTimes( files);
}