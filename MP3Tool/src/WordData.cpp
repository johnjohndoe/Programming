#include "StdAfx.h"
#include "WordData.h"


WordData::WordData( const char * p_word, MP3Data * p_associate)
: word( p_word)
{
	associates = new NodeList();
	associates->insert( p_associate);
}
WordData::~WordData( void)
{
	delete associates;
}