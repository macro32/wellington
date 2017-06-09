#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>

#include "stdscr_ikey.hpp"
#include "stdscr_imodel.hpp"
#include "iobserver.hpp"

#include "logger.hpp"

#include "properties.hpp"
#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"
#include "tile.hpp"

#include "actor_factory.hpp"
#include "resource_cache.hpp"
#include "stdscr_view.hpp"


extern Log logger;


class StdScrModel : public StdScrIModel, public ISubject
{

public:

	enum State
	{
		Initial,
		OrderEntry
	};

	typedef boost::shared_ptr< StdScrModel > model_ptr;

	typedef boost::shared_ptr< std::string > line_ptr;

	typedef boost::shared_ptr< Map > map_ptr;
	typedef boost::shared_ptr< Key > key_ptr;
	//typedef boost::shared_ptr< Command > cmd_ptr;

	StdScrModel();

	virtual void Init();
	virtual void Reset();
	virtual void Terminate();

	virtual void Load();
	virtual void Display();

	virtual void LoadMap();
	virtual void LoadKey();

	virtual void DisplayMap();
	virtual void DisplayKey();
	virtual void DisplayCommand();
	virtual void DisplayUnits();

	virtual void LoadMap( const std::string& fileName );
	virtual void LoadKey( const std::string& fileName );

	Properties::ptr Load( const std::string& fileName );

	virtual map_ptr	GetMap();
	virtual cmd_ptr GetCmd();
	virtual stdscr_ikey_ptr GetKey();

	virtual std::vector<Tile> GetTiles();
	virtual std::vector< ActorPtr > GetActors();

	void EnterOrders();
	line_ptr ReadCommand();

	virtual void NotifyObservers();
	virtual void Register( IObserver::observer_ptr observer );
	virtual void Unregister( IObserver::observer_ptr observer );

private:

	map_ptr map_;
	key_ptr key_;
	cmd_ptr cmd_;

	std::vector< Tile > tiles_;
	std::vector< ActorPtr > actors_;

	ActorFactory actorFactory_;

	ResourceCache cache_;
	
	std::string mapFilename_;
	std::string mapKeyFilename_;
	float scale_;

	boost::shared_ptr< boost::program_options::variables_map > options_;

	StdScrView::view_ptr view_;

	ISubject::observer_data observers_;
	
};

#endif

