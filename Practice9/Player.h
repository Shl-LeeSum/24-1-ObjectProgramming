#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>           // Practice 9 �߰�
#include "Card.h"           // Card Ŭ���� ����
#include "Deck.h"

class Player
{
protected:                  
    std::string name;       // �÷��̾� �̸�
    // Practice 9 �߰� ############################# 
    // Card* deck;              // �÷��̾��� ī�� �� <- Practice 9 ���� �Ʒ��� ���� ����
    std::vector<Card*> deck;    // �÷��̾��� ī�� ����
    //##############################################
    int playerNum;
    static int sharedPlayerCount; 
    static int sharedPlayerNum;
public:
    // defalt
    Player( );                      // Practice 9 ���� : �� �ʱ�ȭ ����
    ~Player( );                     // Practice 9 ���� : ���� ��ȭ�ϸ� ī�� ����

    std::string getPlayerName( );
    int getPlayerNumber();

    bool checkDraw( );              // Practice 9 ����

    void printPlayerDeck( );        // Practice 9 ����
    bool drawCard( Card* card );    // Practice 9 ���� : �Ʒ� �������� ����
    int getCardCount();             // Practice 9 �߰� : ī�� �� ��������
    int calculateScore() const;     // Practice 9 �߰� : ī�� �� ���
    void turn(Deck& gameDeck);      // Practice 9 �߰� 
    Card* discardCard( );           // Practice 9 ����

    // static
    static int getSharedPlayerCount( );

};

#endif