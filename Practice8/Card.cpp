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

int Card::operator+( Card& card )
{
    int num1 = ( this->number > 10 ) ? 10 : this->number;
    int num2 = ( card.number > 10 ) ? 10 : card.number;

    // 두 카드 모두 에이스인 경우
    if ( num1 == 1 && num2 == 1 )
        return 12;  // 두 카드 모두 에이스인 경우, 21을 초과하지 않는 최대 값 12를 반환
    // num1이 에이스인 경우
    else if ( num1 == 1 )
    {
        if ( 11 + num2 > 21 )
            return 1 + num2;
        else
            return 11 + num2;
    }
    // num2가 에이스인 경우
    else if ( num2 == 1 )
    {
        if ( num1 + 11 > 21 )
            return num1 + 1;
        else
            return num1 + 11;
    }
     // 에이스가 없는 경우 단순 합산
    else
        return num1 + num2;
}
