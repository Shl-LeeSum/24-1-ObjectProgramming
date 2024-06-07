#ifndef PLAYERDEALER_H
#define PLAYERDEALER_H

#include "Player.h"
#include "Deck.h"
#include <vector>

class PlayerDealer : public Player
{
private:
    Deck* gameDeck;
public:
    PlayerDealer( );
    ~PlayerDealer( );
    void shuffleGameDeck( );
    void printGameDeck( ) const;

    std::vector<Card*> dealCards( int numCards );
    void turn( );
    friend class Game;
};

#endif
