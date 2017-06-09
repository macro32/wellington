#include "logger.hpp"



BOOST_LOG_ATTRIBUTE_KEYWORD( line_id, "LineID", unsigned int )
BOOST_LOG_ATTRIBUTE_KEYWORD( severity, "Severity", severity_level )
BOOST_LOG_ATTRIBUTE_KEYWORD( tag_attr, "Tag", std::string )
BOOST_LOG_ATTRIBUTE_KEYWORD( scope, "Scope", attrs::named_scope::value_type )
BOOST_LOG_ATTRIBUTE_KEYWORD( timeline, "Timeline", attrs::timer::value_type )


// use this for Named Scope logging by preceding it with BOOST_LOG_NAMED_SCOPE( "scope" );
void Log::Severity( severity_level severity, const std::string& message )
{
    src::severity_logger< severity_level > slg;

    BOOST_LOG_SEV(slg, severity) << message;
}



void Log::Tagged( severity_level severity, const std::string& tag, const std::string& message )
{
    src::severity_logger< severity_level > slg;
    slg.add_attribute("Tag", attrs::constant< std::string >( tag ));

    BOOST_LOG_SEV( slg, severity ) << message;
}



Log::slogger Log::TimedStart( severity_level severity, const std::string& message )
{
    BOOST_LOG_SCOPED_THREAD_ATTR( "Timeline", attrs::timer() );

    src::severity_logger< severity_level > slg;
    BOOST_LOG_SEV( slg, severity ) << message;

    return slg;
}



void Log::TimedEnd( severity_level severity, slogger slg, const std::string& message )
{
    BOOST_LOG_SEV( slg, severity ) << message;
}



std::ostream& operator<< (std::ostream& strm, severity_level level)
{
    static const char* strings[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };

    if (static_cast< std::size_t >(level) < sizeof(strings) / sizeof(*strings))
        strm << strings[level];
    else
        strm << static_cast< int >(level);

    return strm;
}



void Log::Init()
{
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
    boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();

    sink->locked_backend()->add_stream(
        boost::make_shared< std::ofstream >("wellington.log"));

    sink->set_formatter
    (
        expr::stream
            << std::hex << std::setw(8) << std::setfill('0') << line_id << std::dec << std::setfill(' ')
            << ": <" << severity << ">\t"
            << "(" << scope << ") "
            << expr::if_( expr::has_attr(tag_attr) )
               [
                    expr::stream << "[" << tag_attr << "] "
               ]
            << expr::if_( expr::has_attr(timeline) )
               [
                    expr::stream << "[" << timeline << "] "
               ]
            << expr::smessage
    );

    logging::core::get()->add_sink(sink);

    logging::add_common_attributes();

    //logging::core::get()->add_global_attribute("Scope", attrs::named_scope());
}
