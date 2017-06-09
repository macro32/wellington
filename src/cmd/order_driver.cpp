#include "order_driver.hpp"

namespace order
{

OrderDriver::OrderDriver( class OrderContext& orders )
	: 	orders_( orders )
{}

bool OrderDriver::ParseStream( std::istream& input, const std::string& name )
{
	Scanner scanner( input );
	lexer_ = &scanner;

	Parser parser( *this );

	return parser.parse() == 0;
}

bool OrderDriver::ParseString( const std::string& input, const std::string& name )
{
	std::istringstream in( input );
	return ParseStream( in, name );
}

bool OrderDriver::ParseFile( const std::string& name )
{
	std::ifstream input( name.c_str() );
	return ParseStream( input, name );
}

}
