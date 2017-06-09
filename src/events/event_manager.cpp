#include "event_manager.hpp"


bool EventManager::AddListener( const IEvent::EventListenerDelegate eventDelegate, const IEvent::EventType type )
{
    EventListenerList& eventListenerList = eventListeners_[ type ];
    for ( auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it )
    {
        if ( eventDelegate == (*it) )
        {
            return false;
        }
    }

    eventListenerList.push_back( eventDelegate );

	return true;
}

bool EventManager::RemoveListener( const IEvent::EventListenerDelegate eventDelegate, const IEvent::EventType type )
{
	bool success = false;

    auto findIt = eventListeners_.find( type );
    if ( findIt != eventListeners_.end() )
    {
        EventListenerList& listeners = findIt->second;
        for ( auto it = listeners.begin(); it != listeners.end(); ++it )
        {
            if ( eventDelegate == (*it) )
            {
                listeners.erase( it );
                success = true;
                break;  
            }
        }
    }

    return success;
}

bool EventManager::TriggerEvent( const IEvent::IEventPtr event ) const
{
    bool processed = false;

    auto findIt = eventListeners_.find( event->GetEventType() );
	if ( findIt != eventListeners_.end() )
    {
	    const EventListenerList& eventListenerList = findIt->second;
	    for (EventListenerList::const_iterator it = eventListenerList.begin(); it != eventListenerList.end(); ++it)
	    {
		    IEvent::EventListenerDelegate listener = (*it);
		    listener( event );
            processed = true;
	    }
    }
	
	return processed;
}

bool EventManager::QueueEvent( const IEvent::IEventPtr event )
{
    if ( !event )
    {
        return false;
    }

	auto findIt = eventListeners_.find( event->GetEventType() );

    if( findIt != eventListeners_.end() )
    {
        eventQueue_.push_back( event );

        return true;
    }
    else
    {
        return false;
    }
}

bool EventManager::AbortEvent( const IEvent::EventType type, bool allOfType )
{
    bool success = false;

	EventListenerMap::iterator findIt = eventListeners_.find( type );

	if ( findIt != eventListeners_.end() )
    {
        EventQueue& eventQueue = eventQueue_;
        auto it = eventQueue.begin();
        while ( it != eventQueue.end() )
        {
            auto thisIt = it;
            ++it;

	        if ( (*thisIt)->GetEventType() == type )
	        {
		        eventQueue.erase( thisIt );
		        success = true;
		        if ( !allOfType )
			        break;
	        }
        }
    }

	return success;
}

bool EventManager::Update( unsigned long maxMillis )
{
	unsigned long currMs = clock();
	unsigned long maxMs = currMs + maxMillis;

	eventQueue_.clear();

	while ( !eventQueue_.empty())
	{
		IEvent::IEventPtr event = eventQueue_.front();
        eventQueue_.pop_front();

		const IEvent::EventType& eventType = event->GetEventType();

		auto findIt = eventListeners_.find( eventType );
		if ( findIt != eventListeners_.end() )
		{
			const EventListenerList& eventListeners = findIt->second;

			for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it)
			{
                IEvent::EventListenerDelegate listener = (*it);
				listener( event );
			}
		}

		currMs = clock();
		if ( currMs >= maxMs )
        {
			break;
        }
	}
	
	return eventQueue_.empty();
}
