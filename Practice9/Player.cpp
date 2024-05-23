#include "Player.h"
#include <iostream>

int Player::sharedPlayerCount = 0;
int Player::sharedPlayerNum = 0;

// Player ������: �ʱ�ȭ
Player::Player( )
{
    this->name = "A";

    // Practice 9 ����
    // this->deck = nullptr;
    // ���� �� ���ͷ� �ʱ�ȭ
    this->deck = std::vector<Card*>();

    sharedPlayerCount++;
    sharedPlayerNum++;
    this->playerNum = sharedPlayerNum;
}

/* Practice 9 ����
 * ����
 * Player �Ҹ���: ���� �Ҵ�� �޸� ���� 
Player::~Player( )
{
    if ( checkDraw( ) )
        delete this->deck;
    sharedPlayerCount--;
}
* ������ */
// Player �Ҹ���: ���� �Ҵ�� �޸� ����
Player::~Player()
{
    // ���� �ִ� ��� ī���� �޸� ����
    for (Card* card : deck)
    {
        delete card;
    }
    sharedPlayerCount--;
}
/* Practice 9 ���� : ����
// Player ���� ī�� ����
Card* Player::discardCard( )
{
    Card* returnCard = this->deck;
    this->deck = nullptr;
    return returnCard;
}
* ������ */
// Player ���� ī�� ����
Card* Player::discardCard()
{
    if (deck.empty())
        return nullptr;

    // ������ ������ ī�带 �����ϰ� ��ȯ
    Card* returnCard = deck.back();
    deck.pop_back();
    return returnCard;
}

// get Private Var
std::string Player::getPlayerName( ) { return this->name; }
int Player::getPlayerNumber() { return this->playerNum; }
int Player::getSharedPlayerCount() { return sharedPlayerCount; }
/* Practice 9 ����
 * ���� ��
 * bool Player::checkDraw( ) { return this->deck != nullptr; }
 * ���� �� */
bool Player::checkDraw() { return !this->deck.empty(); }

/* ���� ��
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
        return false;       // ī�尡 �����Ƿ� draw���� ����.
    }
    else
    {
        this->deck = newCard; // �� ī�� ����
        return true;
    }

}
 * ���� �� */
void Player::printPlayerDeck()
{
    for (Card* card : deck)
        card->printCard();
}
bool Player::drawCard(Card* newCard)
{
    if (!newCard)
        return false; // null ī��� �߰����� ����

    this->deck.push_back(newCard);
    return true;
}

//  Practice 9 �߰�
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