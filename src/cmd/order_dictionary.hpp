#ifndef ORDER_DICTIONARY_HPP
#define ORDER_DICTIONARY_HPP

#include <string>
#include <map>

#include <boost/algorithm/string.hpp>
#include <boost/smart_ptr.hpp>

namespace order
{

enum Speech
{
	Verb = 1,
	Noun
};

enum Action
{
	Attack = 1,
	Neutral,
	Defend
};

enum Strength
{
	Weak = 1,
	Medium,
	Strong
};

struct Entry
{

	Entry( 	const std::string& value, 
			enum Speech speech,
			enum Action action,
			enum Strength strength )
		: 	value_( value ),
			speech_( speech ),
			action_( action ),
			strength_( strength )
	{}

	const std::string value_;

	enum Speech speech_;
	enum Action action_;
	enum Strength strength_;
};



class Dictionary
{

public:

	typedef boost::shared_ptr< Entry > entry_ptr;
	typedef std::map< std::string, entry_ptr > dictionary_type;

	Dictionary();

	entry_ptr Get( const std::string& token);	

private:

	dictionary_type	dictionary_;

};

}

#endif
