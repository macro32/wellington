#ifndef REPRESENTATION_COMPONENT_HPP
#define REPRESENTATION_COMPONENT_HPP


#include "actor_component.hpp"



class RepresentationComponent : public ActorComponent
{

public:

    typedef std::size_t Id;
    typedef boost::shared_ptr< ActorComponent > ptr;

    static const std::string name_;

    RepresentationComponent()
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

	char GetChar()
	{
		return char_[0];
	}

private:

    std::string image_;
    std::string char_;

};

#endif
