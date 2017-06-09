#ifndef STDSCR_IVIEW_HPP
#define STDSCR_IVIEW_HPP

#include "types.hpp"

class StdScrIView
{

public:

	virtual void Init() = 0;
	virtual void Terminate() = 0;
	
	virtual void Display() = 0;

	virtual void DisplayMap() = 0;
	virtual void DisplayKey() = 0;
	virtual void DisplayCommand() = 0;
	virtual void DisplayUnits() = 0;

};

typedef boost::shared_ptr< StdScrIView > stdscr_iview_ptr;

#endif
