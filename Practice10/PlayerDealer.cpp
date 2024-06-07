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
void PlayerDealer::printGameDeck( ) const
{
    this->gameDeck->printDeck( );
}
std::vector<Card*> PlayerDealer::dealCards( int numCards )
{
    std::vector<Card*> cards;
    for ( int i = 0; i < numCards; ++i )
    {
        Card* card = this->gameDeck->draw( );
        if ( card != nullptr )
        {
            cards.push_back( card );
        }
    }
    return cards;
}
void PlayerDealer::turn( )
{
    while ( calculateScore( ) < 17 )
    {
        Card* newCard = gameDeck->draw( );
        drawCard( newCard );
    }
}