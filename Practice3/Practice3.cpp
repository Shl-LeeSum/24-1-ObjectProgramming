#include <iostream>
#include <string>
#include <cstdlib> // 랜덤 숫자 생성을 위해 추가
#include <ctime> // 시간 기반 시드 값 설정을 위해 추가
#define SUIT 0

using namespace std;

class Card {
private:
	int number;
	int suit;
public:
	Card(); // 기본 생성자 (랜덤 카드)								practice#2
	Card(int n, int s); // 추가 생성자 (카드 정보 지정) 			practice#2
	~Card();// 소멸자												practice#3

	void printCard(); // 카드정보 출력								practice#2
};
Card::Card() {
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
Card::Card(int n, int s) {
	number = n;
	suit = s;

	cout << "constructed ";
	printCard();
}
Card::~Card() {
	cout << "destructed ";
	printCard();
}
void Card::printCard() {
	string suitSymbols[] = { "CLUB", "DIAMOND", "HEART", "SPADE" };
	string suitSymbol = suitSymbols[suit];


	string numberName;
	bool isFaceOrAce = false;
	if (number == 1) {
		numberName = "Ace";
		isFaceOrAce = true;
	}
	else if (number == 11) {
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

int checkLocalVar(Card** cards) {
	cout << "[START] LOCAL variable INSIDE" << endl;
	Card localCards[3] = {Card(11,SUIT), Card(12,SUIT), Card(13,SUIT)};
	for (int i = 0; i < 3; i++) {
		cards[i + 10] = &(localCards[i]);
	}
	for (int i = 0; i < 13; i++) {
		cards[i]->printCard();
	}
	for (int i = 0; i < 3; i++) {
		cards[i + 10] = NULL;
	}
	cout << "[E N D] LOCAL variable INSIDE" << endl;

	return 0;
}


// 정적 영역 객체 생성(static), 객체 주소를 배열에 저장
Card Ace(1, SUIT);


// 메인함수 시작
int main() {
	cout << "[START] MAIN function" << endl;

	// 랜덤 시드 초기화
	srand(time(NULL));

	// Card 주소를 담을 포인터 배열 생성
	Card* cards[13];

	// 정적영역에서 생성된 객체, 포인터 배열에 저장
	cards[0] = &Ace;

	// 힙 영역 객체 생성, 객체 주소를 배열에 저장
	cout << "[START] HEAP variable" << endl;
	for (int i = 2; i <= 10; i++) {
		cards[i - 1] = new Card(i, SUIT);
	}

	// 지역 영역 객체 생성, 객체 주소를 배열에 저장 및 객체 소멸 확인
	cout << "[START] LOCAL variable OUTSIDE" << endl;
	checkLocalVar(cards);
	cout << "[E N D] LOCAL variable OUTSIDE" << endl;

	


	cout << "[E N D] MAIN function" << endl;
	return 0;
}