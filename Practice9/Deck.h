#ifndef DECK_H
#define DECK_H

#include "Card.h"               // Card Ŭ���� ����


class Deck
{
private:
    Card* deck [ 52 ];          // 52���� ī�� �迭    
    int currentCardIndex;       // Practice 9 �߰� : ���� ���� ī���� �ε���

public:
    Deck( );                    // �⺻ ������
    Deck( const Deck& origin ); // ���� ������
    ~Deck( );                   // �Ҹ���
    void printDeck( );          // �� ��ü ���
    void suffleDeck( );         // �� ����
    Card* draw();               // Practice 9 �߰� : ī�� �� �� �̱�
};

#endif
