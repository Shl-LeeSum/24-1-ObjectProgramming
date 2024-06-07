#include "Game.h"
#include <iostream>
#include <ctime>

Game::Game( )
{
    std::srand( time( 0 ) );
    dealer.shuffleGameDeck( );
}

void Game::dealInitialCards( )
{
    std::vector<Card*> playerInitialCards = dealer.dealCards( 2 );
    std::vector<Card*> dealerInitialCards = dealer.dealCards( 2 );

    for ( Card* card : playerInitialCards )
    {
        player.drawCard( card );
    }

    for ( Card* card : dealerInitialCards )
    {
        dealer.drawCard( card );
    }
}

void Game::showResults( )
{
    int playerScore = player.calculateScore( );
    int dealerScore = dealer.calculateScore( );

    std::cout << "Player's final hand: ";
    player.printPlayerDeck( );
    std::cout << " (Score: " << playerScore << ")\n";

    std::cout << "Dealer's final hand: ";
    dealer.printPlayerDeck( );
    std::cout << " (Score: " << dealerScore << ")\n";

    if ( playerScore > 21 )
    {
        std::cout << "Player busts! Dealer wins.\n";
    }
    else if ( dealerScore > 21 || playerScore > dealerScore )
    {
        std::cout << "Player wins!\n";
    }
    else if ( playerScore < dealerScore )
    {
        std::cout << "Dealer wins!\n";
    }
    else
    {
        std::cout << "It's a tie!\n";
    }
}

void Game::play( )
{
    if ( !loadResultsFromFile( "game_results.txt" ) )
    {
        dealInitialCards( );
    }
    player.turn( *dealer.gameDeck );
    if ( player.isAborted( ) )
    {
        saveResultsToFile( "game_results.txt" ); // 게임 결과 저장
        return;
    }
    dealer.turn( );
    showResults( );
    std::ofstream os( "game_results.txt" , std::ios::trunc );
}

bool Game::loadResultsFromFile( const std::string& filename ) // Practice 10 추가
{
    std::ifstream file( filename );

    if ( file.is_open( ) )
    {
        std::string start;
        int suit = 0 , value;
        file >> start;
        if ( start != "RESULT:" ) return false;
        player.readFromStream( file );
        dealer.readFromStream( file );
        dealer.gameDeck->readFromStream( file );
        return true;
    }
    return false;
}


void Game::saveResultsToFile( const std::string& filename ) // Practice 10 추가
{
    std::ofstream file( filename );

    if ( file.is_open( ) )
    {
        file << "RESULT: ";
        player.writeToStream( file );
        dealer.writeToStream( file );
        dealer.gameDeck->writeToStream( file );
        file.close( );
    }
    else
    {
        std::cerr << "Unable to open file";
    }
}