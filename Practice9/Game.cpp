#include "Game.h"
#include <iostream>
#include <ctime>

Game::Game()
{
    std::srand(time(0));
    dealer.shuffleGameDeck();
}

void Game::dealInitialCards()
{
    std::vector<Card*> playerInitialCards = dealer.dealCards(2);
    std::vector<Card*> dealerInitialCards = dealer.dealCards(2);

    for (Card* card : playerInitialCards)
    {
        player.drawCard(card);
    }

    for (Card* card : dealerInitialCards)
    {
        dealer.drawCard(card);
    }
}

void Game::showResults()
{
    int playerScore = player.calculateScore();
    int dealerScore = dealer.calculateScore();

    std::cout << "Player's final hand: ";
    player.printPlayerDeck();
    std::cout << " (Score: " << playerScore << ")\n";

    std::cout << "Dealer's final hand: ";
    dealer.printPlayerDeck();
    std::cout << " (Score: " << dealerScore << ")\n";

    if (playerScore > 21)
    {
        std::cout << "Player busts! Dealer wins.\n";
    }
    else if (dealerScore > 21 || playerScore > dealerScore)
    {
        std::cout << "Player wins!\n";
    }
    else if (playerScore < dealerScore)
    {
        std::cout << "Dealer wins!\n";
    }
    else
    {
        std::cout << "It's a tie!\n";
    }
}

void Game::play()
{
    dealInitialCards();
    player.turn(*dealer.gameDeck);
    dealer.turn();
    showResults();
}

