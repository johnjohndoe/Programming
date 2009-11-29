#include "StdAfx.h"
#include "WordNode.h"
#include <stdlib.h>	// Needed for definition of NULL


WordNode::WordNode( void)
{
	WordNode( NULL, NULL);
}
WordNode::WordNode( const char * p_word, MP3Data * p_associate)
{
	wordData = new WordData( p_word, p_associate);
	next = NULL;
	prev = NULL;
}
WordNode::~WordNode( void)
{
	delete prev;
	delete next;
	delete wordData;
}
