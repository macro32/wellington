#include <iostream>

#include "actor_factory.hpp"

Log logger;

int main( int argc, char** argv )
{

    std::cout << "starting test actor factory...." << std::endl;

    ActorFactory    actorFactory;

    std::cout << "wellington..." << std::endl;
    ActorPtr wellington = actorFactory.CreateActor( "Wellington.xml" );

    std::cout << "20th Regiment of Foot..." << std::endl;
    ActorPtr line20thFoot = actorFactory.CreateActor( "20thFoot.xml" );

    std::cout << "Scots Greys..." << std::endl;
    ActorPtr heavyCavalryScotsGreys = actorFactory.CreateActor( "ScotsGreys.xml" );

    std::cout << "95th Rifles..." << std::endl;
    ActorPtr rifles92ndRifles = actorFactory.CreateActor( "95thRifles.xml" );
    
    std::cout << "test actor factory completed." << std::endl;

    return 0;
}
