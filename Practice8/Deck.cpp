#include "Deck.h"

Deck::Deck( )
{	// 덱 생성 (suit별 13장씩)
    for ( int suit = 0; suit < 4; suit++ )
        for ( int number = 0; number < 13; number++ )
            this->deck [ suit * 13 + number ] = new Card( number + 1 , suit );
}

Deck::Deck( const Deck& origin )
{	// 
    for ( int count = 0; count < 52; count++ )
        this->deck [ count ] = new Card( *origin.deck [ count ] );
}

Deck::~Deck( )
{
    for ( int count = 0; count < 52; count++ )
        delete this->deck [ count ];
}

void Deck::printDeck( )
{
    for ( int count = 0; count < 52; count++ )
        this->deck [ count ]->printCard( );
}

void Deck::suffleDeck( )
{
    for ( int i = 51; i > 0; i-- )
    {
        // 0부터 i까지의 랜덤한 정수를 생성
        int j = rand( ) % ( i + 1 );

        // 덱의 i번째 카드와 j번째 카드를 교환
        Card* temp = this->deck [ i ];
        this->deck [ i ] = this->deck [ j ];
        this->deck [ j ] = temp;
    }
}