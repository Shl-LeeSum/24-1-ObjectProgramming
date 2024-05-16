#include "PlayerDealer.h"

PlayerDealer::PlayerDealer( )
{
    this->name = "Dealer";
    this->gameDeck = new Deck( );
}
PlayerDealer::~PlayerDealer( )
{
    delete this->gameDeck;
}

void PlayerDealer::shuffleGameDeck( )
{
    this->gameDeck->suffleDeck( );
}
void PlayerDealer::printGameDeck( )
{
    this->gameDeck->printDeck( );
}
