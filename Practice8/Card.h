#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
protected:
    int number; // ī�� ��ȣ
    int suit;   // ī�� ����
public:
    Card( );              // �⺻ ������
    Card( int n , int s );  // �Ű����� �ִ� ������
    ~Card( );             // �Ҹ���
    void printCard( );    // ī�� ���� ���

    // Practice 7
    int operator+( Card& card );
};

#endif
