#include "CardJoker.h"
#include <iostream>

CardJoker::CardJoker( )
{
    this->suit = -1;        // Joker�� ����� ����.
    this->number = 0;
}
CardJoker::~CardJoker( ) { }

void CardJoker::printCard( ) const
{
    std::cout << "JOKER" << std::endl;
}

