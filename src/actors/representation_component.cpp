#include "representation_component.hpp"

extern Log logger;

const std::string RepresentationComponent::name_ = "RepresentationComponent";


bool RepresentationComponent::Init( pugi::xml_node data )
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );

    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );

        if( child.name() == std::string( "Image" ) )
        {
	    	image_ = child.child_value();
        }
        if( child.name() == std::string( "Char" ) )
        {
	    	char_ = child.child_value();
		}
    }
    return true;
}

void RepresentationComponent::PostInit()
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
}
