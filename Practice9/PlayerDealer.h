#ifndef PLAYERDEALER_H
#define PLAYERDEALER_H

#include "Player.h"
#include "Deck.h"
#include <vector>

class PlayerDealer : public Player
{
private:
    Deck* gameDeck;
public:
    PlayerDealer();
    ~PlayerDealer();
    void shuffleGameDeck();
    void printGameDeck() const;
    
    // Practice 9 �߰� : �ټ��� ī�带 ����ϴ� �Լ� �߰�
    std::vector<Card*> dealCards(int numCards);
    // Practice 9 �߰� : ī�� �̴� �Լ�
    void turn();    
    // Practice 9 �߰� : Game Ŭ������ private ����� ������ �� �ֵ���
    friend class Game; 
};

#endif
