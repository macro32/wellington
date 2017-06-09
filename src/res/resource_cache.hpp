#ifndef RESOURCE_CACHE_HPP
#define RESOURCE_CACHE_HPP

#include <map>

#include "resource.hpp"



class ResourceCache
{

public:

	typedef boost::shared_ptr< Resource > resource_value;
	typedef std::map< std::string, resource_value >	resource_data;

	void Add( resource_value value )
	{
		resources_[value->Name()]  = value; 
	}

	resource_value Get( const std::string& name )
	{
		return resources_[ name ];
	}
 
private:

	resource_data	resources_;

};

#endif

