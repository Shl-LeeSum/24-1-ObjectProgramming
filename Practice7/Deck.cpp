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
