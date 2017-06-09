#ifndef ORDER_COMPONENT_HPP
#define ORDER_COMPONENT_HPP


#include "actor_component.hpp"
#include "driver.hpp"


class OrderComponent : public ActorComponent
{

public:

    typedef std::size_t Id;
    typedef boost::shared_ptr< ActorComponent > ptr;

    static const std::string name_;

    OrderComponent() 
    { 
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    }

    virtual ComponentId GetId() const 
    {
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
        return GetIdFromName( GetName() ); 
    }

    virtual const std::string GetName() const 
    {
        return name_;
    }

    virtual bool Init(pugi::xml_node data);

    virtual void PostInit();

    virtual void Update(int deltaMs) { }
    virtual void OnChanged() { }				

    static ComponentId GetIdFromName( const std::string& name )
    {
        boost::hash<std::string> string_hash;
		return string_hash( name );
    }

private:

};

#endif
