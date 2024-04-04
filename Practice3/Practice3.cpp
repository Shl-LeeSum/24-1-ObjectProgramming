#include <iostream>
#include <string>
#include <cstdlib> // ���� ���� ������ ���� �߰�
#include <ctime> // �ð� ��� �õ� �� ������ ���� �߰�
#define SUIT 0

using namespace std;

class Card {
private:
	int number;
	int suit;
public:
	Card(); // �⺻ ������ (���� ī��)								practice#2
	Card(int n, int s); // �߰� ������ (ī�� ���� ����) 			practice#2
	~Card();// �Ҹ���												practice#3

	void printCard(); // ī������ ���								practice#2
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


// ���� ���� ��ü ����(static), ��ü �ּҸ� �迭�� ����
Card Ace(1, SUIT);


// �����Լ� ����
int main() {
	cout << "[START] MAIN function" << endl;

	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// Card �ּҸ� ���� ������ �迭 ����
	Card* cards[13];

	// ������������ ������ ��ü, ������ �迭�� ����
	cards[0] = &Ace;

	// �� ���� ��ü ����, ��ü �ּҸ� �迭�� ����
	cout << "[START] HEAP variable" << endl;
	for (int i = 2; i <= 10; i++) {
		cards[i - 1] = new Card(i, SUIT);
	}

	// ���� ���� ��ü ����, ��ü �ּҸ� �迭�� ���� �� ��ü �Ҹ� Ȯ��
	cout << "[START] LOCAL variable OUTSIDE" << endl;
	checkLocalVar(cards);
	cout << "[E N D] LOCAL variable OUTSIDE" << endl;

	


	cout << "[E N D] MAIN function" << endl;
	return 0;
}