#include <iostream>
#include <string>
#include <cstdlib> // ���� ���� ������ ���� �߰�
#include <ctime>   // �ð� ��� �õ� �� ������ ���� �߰�

using namespace std;

// Card Ŭ����: ī�� �� ���� ��Ÿ��
class Card{
private:
	int number; // ī���� ���� (1~13, Ace, Jack, Queen, King�� ����)
	int suit;	// ī���� ��� (0: CLUB, 1: DIAMOND, 2: HEART, 3: SPADE)
public:
	Card();				// ���� ī�������
	Card(int n, int s); // ī�� ���� ���� ������
	~Card();			// �Ҹ���

	void printCard(); // ī������ ���
};
// �⺻ ������: ������ ���ڿ� ������� ī�� �ʱ�ȭ
Card::Card(){
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
// �Ű������� �ִ� ������: ������ ���ڿ� ������� ī�� �ʱ�ȭ
Card::Card(int n, int s){
	number = n;
	suit = s;
}
// �Ҹ���
Card::~Card() {}

// ī�� ���� ���
void Card::printCard(){
	string suitSymbols[] = { "CLUB", "DIAMOND", "HEART", "SPADE" };
	string suitSymbol = suitSymbols[suit];

	string numberName;
	bool isFaceOrAce = false;
	if (number == 1) {
		numberName = "Ace";
		isFaceOrAce = true;
	}
	else if (number == 11)	{
		numberName = "Jack";
		isFaceOrAce = true;
	}
	else if (number == 12)	{
		numberName = "Queen";
		isFaceOrAce = true;
	}
	else if (number == 13)	{
		numberName = "King";
		isFaceOrAce = true;
	}

	if (isFaceOrAce)	{
		cout << "Card: " << suitSymbol << " " << numberName << endl;
	}
	else	{
		cout << "Card: " << suitSymbol << " " << number << endl;
	}
}

// Player Ŭ����: �÷��̾ ��Ÿ��
class Player{
private:
	string name;
	Card* deck; // �÷��̾ ���� ī��
public:
	Player();
	~Player(); // �Ҹ���

	string getPlayerName();
	void printPlayerDeck();
	bool getDrawCheck();
	bool drawCard(Card* card);
	// Card* discardCard();
};

// Player ������: �ʱ�ȭ
Player::Player(){
	name = "A";
	deck = NULL;
}
// Player �Ҹ���: ���� �Ҵ�� �޸� ����
Player::~Player(){
	if (getDrawCheck())
		delete deck;
}



string Player::getPlayerName() { return name; }

bool Player::getDrawCheck() { return deck != nullptr; }
void Player::printPlayerDeck(){
	if (getDrawCheck())	{
		cout << this->getPlayerName() + "�� ���� ī�带 ������ �ֽ��ϴ�.";
		this->deck->printCard();
	}
}

// ī�� �̱�: ���� ī�� ���� �� ���� ������Ʈ
bool Player::drawCard(Card* card){
	if (getDrawCheck()) {
		cout << this->getPlayerName() + "�� �̹� ī�带 �̾ҽ��ϴ�.";
		return false;
	}

	cout << this->getPlayerName() + "�� ���� ī�带 �̾ҽ��ϴ�.";
	card->printCard();

	deck = card; // �� ī�� ����
	return true;
}


class Deck {
private:
	Card* deck[52];

public:
	Deck();
	Deck(const Deck& origin);
	~Deck();

	void printDeck();
};

Deck::Deck() {
	for (int suit = 0; suit < 4; suit++)
		for (int number = 0; number < 13; number++) 
			this->deck[suit*13 + number] = new Card(number+1, suit);
}
Deck::Deck(const Deck& origin) {
	for (int count = 0; count < 52; count++)
		this->deck[count] = origin.deck[count];
}
Deck::~Deck() {
	for (int count = 0; count < 52; count++)
		delete this->deck[count];
}
void Deck::printDeck() {
	for (int count = 0; count < 52; count++)
		this->deck[count]->printCard();
}
int main(){
	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	Deck deck1;
	deck1.printDeck();

	cout << "========================" << endl;
	Deck* deck2 = new Deck(deck1);
	deck2->printDeck();



	return 0;
}