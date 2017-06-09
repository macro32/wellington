#include <iostream>

#include "pugixml.hpp"

int main( int argc, char** argv )
{
    std::cout << "test pugixml..." << std::endl;

    pugi::xml_document doc;

    pugi::xml_parse_result result = doc.load_file( "Wellington.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        return -1;
    }

    pugi::xml_node components = doc.child( "Actor" ).child( "Components" );

    std::cout << "wellington" << std::endl;
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
        }
        std::cout << std::endl;
    }

    result = doc.load_file( "20thFoot.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        return -1;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "20th foot" << std::endl;
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
        }
        std::cout << std::endl;
    }

    result = doc.load_file( "95thRifles.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        return -1;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "95th rifles" << std::endl;
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
        }
        std::cout << std::endl;
    }

    result = doc.load_file( "ScotsGreys.xml" ) ;

    if( !result )
    {
        std::cout << "read document with error: " << result.description() << std::endl;
        return -1;
    }

    components = doc.child( "Actor" ).child( "Components" );

    std::cout << "scots greys" << std::endl;
    for( pugi::xml_node component: components.children( "Component" ) )
    {
        std::cout << "Component: " << component.attribute( "name" ).value() << " : ";  
        for( pugi::xml_node child: component.children() )
        {
            std::cout << " child " << child.name();
        }
        std::cout << std::endl;
    }
}
