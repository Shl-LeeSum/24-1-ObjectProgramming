#include "Card.h"
#include <cstdlib> // ���� ���� ������ ����
#include <ctime>   // �ð� ��� �õ� �� ������ ����

// �⺻ ������: ������ ���ڿ� ������� ī�� �ʱ�ȭ
Card::Card( )
{
    this->suit = rand( ) % 4;
    this->number = rand( ) % 13 + 1;
}

// �Ű������� �ִ� ������: ������ ���ڿ� ������� ī�� �ʱ�ȭ
Card::Card( int newNumber , int newSuit ) : number( newNumber ) , suit( newSuit ) { }

// �Ҹ���
Card::~Card( ) { }

// ī�� ���� ���
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
