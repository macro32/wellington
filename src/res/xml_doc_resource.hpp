#ifndef XML_DOC_RESOURCE_HPP
#define XML_DOC_RESOURCE_HPP

#include "resource.hpp"
#include "properties.hpp"

class XmlDocResource : public Resource
{

public:

	typedef boost::shared_ptr< XmlDocResource > xml_resource_ptr;

	XmlDocResource( std::string name, std::string& fileName )
		: 	
			Resource( name ),
			fileName_( fileName ),
			resource_( nullptr )
	{}

	virtual void Load()
	{
		resource_ = Properties::ReadXmlDoc( fileName_ );
	}

	Properties::pointer Get()
	{
		return resource_;
	}

private:

	std::string fileName_;

	Properties::pointer resource_;

};

#endif

