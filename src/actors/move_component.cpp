#include "move_component.hpp"

extern Log logger;

const std::string MoveComponent::name_ = "MoveComponent";



bool MoveComponent::Init(pugi::xml_node data)
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );

    for( pugi::xml_node child: data.children() )
    {
        logger.Severity( severity_level::debug, std::string( "child name: " ) + child.name() );
        logger.Severity( severity_level::debug, std::string( "child value: " ) + child.child_value() );
        if( child.name() == std::string( "Front" ) )
        {
	    	front_ = boost::lexical_cast<std::size_t>( child.child_value() );
        	logger.Severity( severity_level::debug, std::string( "front: " ) + boost::lexical_cast<std::string>( front_ ) );
        }
        if( child.name() == std::string( "Normal" ) )
        {
	    	normal_ = boost::lexical_cast<std::size_t>( child.child_value() );
        	logger.Severity( severity_level::debug, std::string( "normal: " ) + boost::lexical_cast<std::string>( normal_ ) );
		}
        if( child.name() == std::string( "Action" ) )
		{
	    	action_ = boost::lexical_cast<std::size_t>( child.child_value() );
        	logger.Severity( severity_level::debug, std::string( "action: " ) + boost::lexical_cast<std::string>( action_ ) );
		}
        if( child.name() == std::string( "StartX" ) )
		{
	    	startX_ = boost::lexical_cast<int>( child.child_value() );
        	logger.Severity( severity_level::debug, std::string( "startx: " ) + boost::lexical_cast<std::string>( startX_ ) );
		}
        if( child.name() == std::string( "StartY" ) )
		{
	    	startY_ = boost::lexical_cast<int>( child.child_value() );
        	logger.Severity( severity_level::debug, std::string( "starty: " ) + boost::lexical_cast<std::string>( startY_ ) );
		}
    }
	return true;
}

void MoveComponent::PostInit()
{
    logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
}
