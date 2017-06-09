#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>

#include "file_reader.hpp"

class Key : public IKey
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;
	typedef std::vector< line_ptr > data_type;
	typedef boost::shared_ptr< data_type > data_ptr;

	Key()
		: keys_( nullptr )
	{}

	void Load( const std::string& fileName )
	{
		keys_ = FileReader::Load( fileName );
	}	

	unsigned int GetRows()
	{
		return keys_->size();
	}

	unsigned int GetColumns()
	{
		return cols_;
	}

	line_ptr GetRow( unsigned int index )
	{
		return (*keys_)[ index ];
	}

	size_t LineCount()
	{
		return keys_->size();
	}

	line_ptr NextLine( size_t count )
	{
		return (*keys_)[ count ]; 
	}

private:

	unsigned int rows_;
	unsigned int cols_;

	data_ptr	keys_;

};

#endif

