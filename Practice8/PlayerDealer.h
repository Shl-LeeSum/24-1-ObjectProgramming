#ifndef PLAYERDECK_H
#define PLAYERDECK_H
#include "Player.h"
#include "Deck.h"

class PlayerDealer : public Player , Deck
{
private:
    Deck* gameDeck;
public:
    PlayerDealer( );
    ~PlayerDealer( );
    void shuffleGameDeck( );
    void printGameDeck( );
};
#endif