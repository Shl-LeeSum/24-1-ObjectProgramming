#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
protected:
    int number;                 // 카드 번호
    int suit;                       // 카드 문양
public:
    Card( );                        // 기본 생성자
    Card( int n , int s );      // 매개변수 있는 생성자
    ~Card( );                      // 소멸자
    void printCard( );         // 카드 정보 출력
    int operator+( const Card& card ) const;        // Practice 9 수정
    int getValue( ) const;                                      // Practice 9 추가
    int getSuit( ) const;                                        // Practice 10 추가
    std::string toString( ) const;                           // Practice 10 추가
};

#endif
