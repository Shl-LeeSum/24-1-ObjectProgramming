#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>            
#include "Card.h"          
#include "Deck.h"

class Player
{
protected:
    std::string name;
    std::vector<Card*> deck;
    int playerNum;
    static int sharedPlayerCount;
    static int sharedPlayerNum;
    bool bAborted = false;
public:
    Player( );
    ~Player( );

    std::string getPlayerName( );
    int getPlayerNumber( );

    bool checkDraw( );

    void printPlayerDeck( );
    bool drawCard( Card* card );
    int getCardCount( );
    int calculateScore( ) const;
    void turn( Deck& gameDeck );
    Card* discardCard( );

    static int getSharedPlayerCount( );

    bool isAborted( ) { return bAborted; }       // Practice 10 추가

    void readFromStream( std::istream& is );  // Practice 10 추가
    void writeToStream( std::ostream& os );  // Practice 10 추가
};

#endif