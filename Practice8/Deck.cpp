#include "Deck.h"

Deck::Deck( )
{	// �� ���� (suit�� 13�徿)
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
        // 0���� i������ ������ ������ ����
        int j = rand( ) % ( i + 1 );

        // ���� i��° ī��� j��° ī�带 ��ȯ
        Card* temp = this->deck [ i ];
        this->deck [ i ] = this->deck [ j ];
        this->deck [ j ] = temp;
    }
}