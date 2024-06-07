#include "Card.h"
#include <cstdlib> 
#include <ctime>  

Card::Card( )
{
    this->suit = rand( ) % 4;
    this->number = rand( ) % 13 + 1;
}

Card::Card( int newNumber , int newSuit ) : number( newNumber ) , suit( newSuit ) { }

Card::~Card( )
{ }

void Card::printCard( )
{
    std::string suitSymbols[ ] = { "CLUB", "DIAMOND", "HEART", "SPADE" };
    std::string numberName;
    bool isFaceOrAce = false;
    if ( this->number == 1 )
    {
        numberName = "Ace";
        isFaceOrAce = true;
    }
    else if ( this->number == 11 )
    {
        numberName = "Jack";
        isFaceOrAce = true;
    }
    else if ( this->number == 12 )
    {
        numberName = "Queen";
        isFaceOrAce = true;
    }
    else if ( this->number == 13 )
    {
        numberName = "King";
        isFaceOrAce = true;
    }
    // case: FaceOrAce | number
    if ( isFaceOrAce )
    {
        std::cout << suitSymbols [ suit ] << " " << numberName << std::endl;
    }
    else
    {
        std::cout << suitSymbols [ suit ] << " " << this->number << std::endl;
    }
}

int Card::operator+( const Card& card ) const
{
    return this->number + card.number;
}

int Card::getValue( ) const
{
    return this->number;
}

// Practice 10 추가
int Card::getSuit( ) const
{
    return this->suit;
}
// Practice 10 추가
std::string Card::toString( ) const
{
    std::string suitSymbols[ ] = { "CLUB", "DIAMOND", "HEART", "SPADE" };
    std::string numberName;
    if ( this->number == 1 )
    {
        numberName = "Ace";
    }
    else if ( this->number == 11 )
    {
        numberName = "Jack";
    }
    else if ( this->number == 12 )
    {
        numberName = "Queen";
    }
    else if ( this->number == 13 )
    {
        numberName = "King";
    }
    else
    {
        numberName = std::to_string( this->number );
    }
    return suitSymbols [ suit ] + " " + numberName;
}