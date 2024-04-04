#include <iostream>
#include <string>

// ���� ���� ������ ���� �߰�
#include <cstdlib>
// �ð� ��� �õ� �� ������ ���� �߰�
#include <ctime> 
using namespace std;

class Card {
private:
	int number;
	int suit;
public:
	Card(); // ���� ī�������
	Card(int n, int s); // ī�� ���� ���� ������

	void printCard(); // ī������ ���
};
Card::Card() {
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
Card::Card(int n, int s) {
	number = n;
	suit = s;
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

int main() {
	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// ����ī�� ���� �� ���
	Card randomCard;
	randomCard.printCard();

	// ���� ī�� ���� ���� �� ���
	int suit;
	int number;

	cout << "ī�� ����� �Է��Ͻÿ�(CLUB:0, DIAMOND:1, HEART:2, SPADE:3 ): ";
	cin >> suit;

	cout << "ī�� ��ȣ�� �Է��Ͻÿ�(1~13): ";
	cin >> number;
	if (number < 1 || number > 13 || suit < 0 || suit > 3) {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	else {
		Card randomCard2(number, suit);
		randomCard2.printCard();
	}

	return 0;
}