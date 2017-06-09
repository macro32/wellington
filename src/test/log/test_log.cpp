#include <iostream>
#include <fstream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/logger.hpp>



namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;





void init_log_sink()
{
    // construct the sink
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
    boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();

    // Add a stream to write log to
    sink->locked_backend()->add_stream(
        boost::make_shared< std::ofstream >("sample.log"));

    // Register the sink in the logging core
    logging::core::get()->add_sink(sink);
}

void init_log()
{
    logging::add_file_log
    (
        keywords::file_name = "sample_%N.log",                                        /*< file name pattern >*/
        keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
    );

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );
}

void init()
{
    boost::log::core::get()->set_filter
    (
        boost::log::trivial::severity >= boost::log::trivial::info
    );
}

void boost_trivial_init_log_sink()
{
    init_log_sink();

    src::logger lg;
    BOOST_LOG(lg) << "Hello world!";
}

void boost_trivial_init_log()
{
    init_log();
    logging::add_common_attributes();

    using namespace logging::trivial;
    src::severity_logger< severity_level > lg;

    BOOST_LOG_SEV(lg, trace) << "A trace severity message";
    BOOST_LOG_SEV(lg, debug) << "A debug severity message";
    BOOST_LOG_SEV(lg, info) << "An informational severity message";
    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
    BOOST_LOG_SEV(lg, error) << "An error severity message";
    BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";
}


void boost_trivial_init()
{
    init();

    BOOST_LOG_TRIVIAL( trace ) << "A trace message";
    BOOST_LOG_TRIVIAL( debug ) << "A debug message";
    BOOST_LOG_TRIVIAL( info ) << "A info message";
    BOOST_LOG_TRIVIAL( warning ) << "A warning message";
    BOOST_LOG_TRIVIAL( error ) << "A error message";
    BOOST_LOG_TRIVIAL( fatal ) << "A fatal message";
}

void boost_trivial()
{
    BOOST_LOG_TRIVIAL( trace ) << "A trace message";
    BOOST_LOG_TRIVIAL( debug ) << "A debug message";
    BOOST_LOG_TRIVIAL( info ) << "A info message";
    BOOST_LOG_TRIVIAL( warning ) << "A warning message";
    BOOST_LOG_TRIVIAL( error ) << "A error message";
    BOOST_LOG_TRIVIAL( fatal ) << "A fatal message";
}


int main( int argc, char** argv )
{
    std::cout << "test log..." << std::endl;

    boost_trivial();

    std::cout << "\n\n";

    boost_trivial_init();

    std::cout << "\n\n";

    boost_trivial_init_log();

    std::cout << "\n\n";

    boost_trivial_init_log_sink();

    return 0;
}
