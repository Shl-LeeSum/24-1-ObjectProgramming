#include <iostream>
#include <string>
#include <cstdlib> // 랜덤 숫자 생성을 위해 추가
#include <ctime> // 시간 기반 시드 값 설정을 위해 추가

using namespace std;

enum Suit {
	CLUB,
	DIAMOND,
	HEART,
	SPADE
};

class Card {
private:
	int number;
	int suit;
	// Suit suit // enum Suit 사용시 변경하여 사용
public:
	Card(); // 랜덤 카드생성자
	Card(int n, int s); // 카드 정보 지정 생성자
	Card(int n, Suit s); // enum 사용 생성자

	void printCard(); // 카드정보 출력
};

Card::Card() {
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
// enum 문제시 사용
Card::Card(int n, int s) {
	number = n;
	suit = s;
}
//enum 사용 가능시 사용
Card::Card(int n, Suit s) {
	number = n;
	suit = static_cast<Suit>(rand() % 4); // int를 Suit 타입으로 캐스팅

}

void Card::printCard() {
	string suitSymbol;
	switch (suit) {
	case CLUB: suitSymbol = "CLUB"; break;
	case DIAMOND: suitSymbol = "DIAMOND"; break;
	case HEART: suitSymbol = "HEART"; break;
	case SPADE: suitSymbol = "SPADE"; break;
	}

	string numberName;
	int isFaceOrAce = false;
	if (number == 1) {
		numberName = "Ace";
		isFaceOrAce = true;
	}
	else if (number == 11){
		numberName = "Jack";
		isFaceOrAce = true;
	}
	else if (number == 12) {
		numberName = "Queen";
		isFaceOrAce = true;
	}
	else if (number == 13) {
		numberName = "King";
		isFaceOrAce = true;
	}

	if (isFaceOrAce) {
		cout << "Card: " << suitSymbol << " " << numberName << endl;
	}
	else {
		cout << "Card: " << suitSymbol << " " << number << endl;
	}
}

int main() {
	// 랜덤 시드 초기화
	srand(time(NULL));

	// 랜덤카드 생성 및 출력
	Card randomCard;
	randomCard.printCard();

	// 임의 카드 설정 생성 및 출력
	int suit;
	int number;
	
	cout << "카드 모양을 입력하시오(CLUB:0, DIAMOND:1, HEART:2, SPADE:3 ): ";
	cin >> suit;

	cout << "카드 번호를 입력하시오(1~13): ";
	cin >> number;
	if (number > 13 or number < 1 or suit < 0 or suit > 5) {
		cout << "잘못 입력하셨습니다." << endl;
	}
	else {
		Card randomCard2(number, suit);
		randomCard2.printCard();
	}

	return 0;
}