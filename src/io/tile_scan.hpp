#ifndef SCAN_HPP
#define SCAN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <boost/algorithm/string.hpp>

typedef enum 
{
	UNKNOWNSY,
	ENUMSY,
	TERRAINSY,
	COVERSY,
	FLATSY,
	HILLSY,
	MOUNTAINSY,
	LAKESY,
	STREAMSY,
	RIVERSY,
	GRASSSY, 
	MARSHSY,
	WOODSY,
	FORESTSY,
	WALLSY,
	BUILDINGSY,
	LEFTBRACKETSY,
	RIGHTBRACKETSY,
	LEFTPARENTSY,
	RIGHTPARENTSY,
	COMMASY,
	LEFTSQUARESY,
	RIGHTSQUARESY,
	MAPSY,
	EQUALSY,
	INTCONST,
	EOFSY

} symbolclass;


class ReservedWords
{

public:

	typedef std::map< std::string, symbolclass > reserved_type;

	static const char ALPHA = 'a';
	static const char DIGIT = '0';

	ReservedWords()
	{
		reserved_["enum"] = ENUMSY;
		reserved_["terrain"] = TERRAINSY;
		reserved_["cover"] = COVERSY;
		reserved_["flat"] = FLATSY;
		reserved_["hill"] = HILLSY;
		reserved_["mountain"] = MOUNTAINSY;
		reserved_["lake"] = LAKESY;
		reserved_["stream"] = STREAMSY;
		reserved_["river"] = RIVERSY;
		reserved_["grass"] = GRASSSY;
		reserved_["marsh"] = MARSHSY;
		reserved_["wood"] = WOODSY;
		reserved_["forest"] = FORESTSY;
		reserved_["wall"] = WALLSY;
		reserved_["building"] = BUILDINGSY;
	}

	bool Exists( const std::string& key )
	{
		return 1 == reserved_.count( key );
	}

    symbolclass Get( const std::string& key )
	{
		if( Exists( key ) )
		{
			return reserved_[ key ];
		}
		return UNKNOWNSY;
	}

private:

	reserved_type	reserved_;

};

class TileScanner
{

public:

	TileScanner( const std::string& fileName )
		: index_( 0 ),
		  fileName_( fileName )
	{
		input_.open( fileName );
		getline( input_, line_ );
		boost::to_lower( line_ );
	}

	TileScanner()
	{
		input_.close();
	}

	int Input();
	void Unput();

	std::string GetToken()
	{
		return token_;
	}

	int NextSymbol();

private:

	int Class( int c );
	int index_;
	std::string line_;
	std::string token_;

	std::string fileName_;
	std::ifstream input_;

	ReservedWords	reserved_;

};


#endif

