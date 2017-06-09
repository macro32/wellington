#ifndef XML_FILE_RESOURCE_HPP
#define XML_FILE_RESOURCE_HPP

#include "resource.hpp"
#include "properties.hpp"

class XmlFileResource : public Resource
{

public:

	typedef boost::shared_ptr< XmlFileResource > xml_resource_ptr;

	XmlFileResource( std::string name, std::string& fileName )
		: 	
			Resource( name ),
			fileName_( fileName ),
			resource_( nullptr )
	{}

	virtual void Load()
	{
		resource_ = Properties::ReadXml( fileName_ );
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

