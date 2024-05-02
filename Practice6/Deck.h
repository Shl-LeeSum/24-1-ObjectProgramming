#ifndef DECK_H
#define DECK_H

#include "Card.h" // Card 클래스 포함

class Deck
{
private:
	Card* deck [ 52 ]; // 52장의 카드 배열
public:
	Deck( );                 // 기본 생성자
	Deck( const Deck& origin ); // 복사 생성자
	~Deck( );                // 소멸자
	void printDeck( );       // 덱 전체 출력
};

#endif
