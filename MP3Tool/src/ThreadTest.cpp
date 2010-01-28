#include <iostream>
#include "ThreadTest.h"
#include "Helper.h"



ThreadTest::ThreadTest( const char * p_path)
{
	files = Helper::getFiles( p_path);
	std::cout << "Successfully read " << files.size() << " files." << std::endl;
}
ThreadTest::~ThreadTest(void)
{
	// Nothing to destroy.
}
void ThreadTest::processAllTests( void)
{
	// Todo: Call individual tests here. A test factory would be suitable also.
}