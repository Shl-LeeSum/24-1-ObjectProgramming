#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

int main( )
{
    Player* team [ 10 ];
    for ( int i = 0; i < 10; i++ )
    {
        team [ i ] = new Player( );
        std::cout << "new Player generated. " << "His Number: ";
        std::cout << team [ i ]->getPlayerNumber( );
        std::cout << " Total Players : " << team[i]->getSharedPlayerCount() << std::endl;
       
    }
    std::cout << "delete team[3] " << std::endl;
    delete team[3];
    std::cout << "Check SharedPlayerCount BY team[0]->getSharedPlayerCount() : " << team[0]->getSharedPlayerCount() << std::endl;
    std::cout << "Check SharedPlayerCount BY team[9]->getSharedPlayerCount() : " << team[9]->getSharedPlayerCount() << std::endl;



    return 0;
}