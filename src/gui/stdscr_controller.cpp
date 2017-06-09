#include "stdscr_controller.hpp"

using namespace order;

StdScrMapController::StdScrMapController( boost::program_options::variables_map& vm )
	: 	
		model_( boost::make_shared< StdScrModel >() ),
		view_( boost::make_shared< StdScrView >( model_ ) ),
		command_( boost::make_shared< Command >() ),
		options_( vm )
{
	if( vm.count("map" ) )
	{
		mapFileName_ = options_["map"].as<std::string>();
	}
	if( vm.count("key" ) )
	{
		mapKeyFileName_ = options_["map"].as<std::string>();
	}
}

void StdScrMapController::Init()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
 
	view_->Init();
}

void StdScrMapController::Reset()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
 
	Load();
	Display();
}

void StdScrMapController::Terminate()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	view_->Terminate();
}

void StdScrMapController::Load()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	model_->LoadMap( mapFileName_ );
	model_->LoadKey( mapKeyFileName_ );
}

void StdScrMapController::Display()
{
	DisplayMap();
	DisplayKey();
	DisplayCommand();
	DisplayUnits();
}

void StdScrMapController::DisplayMap()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	StdScrModel::map_ptr map = model_->GetMap();
	std::vector< Tile > tiles = model_->GetTiles();

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
			view_->Put( row, col, tiles[ map->map_tiles[ row ][ col ] - 1 ].terrain_representation_ );
		}
	}
}

void StdScrMapController::DisplayKey()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	stdscr_ikey_ptr key = model_->GetKey();

	size_t rows = key->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		line_ptr line = key->NextLine( count );
		view_->Put( count, 100, line );
	}
}

void StdScrMapController::DisplayCommand()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	line_ptr prompt = command_->GetPrompt();
	view_->ClearLine( 40, 0, 80 );
	view_->Put( 40, 0, prompt );
}

void StdScrMapController::DisplayUnits()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	for( ActorPtr actor: 	actors_ )
	{
		boost::shared_ptr<MoveComponent> move( actor->GetComponent<MoveComponent>( std::string( "MoveComponent" ) ) );

		int x = move->GetStartX();
		int y = move->GetStartY();		

		boost::shared_ptr<RepresentationComponent> representation( actor->GetComponent<RepresentationComponent>( std::string( "RepresentationComponent" ) ) );

		char c = representation->GetChar();

		view_->Put( x, y, c );

		logger.Severity( severity_level::info, std::string("start x: ") + boost::lexical_cast<std::string>( x ) );
		logger.Severity( severity_level::info, std::string("start y: ") + boost::lexical_cast<std::string>( y ) );

		
	}
}

void StdScrMapController::Load( line_ptr command )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	split_vector_type splits;

	boost::split( splits, *command, boost::is_any_of( " " ) );

	XmlDocResource::xml_resource_ptr resource = boost::make_shared< XmlDocResource >( "deployment", splits[ 1 ] );
	resource->Load();
	cache_.Add( resource );
}

void StdScrMapController::LoadResources()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	XmlDocResource::xml_resource_ptr res = boost::static_pointer_cast< XmlDocResource >( cache_.Get( "deployment" ) );

	Properties::pointer xml = res->Get();

	pugi::xml_node map = (*xml).child( "Battle" ).child( "Map" );
	for( pugi::xml_node child: map.children() )
	{
		logger.Severity( severity_level::info, std::string( "battle.map.child: " ) + child.name() );
		logger.Severity( severity_level::info, std::string( "battle.map.child: " ) + child.child_value() );

		if( child.name() == std::string( "File" ) )
		{
			mapFileName_ = child.child_value();
		}
		if( child.name() == std::string( "Key" ) )
		{
			mapKeyFileName_ = child.child_value();
		}
		if( child.name() == std::string( "Scale" ) )
		{
			scale_ = boost::lexical_cast<float>(child.child_value());
		}

	}

	pugi::xml_node units = (*xml).child( "Battle" ).child( "Units" );
	for( pugi::xml_node unit: units.children( "Unit" ) )
	{
		logger.Severity( severity_level::info, std::string( "battle.units.unit: " ) + unit.name() );
		for( pugi::xml_node element: unit.children() )
		{
			logger.Severity( severity_level::info, std::string( "unit.child.name: "  ) + element.name() );
			logger.Severity( severity_level::info, std::string( "unit.child.value: "  ) + element.child_value() );
			if( element.name() == std::string( "Actor" ) )
			{
				ActorPtr actor = actorFactory_.CreateActor( element.child_value() );
				actors_.push_back( actor );
			}
		}
	} 
}

void StdScrMapController::EnterOrders()
{
	Dictionary dictionary;
	OrderContext orders( dictionary );
	Driver driver( orders );

	do
	{
		line_ptr order = command_->Read();

		if( *order == "end" )
		{
			break;
		}
		if( order->empty() )
		{
			continue;
		}

		orders.Clear();
		bool result = driver.ParseString( *order, "order" );
		DisplayCommand();

	} while( true );
}

void StdScrMapController::Run()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	Init();
	DisplayCommand();

	do
	{
		line_ptr command = command_->Read();
		if( *command == "end" )
		{
			break;
		}
		if( *command == "reset" )
		{
			Reset();
		}
		if( command->find( "load" ) == 0 )
		{
			Load( command );
			LoadResources();
			Init();
			Reset();
		}
		if( *command == "orders" )
		{
			EnterOrders();
		}

		DisplayCommand();
	}
	while ( true );
}

