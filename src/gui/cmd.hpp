#ifndef CMD_HPP
#define CMD_HPP

#include <ncurses.h>
#include <string>

#include <boost/smart_ptr.hpp>

class Command
{

public:

	typedef boost::shared_ptr< Command > command_ptr; 
	typedef boost::shared_ptr< std::string > line_ptr;

	line_ptr  GetPrompt();
	void Put( unsigned int row, unsigned int col, Command::line_ptr line );
	void ClearLine( unsigned int row, unsigned int col, unsigned int length );
	line_ptr Read( unsigned int row, unsigned int col );
	line_ptr Read();

private:

};

#endif
