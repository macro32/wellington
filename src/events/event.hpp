#ifndef EVENT_HPP
#define EVENT_HPP

/***

   Heavily borrowed from Game Coding Complete, 4th Edition. But I figure
   Mike McShaffrey owes me, as he borrowed my review of the original
   for the 2nd and 3rd Editions. 

   Thanks for a great series. I have bought all editions as requested.

   I plan on using the basic code for actor, actor configuration and event code to get me
   started. The rest will be mine. My main changes to the original code are style, more use 
   of boost, some simplication, and logging will be replaced.

   I will read the GPL3 soon....

   -- spotland (Rochdale AFC's ground)

***/

#include <time.h>

class   IEvent
{

public:

    typedef unsigned long EventType;
    typedef boost::shared_ptr<IEvent> IEventPtr;
    typedef fastdelegate::FastDelegate1<IEventPtr> EventListenerDelegate;
    
    virtual const EventType GetEventType() = 0;
    virtual clock_t GetTimeStamp() = 0;
    virtual const char* GetName() = 0;
 
};

class EventBase : public IEvent
{

public:

    explicit EventBase( const clock_t timeStamp = 0 )
        : timeStamp_( timeStamp )
    {}

    virtual const EventType GetEventType() const = 0;

    clock_t GetTimeStamp() const
    {
        return timeStamp_;
    }

private:

    const clock_t timeStamp_;

};

#endif

