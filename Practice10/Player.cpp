#include "Player.h"
#include <iostream>

int Player::sharedPlayerCount = 0;
int Player::sharedPlayerNum = 0;


Player::Player( )
{
    this->name = "A";
    this->deck = std::vector<Card*>( );

    sharedPlayerCount++;
    sharedPlayerNum++;
    this->playerNum = sharedPlayerNum;
    this->bAborted = false;
}

Player::~Player( )
{
    for ( Card* card : deck )
    {
        delete card;
    }
    sharedPlayerCount--;
}
Card* Player::discardCard( )
{
    if ( deck.empty( ) )
        return nullptr;

    Card* returnCard = deck.back( );
    deck.pop_back( );
    return returnCard;
}

std::string Player::getPlayerName( ) { return this->name; }
int Player::getPlayerNumber( ) { return this->playerNum; }
int Player::getSharedPlayerCount( ) { return sharedPlayerCount; }
bool Player::checkDraw( ) { return !this->deck.empty( ); }

void Player::printPlayerDeck( )
{
    for ( Card* card : deck )
        card->printCard( );
}
bool Player::drawCard( Card* newCard )
{
    if ( !newCard )
        return false;

    this->deck.push_back( newCard );
    return true;
}

int Player::getCardCount( )
{
    return this->deck.size( );
}

int Player::calculateScore( ) const
{
    int score = 0;
    int aces = 0;

    for ( Card* card : deck )
    {
        int cardValue = card->getValue( );
        if ( cardValue == 1 )
        {
            aces++;
            score += 11;
        }
        else if ( cardValue > 10 )
        {
            score += 10;
        }
        else
        {
            score += cardValue;
        }
    }
    while ( score > 21 && aces > 0 )
    {
        score -= 10;
        aces--;
    }

    return score;
}

void Player::turn( Deck& gameDeck )
{
    char choice;
    do
    {
        std::cout << "Player's cards: ";
        printPlayerDeck( );
        std::cout << " (Score: " << calculateScore( ) << ")\n";

        std::cout << "Hit (h) or Stand (s) or Exit[Save Game](e)? ";
        std::cin >> choice;

        if ( choice == 'h' )
        {
            Card* newCard = gameDeck.draw( );
            drawCard( newCard );
        }
        else if ( choice == 'e' )
        {
            bAborted = true;
            return;
        }
    } while ( choice != 's' && calculateScore( ) < 21 );
}

void Player::readFromStream( std::istream& is )  // Practice 10 추가
{

    int  suit = 0 , number = 0;
    while ( suit >= 0 )
    {
        is >> suit;
        is >> number;
        if ( suit >= 0 )
        {
            this->deck.push_back( new Card( suit , number ) );
        }
    }
}

void Player::writeToStream( std::ostream& os )   // Practice 10 추가
{
    for ( Card* card : deck )
    {
        os << card->getValue( ) << " " << card->getSuit( ) << " ";
    }
    os << -1 << " " << -1 << " ";
}