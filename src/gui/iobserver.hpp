#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <list>

#include <boost/smart_ptr.hpp>

class IObserver
{

public:

	typedef boost::shared_ptr< IObserver > observer_ptr;

	virtual void Notify() = 0;

};


class ISubject
{

public:

	typedef boost::shared_ptr< IObserver > subject_ptr;
	typedef std::list< IObserver::observer_ptr > observer_data;

	virtual void Register( IObserver::observer_ptr observer ) = 0;
	virtual void Unregister( IObserver::observer_ptr observer ) = 0;

	virtual void NotifyObservers() = 0;

};

#endif

