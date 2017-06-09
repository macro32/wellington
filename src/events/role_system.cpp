#include "role_system.hpp"

RoleSystem::RoleSystem()
{
}

RoleSystem::~RoleSystem()
{
}

void RoleSystem::Init()
{
    EventListenerDelegate delegate = MakeDelegate( this, &RoleSystem::CreateActorDelegate );
}

void CreateActorDelegate( IEventPtr event )
{
}
