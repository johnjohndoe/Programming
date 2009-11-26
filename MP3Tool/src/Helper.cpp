#include "StdAfx.h"
#include "Helper.h"
#include <stdlib.h>	// Needed for definition of NULL


unsigned int Helper::length( const char * c)
{
	unsigned int i = 0;
	while ( c[i] != NULL)
		i++;
	return i;
}
// Note: Do not forget to dereference the objects before you hand them 
// over to the function. Otherwise the pointer addresses are compared.
// @TODO: Compare case insensitive
int Helper::compareCaseSensitive( const char * lhs, const char * rhs)
{
	unsigned int lengthLhs = Helper::length( lhs);
	unsigned int lengthRhs = Helper::length( rhs);
	unsigned int min = ( lengthLhs > lengthRhs) ? lengthLhs : lengthRhs;

	for( unsigned int i=0; i < min; ++i)
	{
		unsigned int clhs = lhs[i];
		unsigned int crhs = rhs[i];
		if( clhs != crhs)
		{
			if( clhs < crhs) return SMALLER;
			else return GREATER;
		}
		else if( i == min-1)
		{
			if( lengthLhs == lengthRhs)	return EQUAL;
			else if( lengthLhs < lengthRhs)	return SMALLER;
			else return GREATER;
		}
	}
}