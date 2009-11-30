#include "StdAfx.h"
#include <iostream>
#include "Node.h"


Node::Node( void)
: data( NULL), next( NULL), prev( NULL)
{
}
Node::~Node( void)
{
	delete prev;
	delete next;
	delete data;
}
