#include "identity_component.hpp"

extern Log logger;

const std::string IdentityComponent::name_ = "IdentityComponent";


bool IdentityComponent::Init( pugi::xml_node data )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, child.name() );
        logger.Severity( severity_level::debug, child.child_value() );
        if( child.name() == std::string( "Name" ) )
        {
	    id_ = child.child_value();
        }
        if( child.name() == std::string( "Type" ) )
        {
	    type_ = child.child_value();
        }
        if( child.name() == std::string( "Points" ) )
        {
	    points_ = boost::lexical_cast<std::size_t>( child.child_value() );
        }
    }
    return true;
}

void IdentityComponent::PostInit()
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}
