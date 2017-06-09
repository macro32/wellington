#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include "cmd.hpp"
#include "map.hpp"

typedef boost::shared_ptr< std::string >	line_ptr;
typedef boost::shared_ptr< Command > cmd_ptr;
typedef boost::shared_ptr< Map > map_ptr;

#endif

