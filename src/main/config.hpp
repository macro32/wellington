#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <ncurses.h>

#include <string>

#include <boost/smart_ptr.hpp>

#include <pugixml.hpp>

#include "logger.hpp"

extern Log logger;

class Config
{

public:

	Config( const std::string& config );
		
	bool Load();

private:

	std::string config_;

};

#endif
