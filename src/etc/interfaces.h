#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <string>

#include <boost/smart_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Actor;
class ActorComponent;

typedef boost::shared_ptr<Actor>    ActorPtr;
typedef boost::shared_ptr<ActorComponent>   ActorComponentPtr;
typedef boost::shared_ptr< boost::posix_time::time_duration >  timeout_ptr;

typedef std::size_t ActorId;
typedef std::size_t ComponentId;

class Command;
class Map;

typedef boost::shared_ptr< std::string >	line_ptr;
typedef boost::shared_ptr< Command > cmd_ptr;
typedef boost::shared_ptr< Map > map_ptr;

#endif

