#ifndef ACTOR_FACTORY_HPP
#define ACTOR_FACTORY_HPP

#include <map>

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>

#include "logger.hpp"
#include "actor.hpp"
#include "actor_component.hpp"
#include "properties.hpp"

extern Log logger;

template <class BaseType, class SubType>
BaseType* GenericObjectCreationFunction() 
{
    return new SubType; 
}

template <class BaseClass, class IdType>
class GenericObjectFactory
{

    typedef BaseClass* (*ObjectCreationFunction)(void);

public:

    template <class SubClass>
    bool Register( IdType id )
    {
	logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
        auto it = creationFunctions.find( id );
        if ( it == creationFunctions.end() )
        {
            creationFunctions[ id ] = &GenericObjectCreationFunction< BaseClass, SubClass >;
            return true;
        }

        return false;
    }

    BaseClass* Create( IdType id )
    {
	logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
        auto it = creationFunctions.find( id );
        if( it != creationFunctions.end() )
        {
            ObjectCreationFunction func = it->second;
            return func();
        }

        return NULL;
    }

private:

    std::map< IdType, ObjectCreationFunction > creationFunctions;

};


class   ActorFactory : public boost::noncopyable
{

public:

    typedef boost::shared_ptr< ActorComponent > (*ActorComponentCreator)();
    typedef std::map< std::string, ActorComponentCreator > ActorComponentCreatorMap;

    ActorFactory();

    ActorPtr    CreateActor( const std::string& actorResource );
    virtual ActorComponentPtr CreateComponent( pugi::xml_node data );

private:

    ActorId   GetNextId() 
    {
	logger.Severity( severity_level::debug, __PRETTY_FUNCTION__ );
        ++id_;
        return id_;
    }

    GenericObjectFactory< ActorComponent, ComponentId > componentFactory_;

    ActorComponentCreatorMap    actorComponentCreators_;

    ActorId   id_;
};

#endif

