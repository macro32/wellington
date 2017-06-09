#include "stdscr_model.hpp"



StdScrModel::StdScrModel()
	: map_( boost::make_shared< Map >() ),
	  key_( boost::make_shared< Key >() ),
      cmd_( boost::make_shared< Command >() )
{}



void StdScrModel::Init()
{}

void StdScrModel::Reset()
{
	Load();
	Display();
}

void StdScrModel::Terminate()
{}

void StdScrModel::Load()
{
	LoadMap();
	LoadKey();
}

void StdScrModel::Display()
{
	DisplayMap();
	DisplayKey();
	DisplayCommand();
	DisplayUnits();
}

void StdScrModel::LoadMap()
{}

void StdScrModel::LoadKey()
{}

void StdScrModel::DisplayMap()
{}

void StdScrModel::DisplayKey()
{}

void StdScrModel::DisplayCommand()
{}

void StdScrModel::DisplayUnits()
{}

void StdScrModel::LoadMap( const std::string& fileName )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	Properties::ptr map = Load( fileName );
	//write_json( std::cout, *map );

	for( auto const& tiles : map->get_child( "tiles" ) )
	{
		Tile tile;

		int id = tiles.second.get<int>( "id" );
		tile.id_ = id;

		tile.terrain_ = tiles.second.get<int>( "terrain" );

		std::string display = tiles.second.get<std::string>( "display" );
		tile.terrain_representation_ = display[0];

		for( auto const& cover : tiles.second.get_child( "cover." ) ) 
		{	
			int c = cover.second.get<int>( "" );
			tile.cover_.push_back( c );
		}
	
		tiles_.push_back( tile ); 
		logger.Severity( severity_level::info, tile.ToString() );
	} 

	int row_count = 0;
	int col_count = 0;

	for( auto const& row : map->get_child( "map." ) )
	{
		logger.Severity( severity_level::info, "row_count " + boost::lexical_cast<std::string>( row_count ) );

		col_count = 0;

		for( auto const& col : row.second.get_child( "" ) ) 
		{	
			map_->map_tiles[ row_count ][ col_count ] = col.second.get<int>( "" );
			++col_count;
		}
		++row_count;
	} 

	map_->rows_ = row_count;
	map_->cols_ = col_count;
	
}

Properties::ptr StdScrModel::Load( const std::string& fileName )
{
	return Properties::ReadJson( fileName ); 
}

void StdScrModel::LoadKey( const std::string& fileName )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	key_->Load( fileName );
}

StdScrModel::map_ptr	StdScrModel::GetMap()
{
	return map_;
}

cmd_ptr StdScrModel::GetCmd()
{
	return cmd_;
}

stdscr_ikey_ptr StdScrModel::GetKey()
{
	return boost::dynamic_pointer_cast< IKey >( key_ );
}

std::vector<Tile> StdScrModel::GetTiles()
{
	return tiles_;
}

std::vector< ActorPtr > StdScrModel::GetActors()
{
	return actors_;
}

void StdScrModel::EnterOrders()
{
}

StdScrModel::line_ptr StdScrModel::ReadCommand()
{
}


void StdScrModel::NotifyObservers()
{
	for( IObserver::observer_ptr observer: observers_ )
	{
		observer->Notify();
	}
}

void StdScrModel::Register( IObserver::observer_ptr observer )
{
	observers_.push_back( observer );
}

void StdScrModel::Unregister( IObserver::observer_ptr observer )
{
	observers_.remove( observer );
}
