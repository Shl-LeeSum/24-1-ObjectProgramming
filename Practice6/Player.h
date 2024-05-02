#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"           // Card 클래스 포함

class Player
{
private:
    std::string name;       // 플레이어 이름
    Card* deck;             // 플레이어의 카드 덱
    int playerNum;
    static int sharedPlayerCount; // static 변수
    static int sharedPlayerNum;

public:
    // defalt
    Player( );                  // 생성자
    ~Player( ); // 소멸자

    // get
    std::string getPlayerName( ); // 플레이어 이름 가져오기
    bool checkDraw( );       // 카드 뽑기 상태 확인
    int getPlayerNumber( );

    // print
    void printPlayerDeck( );    // 플레이어 덱 출력

    // Card
    bool drawCard( Card* card ); // 카드 뽑기
    Card* discardCard( );

    // static
    static int getSharedPlayerCount( );
};

#endif