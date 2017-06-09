#include "cmd.hpp"


Command::line_ptr Command::GetPrompt()
{
	return boost::make_shared<std::string>( "Enter command: " );
}

void Command::Put( unsigned int row, unsigned int col, Command::line_ptr line )
{
	mvprintw( row, col, (*line).c_str() );
}

Command::line_ptr Command::Read( unsigned int row, unsigned int col )
{
	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

Command::line_ptr Command::Read()
{
	char cmd[ 128 ];

	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

void Command::ClearLine( unsigned int row, unsigned int column, unsigned int length )
{
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column + count, ' ' );
	} 
}

