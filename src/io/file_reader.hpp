#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>



class FileReader
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;
	typedef std::vector< line_ptr > data_type;
	typedef boost::shared_ptr< data_type > data_ptr;

	static data_ptr Load( const std::string& fileName )
	{
		std::string line;

		std::ifstream input;

		data_ptr lines = boost::make_shared< data_type >();

		input.open( fileName );
		while( !input.eof() )
		{
			getline( input, line );	
			boost::shared_ptr< std::string> l = boost::make_shared< std::string >( line );
			lines->push_back( l );
		}
		input.close();

		return lines;
	}	

};

#endif

