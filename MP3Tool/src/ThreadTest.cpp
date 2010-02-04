#include <iostream>
#include <boost/thread.hpp>
#include "ThreadTest.h"
#include "Helper.h"
#include "TrackManager.h"
#include "TrackManagerFactory.h"
#include <time.h>
#include <vector>
#include <ctype.h>



static void join( std::vector<boost::thread *> & p_threadCollection)
{
	std::vector<boost::thread *>::iterator iterBegin = p_threadCollection.begin();
	std::vector<boost::thread *>::iterator iterEnd = p_threadCollection.end();
	for( iterBegin; iterBegin != iterEnd; ++iterBegin)
	{
		(*iterBegin)->join();
	}
}
static CTrackInfo * addFile( TrackManager * p_trackManager, const char * p_file)
{
	CTrackInfo * trackInformation = new CTrackInfo();
	//std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Adding " << p_file << "." << std::endl;
	//std::cout << "Thread Id " << boost::this_thread::get_id() << " ___ Return value: " << p_trackManager->addTrack( p_file, trackInformation) << std::endl;
	int index = p_trackManager->addTrack( p_file, *trackInformation);
	//if( index != INVALID_INDEX) std::cout << "Threaded adding, index: " << trackInformation->mIndex << std::endl;
	//else std::cout << "Threaded adding, file already contained." << std::endl;
	return trackInformation;
}

static bool removeFile( TrackManager * p_trackManager, int index)
{
	bool result = p_trackManager->removeTrack( index);
	//std::cout << "Threaded remove: " << result << std::endl;
	return result;
}

std::string StringToLower(std::string strToConvert)
{//change each element of the string to lower case
   for(unsigned int i=0;i<strToConvert.length();i++)
   {
      strToConvert[i] = tolower(strToConvert[i]);
   }
   return strToConvert;//return the converted string
} 

static bool searchFile( TrackManager * p_trackManager, std::string searchTitle)
{
	CTrackInfo * tempTrackInfo = new CTrackInfo;
	TSearchID searchID = INVALID_SEARCH_ID;
	std::string searchString = StringToLower(searchTitle.substr(0,1));
	int searchLength = p_trackManager->trackSearchStart(searchString, searchID);
	std::cout << "Method for searchFile - search for "  << searchString << " SearchLength: " << searchLength << std::endl;
	for( int i = 0; i < searchLength; i++)
	{
		p_trackManager->trackGetNext(searchID, * tempTrackInfo);
		std::cout << boost::this_thread::get_id() << " " << tempTrackInfo->mTitle << std::endl;
	}
	return true;
}

static std::vector<CTrackInfo *> * addFiles( TrackManager * p_trackManager, std::vector<std::string> & p_files, unsigned int fromIndex, unsigned int toIndex)
{
	if( toIndex > p_files.size())
	{
		std::cerr << "Thread Id " << boost::this_thread::get_id() << ": Error accessing file collection." << std::endl;
		return NULL;
	}
	if( toIndex > p_files.size() + 1)
	{
		std::cerr << "Error: Exceeding file collection size." << std::endl;
		return NULL;
	}
	std::vector<CTrackInfo *> * trackInformation = new std::vector<CTrackInfo *>();
	std::vector<CTrackInfo *>::iterator iterTI = trackInformation->begin();
	for( unsigned int i = fromIndex; i < toIndex; ++i)
	{
		CTrackInfo * current = addFile( p_trackManager, p_files.at( i).c_str());
		if( current) trackInformation->insert( iterTI, current);
		else std::cerr << "Error: Retrieved CTrackInfo is empty." << std::endl;
	}
	return trackInformation;
}
static bool compare( TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	// Todo: Compare track manager lists.
	std::cout << "Method: compare" << std::endl;
	CTrackInfo * threadedTrackInfo = new CTrackInfo;
	CTrackInfo * unthreadedTrackInfo = new CTrackInfo;
	TSearchID threadedSearchId = INVALID_SEARCH_ID;
	TSearchID unthreadedSearchId = INVALID_SEARCH_ID;
	int threadedSearchLength = threadedTrackManager->trackSearchStart("", threadedSearchId);
	int unthreadedSearchLength = unthreadedTrackManager->trackSearchStart("", unthreadedSearchId);

	// Check Length
	if(threadedSearchLength == unthreadedSearchLength)
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
	std::cout << "Method: compare - END" << std::endl;
	return true;
}
static bool testAddSingleFileMultipleTimes( std::vector<std::string> * p_files, TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	std::cout << "Method: testAddSingleFileMultipleTimes" << std::endl;
	std::cout << "Insert different files and also one file more than once." << std::endl;

	std::vector<boost::thread *> threadCollection;
	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 0, 1));
	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 1, 2));
	threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, 0, 1));

	join( threadCollection);

	// Add Files without MultiThread
	CTrackInfo * tempTrackInfo = new CTrackInfo;
	unthreadedTrackManager->addTrack(p_files->at(0), *tempTrackInfo);
	unthreadedTrackManager->addTrack(p_files->at(1), *tempTrackInfo);
	unthreadedTrackManager->addTrack(p_files->at(0), *tempTrackInfo);
	if( tempTrackInfo != NULL) delete tempTrackInfo;

	return compare( threadedTrackManager, unthreadedTrackManager);
}
static bool testAddMultipleFiles( std::vector<std::string> * p_files, TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager, std::vector<int> * trackIndices)
{
	std::cout << "Method: testAddMultipleFiles" << std::endl;

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
		int trackIndex = unthreadedTrackManager->addTrack( file, *trackInformation);
		// Add the valid track index to the collection.
		if( trackIndices != NULL && trackIndex != INVALID_INDEX) trackIndices->push_back( trackIndex);
		// Add file to test list. Threaded.
		threadCollection.push_back( new boost::thread( addFiles, threadedTrackManager, *p_files, randomIndex, randomIndex + 1));
		// threadedTrackManager->addTrack(file, * trackInformation);
		countIndex++;
		randomIndex = rand() % p_files->size();
	}
	
	join( threadCollection);
	std::cout << "Method: testAddMultipleFiles - END" << std::endl;
	return compare( threadedTrackManager, unthreadedTrackManager);
}



static bool testRemoveSingleFiles( std::vector<std::string> * p_files, TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager, std::vector<int> * trackIndices)
{
	std::cout << "Method: testDeleteSingleFiles" << std::endl;

	if( trackIndices == NULL)
	{
		std::cerr << "Error: No track indices available." << std::endl;
		return false;
	}

	std::vector<boost::thread *> threadCollection;
	// Fülle die TrackManager mit mehreren Dateien und dann löscht Random eine Datei aus dem TrackManager und Füge Random wieder eine Datei hinzu

	testAddMultipleFiles( p_files, threadedTrackManager, unthreadedTrackManager, NULL);
	// Initialize random seed.
	srand ( (unsigned int) time( NULL));
	// Random index. Possible values are zero till files size.

	TSearchID unthreadedSearchID = INVALID_SEARCH_ID;
	CTrackInfo * tempTrackInfo = new CTrackInfo;

	// Lösche Maximal 3 Dateien
	for( unsigned int i = 0; i < 3; i++)
	{
		unsigned int randomIndex = rand() % trackIndices->size();
		unsigned int tempTrackIndex = trackIndices->at(randomIndex);
		threadCollection.push_back( new boost::thread( removeFile, threadedTrackManager, tempTrackIndex));
		unthreadedTrackManager->removeTrack(tempTrackIndex);		
	}

	join(threadCollection);

	// Speichere das Suchergebiss in einen Vector und vergleiche diesen Vector

	return compare(threadedTrackManager, unthreadedTrackManager);

}
static void printTrackInformation( std::vector<CTrackInfo *> * trackInformationCollection)
{
	if( trackInformationCollection == NULL)
	{
		std::cerr << "Error: No track information available for printing." << std::endl;
		return;
	}
	for( unsigned int i = 0; i < trackInformationCollection->size(); ++i)
	{
		CTrackInfo * ti = trackInformationCollection->at( i);
		std::cout << ti->mTitle << std::endl;
	}
}
static void testSearchFile( TrackManager * threadedTrackManager, TrackManager * unthreadedTrackManager)
{
	std::cout << "Method: testSearchFile" << std::endl;
	TSearchID sId = INVALID_SEARCH_ID;
	int searchLength = threadedTrackManager->trackSearchStart( "", sId);
	
	// Fill vector of CTrackInfo.
	std::vector<CTrackInfo *> * trackInformationCollection = new std::vector<CTrackInfo *>();

	CTrackInfo * ti = NULL;
	bool hasNext = false;
	for(int i = 0; i < searchLength; i++)
	{
		ti = new CTrackInfo();
		hasNext = unthreadedTrackManager->trackGetNext( sId, *ti);
		// std::cout << ti->mTitle << std::endl;
		trackInformationCollection->push_back(ti);
	}
	std::cout << "Groesse des TrackInfo-Vectors: " << trackInformationCollection->size() << std::endl;
	

	//printTrackInformation( trackInformationCollection);
	
	// Pick title from vector.
	std::vector<boost::thread *> threadCollection;
	srand ( (unsigned int) time( NULL));
	for(int i = 0; i < 3; i++)
	{	
		unsigned int randomIndex = rand() % trackInformationCollection->size();
		threadCollection.push_back( new boost::thread( searchFile, threadedTrackManager, trackInformationCollection->at(randomIndex)->mTitle));
	}
	std::cout << "Method: testSearchFile - END" << std::endl;
	join(threadCollection);


	// Multiple threaded search in threadedTrackManager.

	
	
	// Output CTrackInfo results from threaded search.



	// Delete TrackInfos
	for(unsigned int i = 0; i < trackInformationCollection->size(); i++)
	{
		if(trackInformationCollection->at(i) != NULL) delete trackInformationCollection->at(i);
	}
	if(trackInformationCollection != NULL) delete trackInformationCollection;
	
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
	std::cout << "Successfully read " << files->size() << " files.\n\n" << std::endl;
}


ThreadTest::~ThreadTest(void)
{
	if( files != NULL) delete files;
}
void ThreadTest::processAllTests( void)
{
/*
	// ----------- Test 1 ---------------- Add single file multiple times.

	std::cout << "TEST 1 START" << std::endl;
	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();

	if( testAddSingleFileMultipleTimes( files, threadedTrackManager, unthreadedTrackManager))
	{
		std::cout << "Test 1 passed." << std::endl;
	}
	else
	{
		std::cerr << "Test 1 failed." << std::endl;
	}
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;
	std::cout << "TEST 1 FINISH\n\n" << std::endl;


	// ----------- Test 2 ---------------- Add multiple different files. Multiple files per thread.

	std::cout << "TEST 2 START" << std::endl;
	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();

	if( testAddMultipleFiles( files, threadedTrackManager, unthreadedTrackManager, NULL))
	{
		std::cout << "Test 2 passed." << std::endl;
	}
	else
	{
		std::cerr << "Test 2 failed." << std::endl;
	}
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;
	std::cout << "TEST 2 FINISH\n\n" << std::endl;

	
	// --------- Test 3 ------------------
*/
/*
	std::cout << "TEST 3 START" << std::endl;
	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	testAddMultipleFiles( files, threadedTrackManager, unthreadedTrackManager, NULL);
	if( testReadMultibleFiles(files, threadedTrackManager, unthreadedTrackManager) )
	{
		std::cout << "Test 3 passed." << std::endl;
	}
	else
	{
		std::cerr << "Test 3 failed." << std::endl;
	}
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;
	std::cout << "TEST 3 FINISH\n\n" << std::endl;
*/



	// --------- Test 4 ------------------ Add and remove files.
/*
	std::cout << "TEST 4 START" << std::endl;
	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	std::cout << "Fuellen der TrackManager" << std::endl;


	std::vector<int> * trackIndices = new std::vector<int>();
	testAddMultipleFiles( files, threadedTrackManager, unthreadedTrackManager, trackIndices);

	std::cout << "Loeschen eines Eintrages aus dem TrackManager" << std::endl;
	if( testRemoveSingleFiles( files, threadedTrackManager, unthreadedTrackManager, trackIndices))
	{
		std::cout << "Test 4 passed." << std::endl;
	}
	else
	{
		std::cerr << "Test 4 failed." << std::endl;
	}
	if( trackIndices != NULL) delete trackIndices;
	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;	
	std::cout << "TEST 4 FINISH\n\n" << std::endl;
*/


	// --------- Test 5 ------------------ Add and remove files.

	std::cout << "TEST 5 START" << std::endl;
	threadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();
	unthreadedTrackManager = (TrackManager *) TrackManagerFactory::getTrackManager();

	testAddMultipleFiles( files, threadedTrackManager, unthreadedTrackManager, NULL);
	testSearchFile( threadedTrackManager, unthreadedTrackManager);

	if( threadedTrackManager != NULL) delete threadedTrackManager;
	if( unthreadedTrackManager != NULL) delete unthreadedTrackManager;	
	std::cout << "TEST 5 FINISH\n\n" << std::endl;

}