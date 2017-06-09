#ifndef JSON_FILE_RESOURCE_HPP
#define JSON_FILE_RESOURCE_HPP

#include "resource.hpp"
#include "properties.hpp"

class JsonFileResource : public Resource
{

public:

	typedef boost::shared_ptr< JsonFileResource > json_resource_ptr;

	JsonFileResource( std::string name, std::string& fileName )
		: 	
			Resource( name ),
			fileName_( fileName ),
			resource_( nullptr )
	{}

	virtual void Load()
	{
		resource_ = Properties::ReadJson( fileName_ );
	}

	Properties::ptr Get()
	{
		return resource_;
	}

private:

	std::string fileName_;

	Properties::ptr resource_;

};

#endif

