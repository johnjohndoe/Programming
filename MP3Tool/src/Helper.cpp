#include "StdAfx.h"
#include <iostream>
#include <exception>
#include <cctype>
#include <stdlib.h>	// Needed for definition of NULL
#include "Helper.h"


unsigned int Helper::length( const char * c)
{
	if( c == NULL) return 0;
	unsigned int i = 0;
	while ( c[i] != NULL)
		i++;
	return i;
}
// Note: Do not forget to dereference the objects before you hand them 
// over to the function. Otherwise the pointer addresses are compared.
int Helper::compareCaseSensitive( const char * lhs, const char * rhs)
{
	unsigned int lengthLhs = Helper::length( lhs);
	unsigned int lengthRhs = Helper::length( rhs);

	if( lengthLhs == 0 || lengthRhs == 0)
	{	
		throw "Error: Helper::length(), Character object has length zero.";
		exit( -1);
	}

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
void Helper::toLowerCase(std::string &str)
{
	const int length = str.length();
	for(int i=0; i < length; ++i)
	{
		str[i] = std::tolower(str[i]);
	}
}
std::vector<std::string> * Helper::getFiles( const char * p_path)
{
	// The collection to store the files in.
	std::vector<std::string> * files = NULL;

	// Build a fully qualified path. 
	boost::filesystem::path relativePath( p_path);
	boost::filesystem::path absolutePath = boost::filesystem::system_complete( relativePath);

	// Return the empty collection if the file system bars access.
	if( !boost::filesystem::exists( absolutePath)) return files;
	if( !boost::filesystem::is_directory( absolutePath)) return files;

	files = new std::vector<std::string>();

	// Collect files from directory.
	boost::filesystem::directory_iterator current( absolutePath);
	boost::filesystem::directory_iterator last;
	for( current; current != last; ++current)
	{
		if ( !boost::filesystem::is_directory( current->status() ) )
		{
			files->push_back( current->path().string());
		}
	}
	return files;
}