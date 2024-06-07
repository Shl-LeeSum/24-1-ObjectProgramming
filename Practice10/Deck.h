#ifndef DECK_H
#define DECK_H

#include "Card.h"             


class Deck
{
private:
    Card* deck [ 52 ];
    int currentCardIndex;

public:
    Deck( );
    Deck( const Deck& origin );
    ~Deck( );
    void printDeck( );
    void suffleDeck( );
    Card* draw( );
    void readFromStream( std::istream& is );  //Practice 10 추가
    void writeToStream( std::ostream& os );    //Practice 10 추가
};

#endif
