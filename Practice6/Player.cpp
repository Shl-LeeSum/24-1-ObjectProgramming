#include "Player.h"
#include <iostream>

int Player::sharedPlayerCount = 0;
int Player::sharedPlayerNum = 0;

// Player 생성자: 초기화
Player::Player( )
{
    this->name = "A";
    this->deck = nullptr;

    sharedPlayerCount++;
    sharedPlayerNum++;
    this->playerNum = sharedPlayerNum;
}

// Player 소멸자: 동적 할당된 메모리 정리
Player::~Player( )
{
    if ( checkDraw( ) )
        delete this->deck;
    sharedPlayerCount--;
}

// Player 보유 카드 삭제
Card* Player::discardCard( )
{
    Card* returnCard = this->deck;
    this->deck = nullptr;
    return returnCard;
}

// get Private Var
std::string Player::getPlayerName( ) { return this->name; }
bool Player::checkDraw( ) { return this->deck != nullptr; }
int Player::getPlayerNumber( ) { return this->playerNum; }
int Player::getSharedPlayerCount( ) { return sharedPlayerCount; }

// print Player Deck
void Player::printPlayerDeck( )
{
    if ( checkDraw( ) )
    {
        this->deck->printCard( );
    }
}

// 카드 뽑기: 랜덤 카드 생성 및 정보 업데이트
bool Player::drawCard( Card* newCard )
{
    if ( checkDraw( ) )
    {
        return false;       // 카드가 있으므로 draw하지 않음.
    }
    else
    {
        this->deck = newCard; // 새 카드 생성
        return true;
    }

}