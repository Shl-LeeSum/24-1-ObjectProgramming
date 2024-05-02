#include "Card.h"
#include <cstdlib> // 랜덤 숫자 생성을 위해
#include <ctime>   // 시간 기반 시드 값 설정을 위해

// 기본 생성자: 랜덤한 숫자와 모양으로 카드 초기화
Card::Card( )
{
    this->suit = rand( ) % 4;
    this->number = rand( ) % 13 + 1;
}

// 매개변수가 있는 생성자: 지정된 숫자와 모양으로 카드 초기화
Card::Card( int newNumber , int newSuit ) : number( newNumber ) , suit( newSuit ) { }

// 소멸자
Card::~Card( ) { }

// 카드 정보 출력
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
