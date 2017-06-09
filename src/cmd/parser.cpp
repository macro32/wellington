#include "parser.hpp"

namespace order
{

bool Parser::parse()
{
	std::string text;

	Order::order_ptr order = boost::make_shared<Order>();
	symbolclass token = driver_.lexer_->NextToken();
	while( EOFSY != token )
	{
		switch( token )
		{
			case WORD :	
				text = driver_.lexer_->GetToken();
				order->Add( text );				
				break;
			case INTEGER :
				text = driver_.lexer_->GetToken();
				order->Add( text );				
				break;
			case PERIOD :
				driver_.orders_.orders_.push_back( order );	
				order = boost::make_shared<Order>();
				break;
		}
		token = driver_.lexer_->NextToken();
	}

	return true;
}

}
