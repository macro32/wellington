#include "actor.hpp"
#include "actor_component.hpp"

Actor::Actor(ActorId id)
{
    actorId_ = id;
}

Actor::~Actor()
{
}

bool Actor::Init( Properties::pointer data )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

    type_ = data->child( "Actor" ).attribute( "type" ).value();
    resource_ = data->child( "Actor" ).attribute( "resource" ).value();

    logger.Severity( severity_level::debug, type_ );
    logger.Severity( severity_level::debug, resource_ );

    return true;
}

void Actor::PostInit(void)
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->PostInit();
    }
}

void Actor::Destroy(void)
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    components_.clear();
}

void Actor::Update( int deltaMs )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->Update( deltaMs );
    }
}

void Actor::AddComponent( ActorComponentPtr component )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    std::pair<ActorComponents::iterator, bool> success = components_.insert( std::make_pair( component->GetId(), component ) );
}

std::string Actor::ToXML()
{
	std::stringstream os;
	os << "<Components>" << boost::lexical_cast<std::string>( components_.size() ) << "</Components>";
	return os.str();
}

