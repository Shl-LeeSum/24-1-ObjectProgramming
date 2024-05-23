#ifndef DECK_H
#define DECK_H

#include "Card.h"               // Card 클래스 포함


class Deck
{
private:
    Card* deck [ 52 ];          // 52장의 카드 배열    
    int currentCardIndex;       // Practice 9 추가 : 현재 뽑을 카드의 인덱스

public:
    Deck( );                    // 기본 생성자
    Deck( const Deck& origin ); // 복사 생성자
    ~Deck( );                   // 소멸자
    void printDeck( );          // 덱 전체 출력
    void suffleDeck( );         // 덱 셔플
    Card* draw();               // Practice 9 추가 : 카드 한 장 뽑기
};

#endif
