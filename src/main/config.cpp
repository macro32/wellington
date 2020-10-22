#include <iostream>

#include "pugixml.hpp"
#include "config.hpp"

Config::Config( const std::string& config )
	: config_( config )
{ 

}


bool Config::Load()
{
    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file( "Wellington.xml" ) ;

    if( !result )
    {
	std::cout << "read document with error: " << result.description() << std::endl;
	logger.Severity( severity_level::info, "read document with error: \n"  );
        return false;
    }

    pugi::xml_node components = doc.child( "Actor" ).child( "Components" );

    std::cout << "wellington" << std::endl;
    logger.Severity( severity_level::info,  "wellington\n"  );
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        logger.Severity( severity_level::info, "Component:  : " );  
        logger.Severity( severity_level::info, component.attribute( "name" ).value() );  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
            logger.Severity( severity_level::info, " child "  );
            logger.Severity( severity_level::info, child.name()  );
        }
        std::cout << std::endl;
        logger.Severity( severity_level::info, "\n" );
    }

    result = doc.load_file( "20thFoot.xml" ) ;
    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        logger.Severity( severity_level::info, "read document with error: " );
        return false;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "20th foot" << std::endl;
    logger.Severity( severity_level::info, "20th foot\n" );
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        logger.Severity( severity_level::info, "Component:  : " );  
        logger.Severity( severity_level::info, component.attribute( "name" ).value() );  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
            logger.Severity( severity_level::info, " child " );
            logger.Severity( severity_level::info, child.name()  );
        }
        std::cout << std::endl;
        logger.Severity( severity_level::info, "\n" );
    }

    result = doc.load_file( "95thRifles.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        logger.Severity( severity_level::info, "read document with error: \n"  );
        return false;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "95th rifles" << std::endl;
    logger.Severity( severity_level::info, "95th rifles\n" );
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        logger.Severity( severity_level::info, "Component:  : " );  
        logger.Severity( severity_level::info, component.attribute( "name" ).value() );  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
            logger.Severity( severity_level::info, " child " );
            logger.Severity( severity_level::info, child.name()  );
        }
        std::cout << std::endl;
        logger.Severity( severity_level::info, "\n" );
    }

    result = doc.load_file( "ScotsGreys.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        logger.Severity( severity_level::info, "read document with error: "  );
        return false;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "scots greys" << std::endl;
    logger.Severity( severity_level::info, "scots greys\n"  );
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        logger.Severity( severity_level::info, "Component:  : " );  
        logger.Severity( severity_level::info, component.attribute( "name" ).value() );  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
            logger.Severity( severity_level::info, " child " );
            logger.Severity( severity_level::info, child.name()  );
        }
        std::cout << std::endl;
        logger.Severity( severity_level::info, "\n" );
    }

    return true;
}
