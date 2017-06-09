#ifndef TILE_PARSER_HPP
#define TILE_PARSER_HPP

#include <map>
#include <vector>

#include "tile_scan.hpp"

class Tile
{

public:

	Tile( int id )
		: id_( id )
	{}

	void AddTerrain( int terrain )
	{
		terrain_.push_back( terrain );
	}

	void AddCover( int cover )
	{
		cover_.push_back( cover );
	}

	int GetId()
	{
		return id_;
	}

	std::vector<int> GetTerrain()
	{
		return terrain_;
	}

	std::vector<int> GetCover()
	{
		return cover_;
	}

private:

	int id_;

	std::vector<int> terrain_;
	std::vector<int> cover_;

};



class TileParser
{

	typedef std::map< std::string, int > enum_type;
	typedef std::map< std::string, enum_type > enum_data;

	typedef std::map< int, Tile > tile_data;

	typedef std::vector< std::vector< int > > map_type;

public:

	TileParser( const std::string& fileName )
		: scanner_( fileName )
	{}

	void Parse();

private:

	void AddEnum();
	void AddTile();

	TileScanner scanner_;

	map_type	map_;
	
};

#endif

