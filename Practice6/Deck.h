#ifndef DECK_H
#define DECK_H

#include "Card.h" // Card Ŭ���� ����

class Deck
{
private:
	Card* deck [ 52 ]; // 52���� ī�� �迭
public:
	Deck( );                 // �⺻ ������
	Deck( const Deck& origin ); // ���� ������
	~Deck( );                // �Ҹ���
	void printDeck( );       // �� ��ü ���
};

#endif
