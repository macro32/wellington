#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <time.h>

#include <list>
#include <map>

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>

#include "FastDelegate.h"
#include "event.hpp"


class EventManager : public boost::noncopyable
{

public:

    typedef std::list<IEvent::EventListenerDelegate> EventListenerList;
    typedef std::map<IEvent::EventType, EventListenerList> EventListenerMap;
    typedef std::list<IEvent::IEventPtr> EventQueue;

    virtual bool AddListener( const IEvent::EventListenerDelegate eventDelegate, const IEvent::EventType type);
	virtual bool RemoveListener( const IEvent::EventListenerDelegate eventDelegate, const IEvent::EventType type);

	virtual bool TriggerEvent( const IEvent::IEventPtr event ) const;

	virtual bool QueueEvent( const IEvent::IEventPtr event );

	virtual bool AbortEvent( const IEvent::EventType type, bool allOfType = false);

	virtual bool Update( unsigned long maxMillis );

private:

    EventListenerMap   eventListeners_;
    EventQueue eventQueue_;
    
};

#endif
