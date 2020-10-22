#ifndef ACTOR_COMPONENT_HPP
#define ACTOR_COMPONENT_HPP

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/smart_ptr.hpp>
#include <boost/functional/hash.hpp>
#include <boost/lexical_cast.hpp>

#include "interfaces.h"
#include "properties.hpp"
#include "pugixml.hpp"
#include "logger.hpp"

extern Log logger;

class ActorComponent
{

public:

    virtual ~ActorComponent() 
    { 
        owner_.reset(); 
    }

    virtual ComponentId GetId() const 
    {
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
		logger.Severity( severity_level::debug, GetName() );
		logger.Severity( severity_level::debug, boost::lexical_cast<std::string>( GetIdFromName( GetName() ) ) );

        return GetIdFromName( GetName() ); 
    }

    virtual const std::string GetName() const = 0;

    virtual bool Init( pugi::xml_node data ) = 0;

    virtual void PostInit() { }

    virtual void Update(int deltaMs) { }
    virtual void OnChanged() { }				

    static ComponentId GetIdFromName( const std::string& name )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	logger.Severity( severity_level::debug, name );
        boost::hash<std::string> string_hash;
	logger.Severity( severity_level::debug, boost::lexical_cast<std::string>( string_hash(name) ) );
	return string_hash( name );
    }

    void SetOwner( ActorPtr owner ) 
    { 
        owner_ = owner; 
    }

private:

    ActorPtr  owner_;

};

#endif
