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

    // Practice 9 ����
    int operator+( const Card& card ) const;
    // Practice 9 �߰�
    int getValue() const ;
};

#endif
