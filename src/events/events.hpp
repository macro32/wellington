#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "actor.hpp"
#include "event.hpp"

class EventCreateActor : public EventBase
{

public:

    static const EventType eventType_;

    expicit EventCreateActor( ActorId id )
        : id_( id )
    {}

    virtual const EventType GetEventType() const
    {
        return eventType_;
    }

private:

    ActorId id_;

};

#endif

