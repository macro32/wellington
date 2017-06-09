#include "stdscr_view.hpp"

#include <iostream>

StdScrView::StdScrView()
	:
		rows_( LINES ),
		columns_( COLS )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

StdScrView::StdScrView( stdscr_imodel_ptr model )
	:	imodel_( model ),
		rows_( LINES ),
		columns_( COLS )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

StdScrView::~StdScrView()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	Terminate();
}

void StdScrView::Init()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	initscr();
	raw();
	keypad( stdscr, TRUE );
	//int rows, cols;
	//getmaxyx( stdscr, rows, cols );
	//rows_ = rows;
	//columns_ = cols;
	refresh();
}

void StdScrView::Terminate()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	endwin();
}


void StdScrView::Display()
{
	DisplayMap();
	DisplayKey();
	DisplayCommand();
	DisplayUnits();
}

void StdScrView::DisplayMap()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	map_ptr map = imodel_->GetMap();

	std::vector< Tile > tiles = imodel_->GetTiles();

	logger.Severity( severity_level::info, map->ToString() );
	for( int i = 0; i < tiles.size(); ++i )
	{
		logger.Severity( severity_level::info, tiles[i].ToString() );
	}

	for( size_t row = 0;
		 row < map->rows_;
		 ++row
		)
	{
		for( size_t col = 0;
			 col < map->cols_;
			 ++col )
		{
			Put( row, col, tiles[ map->map_tiles[ row ][ col ] - 1 ].terrain_representation_ );
		}
	}
}

void StdScrView::DisplayKey()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	stdscr_ikey_ptr key = imodel_->GetKey();

	size_t rows = key->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		line_ptr line = key->NextLine( count );
		Put( count, 100, line );
	}
}

void StdScrView::DisplayCommand()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	line_ptr prompt = imodel_->GetCmd()->GetPrompt();
	ClearLine( 40, 0, 80 );
	Put( 40, 0, prompt );
}

void StdScrView::DisplayUnits()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
#if 0
	logger.Severity( severity_level::info, std::string("actor count: ") + boost::lexical_cast<std::string>(actors_.size()) );

	logger.Severity( severity_level::info, std::string("actor 1: ") + actors_[0]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 2: ") + actors_[1]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 3: ") + actors_[2]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 4: ") + actors_[3]->ToXML() );
#endif

	for( ActorPtr actor: 	imodel_->GetActors() )
	{
		boost::shared_ptr<MoveComponent> move( actor->GetComponent<MoveComponent>( std::string( "MoveComponent" ) ) );

		int x = move->GetStartX();
		int y = move->GetStartY();		

		boost::shared_ptr<RepresentationComponent> representation( actor->GetComponent<RepresentationComponent>( std::string( "RepresentationComponent" ) ) );

		char c = representation->GetChar();

		Put( x, y, c );

		logger.Severity( severity_level::info, std::string("start x: ") + boost::lexical_cast<std::string>( x ) );
		logger.Severity( severity_level::info, std::string("start y: ") + boost::lexical_cast<std::string>( y ) );
	}
}

void StdScrView::DisplayLine( unsigned int row, unsigned int column, std::string& line )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	mvprintw( row, column, line.c_str() );
}

void StdScrView::Put( unsigned int row, unsigned int col, line_ptr line )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	mvprintw( row, col, (*line).c_str() );
}

line_ptr StdScrView::Read( unsigned int row, unsigned int col )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

line_ptr StdScrView::Read()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	char cmd[ 128 ];

	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

void StdScrView::ClearLine( unsigned int row, unsigned int column, unsigned int length )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column + count, ' ' );
	} 
}

void StdScrView::Put( unsigned int row, unsigned int col, char ch )
{
	mvaddch( row, col, ch );
}

