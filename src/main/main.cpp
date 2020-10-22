#include <iostream>
#include <string>

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/program_options.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
namespace src = boost::log::sources;

#include "logger.hpp"
#include "config.hpp"
#include "stdscr_controller.hpp"

namespace po = boost::program_options;
po::options_description desc("Allowed options");
po::variables_map vm;

Log	logger;

bool program_options( int argc, char** argv )
{
	try
	{
        po::options_description desc("Allowed options");
		desc.add_options()
    		("help", "help message")
		("battle", po::value<std::string>(), "load battle file (xml)")
    		("map", po::value<std::string>(), "load map file (json)")
    		("key", po::value<std::string>(), "load map key (txt)")
    		;

        po::store( po::parse_command_line( argc, argv, desc ), vm );
        po::notify( vm );    

        if( vm.count("help") ) 
        {
            std::cout << desc << "\n";
            return false;
        }
        if( vm.count("battle") ) 
        {
            std::cout << "battle details read from '" 
                      << vm["battle"].as<std::string>() << "'.\n";
        } 
        else 
        {
            std::cout << "no battle specified.\n";
        }

        if( vm.count("map") ) 
        {
            std::cout << "map details read from '" 
                      << vm["map"].as<std::string>() << "'.\n";
        } 
        else 
        {
            std::cout << "no map specified.\n";
        }
    }
    catch( const std::exception& e )
    {
        std::cout << "error : " << e.what() << std::endl;
        return false; 
    }
	return true;
}

int main( int argc, char** argv )
{
	logger.Severity( severity_level::info, "main()" );

	if( !program_options( argc, argv ) )
	{
		exit(1);
	}

	Config config( vm["map"].as<std::string>() );
	config.Load();

	StdScrMapController controller( vm );

	controller.Run();

    return 0;
}

