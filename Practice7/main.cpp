#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main( )
{
    Card* c1 = new Card( );
    Card* c2 = new Card( );

    int sum = *c1 + *c2;  // 카드의 합을 계산

    cout << "c1 : ";
    c1->printCard( );

    cout << "c2 : ";
    c2->printCard( );

    cout << "Sum of c1 and c2: " << sum << endl;  // 계산된 합을 출력

    return 0;
}
