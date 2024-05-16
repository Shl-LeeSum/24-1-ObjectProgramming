#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"           // Card Ŭ���� ����

class Player
{
protected:                      // Plyaer�� ����ϴ� Dealer�� ���� �����ϵ��� public���� protected�� ����
    std::string name;       // �÷��̾� �̸�
    Card* deck;             // �÷��̾��� ī�� ��
    int playerNum;
    static int sharedPlayerCount; // static ����
    static int sharedPlayerNum;

public:
    // defalt
    Player( );                  // ������
    ~Player( ); // �Ҹ���

    // get
    std::string getPlayerName( ); // �÷��̾� �̸� ��������
    bool checkDraw( );       // ī�� �̱� ���� Ȯ��
    int getPlayerNumber( );

    // print
    void printPlayerDeck( );    // �÷��̾� �� ���

    // Card
    bool drawCard( Card* card ); // ī�� �̱�
    Card* discardCard( );

    // static
    static int getSharedPlayerCount( );
};

#endif