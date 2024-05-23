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
    
    // Practice 9 추가 : 다수의 카드를 배분하는 함수 추가
    std::vector<Card*> dealCards(int numCards);
    // Practice 9 추가 : 카드 뽑는 함수
    void turn();    
    // Practice 9 추가 : Game 클래스가 private 멤버에 접근할 수 있도록
    friend class Game; 
};

#endif
