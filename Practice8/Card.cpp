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

int Card::operator+( Card& card )
{
    int num1 = ( this->number > 10 ) ? 10 : this->number;
    int num2 = ( card.number > 10 ) ? 10 : card.number;

    // �� ī�� ��� ���̽��� ���
    if ( num1 == 1 && num2 == 1 )
        return 12;  // �� ī�� ��� ���̽��� ���, 21�� �ʰ����� �ʴ� �ִ� �� 12�� ��ȯ
    // num1�� ���̽��� ���
    else if ( num1 == 1 )
    {
        if ( 11 + num2 > 21 )
            return 1 + num2;
        else
            return 11 + num2;
    }
    // num2�� ���̽��� ���
    else if ( num2 == 1 )
    {
        if ( num1 + 11 > 21 )
            return num1 + 1;
        else
            return num1 + 11;
    }
     // ���̽��� ���� ��� �ܼ� �ջ�
    else
        return num1 + num2;
}
