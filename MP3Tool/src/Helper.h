#pragma once
#if !defined ( HELPER_H )
#define HELPER_H


//#define BOOST_FILESYSTEM_NO_DEPRECATED // Deprecated features are excluded.
#include <string>
#include <vector>
#include <boost/filesystem.hpp>


/**
 * \class	Helper
 * \brief	Offers static methods to process strings.
 * \author	Tobias Preuss (s0516424) & Alexander Kramer (s0516343)
**/
class Helper
{

public:

	/// \brief Holds a human readable expression for the result of the lexical comparison.
	enum LexicalOrder { NULLNULL, SMALLER, EQUAL, GREATER};
	/// \brief Returns the number of elements stored in the referenced character array.
	static unsigned int length( const char * c);
	/// \brief Returns the lexical order of the elements in regards to the first parameter.
	static int compareCaseSensitive( const char * lhs, const char * rhs);
	/// \brief Splits a string into separate words and stores them in the supplied container.
	static void tokenize( const std::string & str, std::vector<std::string> & tokens, const std::string & delimiters = " ");
	/// \brief Convert a string to lower case
	static void toLowerCase(std::string & str);
	/// \brief Returns a collection of file paths.
	static std::vector<std::string> * getFiles( const char * p_path);

private:

	/// \brief	Default constructor.
	Helper( void);
	/// \brief	Destructor.
	~Helper( void);
};

#endif;