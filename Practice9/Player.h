#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>           // Practice 9 추가
#include "Card.h"           // Card 클래스 포함
#include "Deck.h"

class Player
{
protected:                  
    std::string name;       // 플레이어 이름
    // Practice 9 추가 ############################# 
    // Card* deck;              // 플레이어의 카드 덱 <- Practice 9 에서 아래와 같이 변경
    std::vector<Card*> deck;    // 플레이어의 카드 벡터
    //##############################################
    int playerNum;
    static int sharedPlayerCount; 
    static int sharedPlayerNum;
public:
    // defalt
    Player( );                      // Practice 9 수정 : 덱 초기화 수정
    ~Player( );                     // Practice 9 수정 : 덱을 순화하며 카드 삭제

    std::string getPlayerName( );
    int getPlayerNumber();

    bool checkDraw( );              // Practice 9 수정

    void printPlayerDeck( );        // Practice 9 수정
    bool drawCard( Card* card );    // Practice 9 수정 : 아래 내용으로 수정
    int getCardCount();             // Practice 9 추가 : 카드 수 가져오기
    int calculateScore() const;     // Practice 9 추가 : 카드 합 계산
    void turn(Deck& gameDeck);      // Practice 9 추가 
    Card* discardCard( );           // Practice 9 수정

    // static
    static int getSharedPlayerCount( );

};

#endif