#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <cstddef>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>

#include <boost/smart_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>



namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;



enum severity_level
{
    info,
    warning,
    error,
    fatal,
    debug
};



class Log
{

public:

    typedef src::severity_logger< severity_level > slogger;

    Log()
    {
	Init();
    }

    void Severity( severity_level severity, const std::string& message );
    void Tagged( severity_level security, const std::string& tag, const std::string& message );    
    slogger TimedStart( severity_level severity, const std::string& message );
    void TimedEnd( severity_level severity, slogger logger, const std::string& message );

private:

    void Init();

};


#endif
