#include <iostream>
#include "Card.h"
#include "CardJoker.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerDealer.h"
using namespace std;

int main( )
{
    srand( time( 0 ) );

    Card card;
    cout << "Print Test Card  : ";
    card.printCard( );

    CardJoker joker;
    cout << "Print Joker Card : ";
    joker.printCard( );

    cout << "Sum of Number    : ";
    cout << card + joker << endl;


    cout << "\n\n";
    cout << "Check dealer's game deck." << endl;
    PlayerDealer dealer;

    cout << "================" << endl;
    cout << "Before shuffle." << endl;
    dealer.printGameDeck( );
    cout << "================" << endl;
    cout << "After shuffle." << endl;
    dealer.shuffleGameDeck( );
    dealer.printGameDeck( );
    return 0;
}
