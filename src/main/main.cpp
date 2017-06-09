#include <iostream>
#include <string>

#include <boost/program_options.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
namespace src = boost::log::sources;

#include "logger.hpp"
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
    		("map", po::value<std::string>(), "load map")
    		("key", po::value<std::string>(), "load map key")
    		;

        po::store( po::parse_command_line( argc, argv, desc ), vm );
        po::notify( vm );    

        if( vm.count("help") ) 
        {
            std::cout << desc << "\n";
            return false;
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

	StdScrMapController controller( vm );

	controller.Run();

    return 0;
}

