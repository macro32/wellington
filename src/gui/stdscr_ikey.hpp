#ifndef STDSCR_IKEY_HPP
#define STDSCR_IKEY_HPP

#include "types.hpp"

class	IKey
{

public:

	virtual void Load( const std::string& fileName ) = 0;
	virtual unsigned int GetRows() = 0;
	virtual unsigned int GetColumns() = 0;
	virtual line_ptr GetRow( unsigned int index ) = 0;
	virtual size_t LineCount() = 0;
	virtual line_ptr NextLine( size_t count ) = 0;

};

typedef boost::shared_ptr< IKey > stdscr_ikey_ptr;

#endif
