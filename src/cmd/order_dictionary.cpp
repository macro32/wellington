#include "order_dictionary.hpp"


namespace order
{

Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = boost::make_shared<Entry>( std::string( "attack" ), Verb, Attack, Strong );
	dictionary_[ "move"   ] = boost::make_shared<Entry>( std::string( "move" ), Verb, Neutral, Medium );
	dictionary_[ "defend" ] = boost::make_shared<Entry>( std::string( "defend" ), Verb, Defend, Strong );
	dictionary_[ "support"] = boost::make_shared<Entry>( std::string( "support" ), Verb, Attack, Medium );
	dictionary_[ "advance"] = boost::make_shared<Entry>( std::string( "advance" ), Verb, Attack, Medium );
	dictionary_[ "occupy" ] = boost::make_shared<Entry>( std::string( "occupy" ), Verb, Neutral, Weak );
	dictionary_[ "hold"   ] = boost::make_shared<Entry>( std::string( "hold" ), Verb, Defend, Medium );
	dictionary_[ "clear"   ] = boost::make_shared<Entry>( std::string( "clear" ), Verb, Attack, Medium );
	dictionary_[ "defeat"   ] = boost::make_shared<Entry>( std::string( "defeat" ), Verb, Neutral, Medium );
	dictionary_[ "wait"   ] = boost::make_shared<Entry>( std::string( "wait" ), Verb, Neutral, Medium );
	
	dictionary_[ "town"   ] = boost::make_shared<Entry>( std::string( "town" ), Noun, Neutral, Strong );
	dictionary_[ "hill"   ] = boost::make_shared<Entry>( std::string( "hill" ), Noun, Neutral, Strong );
	dictionary_[ "village"   ] = boost::make_shared<Entry>( std::string( "village" ), Noun, Neutral, Strong );
	dictionary_[ "wood"   ] = boost::make_shared<Entry>( std::string( "wood" ), Noun, Neutral, Strong );
	dictionary_[ "bridge"   ] = boost::make_shared<Entry>( std::string( "bridge" ), Noun, Neutral, Medium );
	dictionary_[ "road"   ] = boost::make_shared<Entry>( std::string( "road" ), Noun, Neutral, Weak );
	dictionary_[ "farm"   ] = boost::make_shared<Entry>( std::string( "farm" ), Noun, Neutral, Medium );
	dictionary_[ "field"   ] = boost::make_shared<Entry>( std::string( "field" ), Noun, Neutral, Medium );
	dictionary_[ "crossroads"   ] = boost::make_shared<Entry>( std::string( "crossroads" ), Noun, Neutral, Weak );

	dictionary_[ "north"   ] = boost::make_shared<Entry>( std::string( "north" ), Noun, Neutral, Medium );
	dictionary_[ "south"   ] = boost::make_shared<Entry>( std::string( "south" ), Noun, Neutral, Medium );
	dictionary_[ "east"   ] = boost::make_shared<Entry>( std::string( "east" ), Noun, Neutral, Medium );
	dictionary_[ "west"   ] = boost::make_shared<Entry>( std::string( "west" ), Noun, Neutral, Medium );
	dictionary_[ "n"   ] = boost::make_shared<Entry>( std::string( "n" ), Noun, Neutral, Medium );
	dictionary_[ "s"   ] = boost::make_shared<Entry>( std::string( "s" ), Noun, Neutral, Medium );
	dictionary_[ "e"   ] = boost::make_shared<Entry>( std::string( "e" ), Noun, Neutral, Medium );
	dictionary_[ "w"   ] = boost::make_shared<Entry>( std::string( "w" ), Noun, Neutral, Medium );
	dictionary_[ "nw"   ] = boost::make_shared<Entry>( std::string( "nw" ), Noun, Neutral, Medium );
	dictionary_[ "sw"   ] = boost::make_shared<Entry>( std::string( "sw" ), Noun, Neutral, Medium );
	dictionary_[ "ne"   ] = boost::make_shared<Entry>( std::string( "ne" ), Noun, Neutral, Medium );
	dictionary_[ "nw"   ] = boost::make_shared<Entry>( std::string( "nw" ), Noun, Neutral, Medium );

	dictionary_[ "napolean"   ] = boost::make_shared<Entry>( std::string( "napolean" ), Noun, Neutral, Strong );
	dictionary_[ "orders"  ] = boost::make_shared<Entry>( std::string( "orders" ), Noun, Neutral, Strong );

}

Dictionary::entry_ptr Dictionary::Get( const std::string& token )
{
	std::string key( token );
	boost::to_lower( key );	
	return dictionary_[ key ];
}

}
