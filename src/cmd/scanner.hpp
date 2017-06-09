#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>

#include "scan.h"
#include "parser.hpp"


class Scanner
{

public:

	const static int ALPHA = 'a';
	const static int DIGIT = '0';

	Scanner( std::istream& in )
		: ifstream_( in )
	{}

	int Class( int c )
	{
		if( isalpha( c ) )
		{
			return ALPHA;
		}
		if( isdigit( c ) )
		{
			return DIGIT;
		}
		return c;
	}

	symbolclass NextToken()
	{
		int c = ifstream_.get();

		token_.clear();

		while( c != EOF )
		{
			switch( Class( c ) )
			{
				case ' ':
				case '\t':
				case '\n':
					c = ifstream_.get();	
					break;

				case ALPHA:
					for( int j = 0; isalpha( c ); ++j )
					{
						token_.push_back( c );
						c = ifstream_.get();	
					}
					token_.push_back( '\0' );
					ifstream_.unget();
					return WORD;
					break;

				case DIGIT:
					for( int j = 0; isdigit( c ); ++j )
					{
						token_.push_back( c );
						c = ifstream_.get();	
					}	
					token_.push_back( '\0' );
					ifstream_.unget();
					return INTEGER;
					break;

				case '.':
					return PERIOD;
					break;
			}
		}
		return EOFSY;
	}

	std::string GetToken()
	{
		return token_;
	}

private:

	std::istream&	ifstream_;
	std::string		token_;

};

#endif

