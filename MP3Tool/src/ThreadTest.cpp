#include <iostream>
#include <boost/thread.hpp>
#include "ThreadTest.h"
#include "Helper.h"
#include "TrackManager.h"
#include "TrackManagerFactory.h"
#include <time.h>

static void join( std::vector<boost::thread *> & p_threadCollection)
{
	std::vector<boost::thread *>::iterator iterBegin = p_threadCollection.begin();
	std::vector<boost::thread *>::iterator iterEnd = p_threadCollection.end();
	for( iterBegin; iterBegin != iterEnd; ++iterBegin)
	{
		(*iterBegin)->join();
	}
}
static void addFile( TrackManager * p_trackManager, const char * p_file)
{
	CTrackInfo trackInformation;
	//std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Adding " << p_file << "." << std::endl;
	//std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Return value: " << p_trackManager->addTrack( p_file, trackInformation) << std::endl;
	p_trackManager->addTrack( p_file, trackInformation);

}
static void addFiles( TrackManager * p_trackManager, std::vector<std::string> & p_files, unsigned int fromIndex, unsigned int toIndex)
{
	if( toIndex > p_files.size())
	{
		std::cerr << "Thread Id " << boost::this_thread::get_id() << ": Error accessing file collection." << std::endl;
		return;
	}
	if( toIndex > p_files.size() + 1)
	{
		std::cerr << "Error: Exceeding file collection size." << std::endl;
		return;
	}
	for( unsigned int i = fromIndex; i < toIndex; ++i)
	{
		addFile( p_trackManager, p_files.at( i).c_str());
	}
}
static bool compare( TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	// Todo: Compare track manager lists.

	CTrackInfo * threadedTrackInfo = new CTrackInfo;
	CTrackInfo * unthreadedTrackInfo = new CTrackInfo;
	TSearchID threadedSearchId = INVALID_SEARCH_ID;
	TSearchID unthreadedSearchId = INVALID_SEARCH_ID;
	int threadedSearchLength = threadedTrackManager->trackSearchStart("", threadedSearchId);
	int unthreadedSearchLength = unthreadedTrackManager->trackSearchStart("", unthreadedSearchId);

	// Check Length
	if((threadedSearchLength == unthreadedSearchLength) && threadedSearchLength > 0)
	{
		// Get Tracks until nothing left
		while(threadedTrackManager->trackGetNext(threadedSearchId, * threadedTrackInfo) && (unthreadedTrackManager->trackGetNext(unthreadedSearchId, * unthreadedTrackInfo)))
		{
			// Compare titles
			if(Helper::compareCaseSensitive(threadedTrackInfo->mTitle.c_str() , unthreadedTrackInfo->mTitle.c_str()) != Helper::EQUAL)
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
static bool testAddSingleFileMultipleTimes( std::vector<std::string> * p_files, TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	std::cout << "Test 1: Insert different Files and also one File more than once:" << std::endl;

	std::vector<boost::thread *> threadCollection;


	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 0, 1));
	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 1, 2));
	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 0, 1));

	join( threadCollection);

	// Add Files without MultiThread
	CTrackInfo * tempTrackInfo = new CTrackInfo;
	unthreadedTrackManager->addTrack(p_files->at(0), * tempTrackInfo);
	unthreadedTrackManager->addTrack(p_files->at(1), * tempTrackInfo);
	unthreadedTrackManager->addTrack(p_files->at(0), * tempTrackInfo);
	if( tempTrackInfo != NULL) delete tempTrackInfo;

	return compare( threadedTrackManager, unthreadedTrackManager);
}
static bool testAddMultipleFiles( std::vector<std::string> * p_files, TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	// Initialize random seed.
	srand ( (unsigned int) time( NULL));
	// Random index. Possible values are zero till files size.
	unsigned int randomIndex = rand() % p_files->size();
	
	CTrackInfo * trackInformation = new CTrackInfo;
	std::vector<boost::thread *> threadCollection;

	// Add as many times files as files size. This allows duplicate files.
	unsigned int countIndex = 0;
	while( countIndex < p_files->size())
	{
		const char * file = p_files->at( randomIndex).c_str();
		// Add file to reference list. Sequentially.
		unthreadedTrackManager->addTrack( file, * trackInformation);
		// Add file to test list. Threaded.
		threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, randomIndex, randomIndex + 1));
		// threadedTrackManager->addTrack(file, * trackInformation);
		countIndex++;
		randomIndex = rand() % p_files->size();
	}
	
	join( threadCollection);
	
	return compare( threadedTrackManager, unthreadedTrackManager);
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
	if( files != NULL) delete files;
}
void ThreadTest::processAllTests( void)
{

	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();


	// Todo: Call individual tests here. A test factory would be suitable also.
	if( testAddSingleFileMultipleTimes( files, threadedTrackManager, unthreadedTrackManager))
	{
		std::cout << "Test 1 passed." << std::endl;
	}
	else
	{
		std::cout << "Test 1 failed" << std::endl;
	}
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;

	// ---------------------------

	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();

	if( testAddMultipleFiles( files, threadedTrackManager, unthreadedTrackManager))
	{
		std::cout << "Test 2 passed." << std::endl;
	}
	else
	{
		std::cout << "Test 2 failed" << std::endl;
	}
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;

}