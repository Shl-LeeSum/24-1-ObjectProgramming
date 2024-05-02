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

    return 0;
}