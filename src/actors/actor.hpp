#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <map>
#include <memory>

#include <boost/smart_ptr.hpp>

#include <boost/property_tree/ptree.hpp>

#include "actor_component.hpp"
#include "logger.hpp"

extern Log logger;

class   Actor
{

public:

    typedef std::map< ComponentId, ActorComponentPtr > ActorComponents;

    explicit Actor( ActorId id );
    ~Actor();

    bool Init( Properties::pointer data );

    void PostInit();
    void Destroy();

    void Update( int deltaMs );

    std::string ToXML();

    ActorId   GetId()
    {
        return actorId_;
    }

    template< class ComponentType >
    boost::weak_ptr<ComponentType> GetComponent( ComponentId id )
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        ActorComponents::iterator it = components_.find( id );
        if( it != components_.end() )
        {
            ActorComponentPtr base( it->second );
            boost::shared_ptr< ComponentType > sub( boost::static_pointer_cast<ComponentType>( base ) );
            boost::weak_ptr<ComponentType > weakSub( sub );
            return weakSub;
        }
        else
        {
            return boost::weak_ptr<ComponentType>();
        }
    }

    template <class ComponentType>
    boost::weak_ptr<ComponentType> GetComponent(const std::string& name)
    {
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	ComponentId id = ActorComponent::GetIdFromName(name);
        ActorComponents::iterator it = components_.find( id );
        if( it != components_.end())
        {
            ActorComponentPtr base( it->second );
            boost::shared_ptr<ComponentType> sub( boost::static_pointer_cast<ComponentType>( base ) );  
            boost::weak_ptr<ComponentType> weakSub( sub );  
            return weakSub;  
        }
        else
        {
            return boost::weak_ptr<ComponentType>();
        }
    }

    void AddComponent( ActorComponentPtr component );

private:

    std::string type_;
    std::string resource_;

    ActorId actorId_;

    ActorComponents components_;

};

#endif

