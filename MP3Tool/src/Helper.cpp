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
	return NULL; // error
}
void Helper::tokenize( const std::string & str, std::vector<std::string> & tokens, const std::string & delimiters)
{
	// Skip delimiters at beginning.
	std::string::size_type lastPos = str.find_first_not_of( delimiters, 0);
	// Find first "non-delimiter".
	std::string::size_type pos = str.find_first_of( delimiters, lastPos);

	while( std::string::npos != pos || std::string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		tokens.push_back( str.substr( lastPos, pos - lastPos));
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of( delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of( delimiters, lastPos);
	}
}
