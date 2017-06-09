#include <iostream>
#include <ostream>

#include "actor.hpp"

int main( int argc, char** argv )
{
    Actor::Id id = 1;

    Actor   actor( 1 );

    std::cout << actor.GetId() << "\n";

    return 0;
}
