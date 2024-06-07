#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card
{
protected:
    int number;                 // ī�� ��ȣ
    int suit;                       // ī�� ����
public:
    Card( );                        // �⺻ ������
    Card( int n , int s );      // �Ű����� �ִ� ������
    ~Card( );                      // �Ҹ���
    void printCard( );         // ī�� ���� ���
    int operator+( const Card& card ) const;        // Practice 9 ����
    int getValue( ) const;                                      // Practice 9 �߰�
    int getSuit( ) const;                                        // Practice 10 �߰�
    std::string toString( ) const;                           // Practice 10 �߰�
};

#endif
