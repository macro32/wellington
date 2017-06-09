#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include <boost/property_tree/ptree.hpp>

#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "logger.hpp"

#include "pugixml.hpp"

extern Log logger;

class Properties
{

public:

    typedef boost::property_tree::ptree property_tree;
    typedef boost::shared_ptr< property_tree > ptr;

    typedef pugi::xml_document data_type;
    typedef boost::shared_ptr< data_type > pointer; 

    static pointer ReadXmlDoc( const std::string& fileName )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        pointer doc = boost::make_shared< pugi::xml_document >();
        pugi::xml_parse_result result = doc->load_file( fileName.c_str() );
        if( result )
        {
	   logger.Severity( severity_level::debug, result.description() );
           return doc;
        }
	logger.Severity( severity_level::debug, result.description() );
	return pointer();
    }

    static ptr ReadXml( const std::string& fileName )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        ptr properties = boost::make_shared< property_tree >();
        read_xml( fileName, *properties );        
        return properties;
    }

    static ptr ReadJson( const std::string& fileName )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        ptr properties = boost::make_shared< property_tree >();
        read_json( fileName, *properties );        
        return properties;
    }

    static ptr ReadIni( const std::string& fileName )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        ptr properties = boost::make_shared< property_tree >();
        read_ini( fileName, *properties );        
        return properties;
    }

};



#endif
