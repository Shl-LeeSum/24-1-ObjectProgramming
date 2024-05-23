#include "Player.h"
#include <iostream>

int Player::sharedPlayerCount = 0;
int Player::sharedPlayerNum = 0;

// Player 생성자: 초기화
Player::Player( )
{
    this->name = "A";

    // Practice 9 수정
    // this->deck = nullptr;
    // 덱을 빈 벡터로 초기화
    this->deck = std::vector<Card*>();

    sharedPlayerCount++;
    sharedPlayerNum++;
    this->playerNum = sharedPlayerNum;
}

/* Practice 9 수정
 * 기존
 * Player 소멸자: 동적 할당된 메모리 정리 
Player::~Player( )
{
    if ( checkDraw( ) )
        delete this->deck;
    sharedPlayerCount--;
}
* 수정후 */
// Player 소멸자: 동적 할당된 메모리 정리
Player::~Player()
{
    // 덱에 있는 모든 카드의 메모리 해제
    for (Card* card : deck)
    {
        delete card;
    }
    sharedPlayerCount--;
}
/* Practice 9 수정 : 기존
// Player 보유 카드 삭제
Card* Player::discardCard( )
{
    Card* returnCard = this->deck;
    this->deck = nullptr;
    return returnCard;
}
* 수정후 */
// Player 보유 카드 삭제
Card* Player::discardCard()
{
    if (deck.empty())
        return nullptr;

    // 덱에서 마지막 카드를 제거하고 반환
    Card* returnCard = deck.back();
    deck.pop_back();
    return returnCard;
}

// get Private Var
std::string Player::getPlayerName( ) { return this->name; }
int Player::getPlayerNumber() { return this->playerNum; }
int Player::getSharedPlayerCount() { return sharedPlayerCount; }
/* Practice 9 수정
 * 수정 전
 * bool Player::checkDraw( ) { return this->deck != nullptr; }
 * 수정 후 */
bool Player::checkDraw() { return !this->deck.empty(); }

/* 수정 전
void Player::printPlayerDeck( )
{
    if ( checkDraw( ) )
    {
        this->deck->printCard( );
    }
}
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
 * 수정 후 */
void Player::printPlayerDeck()
{
    for (Card* card : deck)
        card->printCard();
}
bool Player::drawCard(Card* newCard)
{
    if (!newCard)
        return false; // null 카드는 추가하지 않음

    this->deck.push_back(newCard);
    return true;
}

//  Practice 9 추가
int Player::getCardCount()
{
    return this->deck.size();
}

int Player::calculateScore() const
{
    int score = 0;
    int aces = 0;

    for (Card* card : deck)
    {
        int cardValue = card->getValue();
        if (cardValue == 1) // Ace
        {
            aces++;
            score += 11;
        }
        else if (cardValue > 10) // Face cards
        {
            score += 10;
        }
        else
        {
            score += cardValue;
        }
    }

    // Adjust for Aces if score exceeds 21
    while (score > 21 && aces > 0)
    {
        score -= 10;
        aces--;
    }

    return score;
}

void Player::turn(Deck& gameDeck)
{
    char choice;
    do
    {
        std::cout << "Player's cards: ";
        printPlayerDeck();
        std::cout << " (Score: " << calculateScore() << ")\n";

        std::cout << "Hit (h) or Stand (s)? ";
        std::cin >> choice;

        if (choice == 'h')
        {
            Card* newCard = gameDeck.draw();
            drawCard(newCard);
        }
    } while (choice != 's' && calculateScore() < 21);
}