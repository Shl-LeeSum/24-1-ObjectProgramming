#include "Deck.h"

Deck::Deck( )
{	// 덱 생성 (suit별 13장씩)
    for ( int suit = 0; suit < 4; suit++ )
        for ( int number = 0; number < 13; number++ )
            this->deck [ suit * 13 + number ] = new Card( number + 1 , suit );

    this->currentCardIndex = 52 - 1;
}

Deck::Deck( const Deck& origin )
{
    for ( int count = 0; count < 52; count++ )
        this->deck [ count ] = new Card( *origin.deck [ count ] );

    this->currentCardIndex = origin.currentCardIndex;
}

Deck::~Deck( )
{
    for ( int count = 0; count <= currentCardIndex; count++ )
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

Card* Deck::draw( )
{
    if ( currentCardIndex >= 0 )
        return this->deck [ currentCardIndex-- ];
    else
        return nullptr; // 덱에 더 이상 카드가 없는 경우
}


void Deck::writeToStream( std::ostream& os )     // Practice 10 추가
{
    for ( int i = 0; i <= currentCardIndex; i++ )
    {
        Card* card = deck [ i ];
        os << card->getSuit( ) << " " << card->getValue( ) << " ";
    }
    os << -1 << " " << -1 << " ";

}

void Deck::readFromStream( std::istream& is )    // Practice 10 추가
{
// 카드덱을 초기화 한다.
    for ( int count = 0; count <= currentCardIndex; count++ )
        delete this->deck [ count ];
    this->currentCardIndex = -1;
    int suit = 0 , value;

    while ( suit >= 0 )
    {
        is >> suit >> value;
        if ( suit >= 0 )
        {
            this->currentCardIndex++;
            this->deck [ this->currentCardIndex ] = new Card( value , suit );
        }
    }
}
