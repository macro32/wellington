#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "order_dictionary.hpp"

namespace order
{

class Order 
{

public:

	typedef boost::shared_ptr< Order > order_ptr;
	typedef std::vector< std::string > order_data;
	typedef std::vector< Dictionary::entry_ptr > entry_data;

	void Add( const std::string& value )
	{
		sentence_.push_back( value );
	}

	void Add( Dictionary::entry_ptr entry )
	{
		entries_.push_back( entry );
	}

	order_data GetSentence()
	{
		return sentence_;
	}

	entry_data GetEntries()
	{
		return entries_;
	}

private:

	std::vector< Dictionary::entry_ptr > entries_; 
	std::vector< std::string > sentence_;

};

class OrderContext
{

public:

	typedef std::vector< Order::order_ptr > orders_data;

	OrderContext( Dictionary& dictionary )
		: dictionary_( dictionary )
	{}

	void Clear()
	{
		orders_.clear();
	}

	void Translate()
	{
		for( 	orders_data::iterator it = orders_.begin();
				it != orders_.end();
				++it )
		{
			Order::order_data sentence = (*it)->GetSentence();
			for( 	Order::order_data::iterator oi = sentence.begin();
					oi != sentence.end();
					++oi )
			{
				Dictionary::entry_ptr entry = dictionary_.Get( (*oi) );
				(*it)->Add( entry );
			}	 
		}
	}

	std::vector< Order::order_ptr > orders_;

	Dictionary&	dictionary_;

};

}
 
#endif

