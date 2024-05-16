#include "Player.h"
#include <iostream>

int Player::sharedPlayerCount = 0;
int Player::sharedPlayerNum = 0;

// Player ������: �ʱ�ȭ
Player::Player( )
{
    this->name = "A";
    this->deck = nullptr;

    sharedPlayerCount++;
    sharedPlayerNum++;
    this->playerNum = sharedPlayerNum;
}

// Player �Ҹ���: ���� �Ҵ�� �޸� ����
Player::~Player( )
{
    if ( checkDraw( ) )
        delete this->deck;
    sharedPlayerCount--;
}

// Player ���� ī�� ����
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

// ī�� �̱�: ���� ī�� ���� �� ���� ������Ʈ
bool Player::drawCard( Card* newCard )
{
    if ( checkDraw( ) )
    {
        return false;       // ī�尡 �����Ƿ� draw���� ����.
    }
    else
    {
        this->deck = newCard; // �� ī�� ����
        return true;
    }

}