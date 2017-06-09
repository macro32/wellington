#include "order_component.hpp"

extern Log logger;

const std::string OrderComponent::name_ = "OrderComponent";



bool OrderComponent::Init(pugi::xml_node data)
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );

    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, std::string( "child name: " ) + child.name() );
        logger.Severity( severity_level::debug, std::string( "child value: " ) + child.child_value() );
		if( child.name() == "Order" )
		{
		}
    }
	return true;
}

void OrderComponent::PostInit()
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
}
