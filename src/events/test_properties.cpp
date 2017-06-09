#include <iostream>
#include <ostream>

#include <boost/foreach.hpp>

#include "properties.hpp"

int main( int argc, char** argv )
{
    Properties::ptr p = Properties::ReadXml( "ptree.xml" );
    write_xml( std::cout, *p );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*p).get_child("Actor") )
    {
        std::cout << "ptree.xml : actor : " << v.first << "\n";
    }

    p = Properties::ReadJson( "ptree.json" );
    write_json( std::cout, *p );

    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, (*p).get_child("units") )
    {
        std::cout << "ptree.json : units : " << v.first << "\n";
        BOOST_FOREACH( boost::property_tree::ptree::value_type &vc, v.second )
        {
            std::cout << "    vc.first : " << vc.first << "\n";
            BOOST_FOREACH( boost::property_tree::ptree::value_type &vcc, vc.second )
            {
                std::cout << "        vcc.first : " << vcc.first <<  " : vcc.second.data() : " << vcc.second.data() << "\n";
            } 
        } 
    }

    return 0;
}
