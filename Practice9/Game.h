#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "PlayerDealer.h"

class Game
{
private:
    PlayerDealer dealer;
    Player player;

    void dealInitialCards();
    void showResults();
public:
    Game();
    void play();
};

#endif
