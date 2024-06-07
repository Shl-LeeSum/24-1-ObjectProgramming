#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "PlayerDealer.h"
#include <fstream>

class Game
{
private:
    PlayerDealer dealer;
    Player player;

    void dealInitialCards( );
    void showResults( );

public:
    Game( );
    void play( );
    void saveResultsToFile( const std::string& filename ); // Practice 10 추가
    bool loadResultsFromFile(const std::string& filename); // Practice 10 추가
};

#endif
