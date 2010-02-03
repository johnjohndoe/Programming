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
	std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Adding " << p_file << "." << std::endl;
	std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Return value: " << p_trackManager->addTrack( p_file, trackInformation) << std::endl;		

}
static void addFiles( TrackManager * p_trackManager, std::vector<std::string> & p_files, unsigned int fromIndex, unsigned int toIndex)
{
	if( toIndex > p_files.size())
	{
		std::cerr << "Thread Id " << boost::this_thread::get_id() << ": Error accessing file collection." << std::endl;
		return;
	}
	for( unsigned int i = fromIndex; i <= toIndex; ++i)
	{
		addFile( p_trackManager, p_files.at( i).c_str());
	}
}
static bool testAddSingleFileMultipleTimes( std::vector<std::string> * p_files)
{
	std::cout << "Test 1: Insert differnt Files and also one File more than once:" << std::endl;

	TrackManager * testTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	TrackManager * referenceTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	std::vector<boost::thread *> threadCollection;


	threadCollection.push_back( new boost::thread( addFiles, testTrackManager, *p_files, 0, 1));
	threadCollection.push_back( new boost::thread( addFiles, testTrackManager, *p_files, 1, 2));
	threadCollection.push_back( new boost::thread( addFiles, testTrackManager, *p_files, 0, 1));

	join( threadCollection);

	// Add Files without MultiThread

	CTrackInfo * r_trackInfo = new CTrackInfo;
	CTrackInfo * r_trackInfoCmpr = new CTrackInfo;
	referenceTrackManager->addTrack(p_files->at(0), * r_trackInfo);
	referenceTrackManager->addTrack(p_files->at(1), * r_trackInfo);
	referenceTrackManager->addTrack(p_files->at(0), * r_trackInfo);

	TSearchID threadedSearchId = -1;
	TSearchID serialSearchId = -1;
	int threadedSearchLength = testTrackManager->trackSearchStart("", threadedSearchId);
	int serialSearchLength = referenceTrackManager->trackSearchStart("", serialSearchId);

	// Check Length
	if((threadedSearchLength == serialSearchLength) && threadedSearchLength > 0)
	{
		// Get Tracks until nothing left
		while(testTrackManager->trackGetNext(threadedSearchId, * r_trackInfo) && (referenceTrackManager->trackGetNext(threadedSearchId, * r_trackInfoCmpr)))
		{
			// Compare titles
			if(Helper::compareCaseSensitive(r_trackInfo->mTitle.c_str() , r_trackInfoCmpr->mTitle.c_str()) != Helper::EQUAL)
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
static bool testAddMultipleFiles( std::vector<std::string> * p_files)
{
	TrackManager * testTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	TrackManager * referenceTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	
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
		std::cout << " Random: " << randomIndex << std::endl;
		std::cout << "Datei eins: " <<  p_files->at(randomIndex) << std::endl;
		// Add file to reference list. Sequentially.
		referenceTrackManager->addTrack( file, * trackInformation);
		// Add file to test list. Threaded.
		threadCollection.push_back( new boost::thread( addFiles, testTrackManager, *p_files, randomIndex, randomIndex));
		// testTrackManager->addTrack(file, * trackInformation);
		countIndex++;
		randomIndex = rand() % p_files->size();
	}
	
	join( threadCollection);
	

	// Todo: Compare track manager lists.

	CTrackInfo * r_trackInfo = new CTrackInfo;
	CTrackInfo * r_trackInfoCmpr = new CTrackInfo;
	TSearchID threadedSearchId = -1;
	TSearchID serialSearchId = -1;
	int threadedSearchLength = testTrackManager->trackSearchStart("", threadedSearchId);
	int serialSearchLength = referenceTrackManager->trackSearchStart("", serialSearchId);

	// Check Length
	if((threadedSearchLength == serialSearchLength) && threadedSearchLength > 0)
	{
		// Get Tracks until nothing left
		while(testTrackManager->trackGetNext(threadedSearchId, * r_trackInfo) && (referenceTrackManager->trackGetNext(threadedSearchId, * r_trackInfoCmpr)))
		{
			// Compare titles
			if(Helper::compareCaseSensitive(r_trackInfo->mTitle.c_str() , r_trackInfoCmpr->mTitle.c_str()) != Helper::EQUAL)
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
	//if(testAddSingleFileMultipleTimes( files))
	//{std::cout << "Test 1 passed." << std::endl;}
	//else
	//{std::cout << "Test One failed" << std::endl;}
	
	if(testAddMultipleFiles( files))
	{std::cout << "Test 2 passed." << std::endl;}
	else
	{std::cout << "Test One failed" << std::endl;}



}