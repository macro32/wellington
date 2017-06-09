#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting order input test program...." << std::endl;

	OrderContext orders;
	Driver driver( orders );

	if( argc > 1 )
	{
		std::fstream infile( argv[1] );
		if( !infile.good() )
		{
			std::cout << "cannot open input file : [" << argv[1] << "]" << std::endl;
			return 0;
		}
		orders.Clear();
		bool result = driver.ParseStream( infile, argv[1] );
		if ( result )
		{
			std::cout << "orders: " << std::endl;
			for( unsigned int o = 0; o < driver.orders_.orders_.size(); ++o )
			{
			}
		}	
		return 0;
	}

	do
	{
		std::string order;
		std::cout << "input order ";	
		getline( std::cin, order );	

		if( order == "end" )
		{
			break;
		}
		if( order.empty() )
		{
			break;
		}

		orders.Clear();
		bool result = driver.ParseString( order, "order" );
		if ( result )
		{
			std::cout << "orders: " << std::endl;
			for( unsigned int o = 0; o < driver.orders_.orders_.size(); ++o )
			{
			}
		}	

	} while( true );
	
	return 0;
}
