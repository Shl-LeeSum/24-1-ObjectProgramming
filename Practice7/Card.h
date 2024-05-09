#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
private:
    int number; // 카드 번호
    int suit;   // 카드 문양
public:
    Card( );              // 기본 생성자
    Card( int n , int s );  // 매개변수 있는 생성자
    ~Card( );             // 소멸자
    void printCard( );    // 카드 정보 출력

    // Practice 7
    int operator+( Card& card );
};

#endif
