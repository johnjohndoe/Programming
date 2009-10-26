#include "StdAfx.h"
#include "MP3Container.h"
#include "MP3Connector.h"
#include <set>


// Constructor
MP3Container::MP3Container( void)
{
	mySet = new std::set<MP3Connector*>();
}

// Destructor
MP3Container::~MP3Container( void)
{
}




void MP3Container::add(const char* pathString)
{
	MP3Connector* myCon = new MP3Connector(pathString);
	mySet->insert(myCon);
}

//MP3Connector MP3Container::getIterator()