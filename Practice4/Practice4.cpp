#include <iostream>
#include <string>
#include <cstdlib> // ���� ���� ������ ���� �߰�
#include <ctime>   // �ð� ��� �õ� �� ������ ���� �߰�

using namespace std;

// Card Ŭ����: ī�� �� ���� ��Ÿ��
class Card
{
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
Card::Card()
{
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
// �Ű������� �ִ� ������: ������ ���ڿ� ������� ī�� �ʱ�ȭ
Card::Card(int n, int s)
{
	number = n;
	suit = s;
}
// �Ҹ���
Card::~Card() {}

// ī�� ���� ���
void Card::printCard()
{
	string suitSymbols[] = {"CLUB", "DIAMOND", "HEART", "SPADE"};
	string suitSymbol = suitSymbols[suit];

	string numberName;
	bool isFaceOrAce = false;
	if (number == 1)
	{
		numberName = "Ace";
		isFaceOrAce = true;
	}
	else if (number == 11)
	{
		numberName = "Jack";
		isFaceOrAce = true;
	}
	else if (number == 12)
	{
		numberName = "Queen";
		isFaceOrAce = true;
	}
	else if (number == 13)
	{
		numberName = "King";
		isFaceOrAce = true;
	}

	if (isFaceOrAce)
	{
		cout << "Card: " << suitSymbol << " " << numberName << endl;
	}
	else
	{
		cout << "Card: " << suitSymbol << " " << number << endl;
	}
}

// Player Ŭ����: �÷��̾ ��Ÿ��
class Player
{
private:
	string name;
	Card *deck; // �÷��̾ ���� ī��
public:
	Player();
	~Player(); // �Ҹ���

	string getPlayerName();
	void printPlayerDeck();
	bool getDrawCheck();
	bool drawCard(Card *card);
	// Card* discardCard();
};

// Player ������: �ʱ�ȭ
Player::Player()
{
	name = "A";
	deck = NULL;
}
// Player �Ҹ���: ���� �Ҵ�� �޸� ����
Player::~Player()
{
	if (getDrawCheck())
		delete deck;
}
Card* discardCard() {
	/*
	*
	* 
	* �ۼ� �ʿ�
	* 
	* 
	*/	
};

string Player::getPlayerName() { return name; }

bool Player::getDrawCheck() { return deck != nullptr; }
void Player::printPlayerDeck()
{
	if (getDrawCheck())
	{
		cout << this->getPlayerName() + "�� ���� ī�带 ������ �ֽ��ϴ�.";
		this->deck->printCard();
	}
}

// ī�� �̱�: ���� ī�� ���� �� ���� ������Ʈ
bool Player::drawCard(Card *card)
{
	if (getDrawCheck()) {
		cout << this->getPlayerName() + "�� �̹� ī�带 �̾ҽ��ϴ�.";
		return false;
	}

	cout << this->getPlayerName() + "�� ���� ī�带 �̾ҽ��ϴ�.";
	card->printCard();

	deck = card; // �� ī�� ����
	return true;
}

int main()
{
	// ���� �õ� �ʱ�ȭ
	srand(time(NULL));

	// ����ī�� ���� �� ���
	Card *randomCard = nullptr;

	// ���� ī�� ���� ���� �� ���
	int suit;
	int number;

	cout << "ī�� ����� �Է��Ͻÿ�(CLUB:0, DIAMOND:1, HEART:2, SPADE:3 ): ";
	cin >> suit;

	cout << "ī�� ��ȣ�� �Է��Ͻÿ�(1~13): ";
	cin >> number;
	if (number < 1 || number > 13 || suit < 0 || suit > 3)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	else
	{
		randomCard = new Card(number, suit);
	}
	randomCard->printCard();

	// Player ����
	Player A;

	// Player A ������ instance ���� Ȯ��
	cout << "Player name		: " << A.getPlayerName() << endl;
	cout << "Player drawCheck	: " << A.getDrawCheck() << endl;

	// Player A ī�� �̱�
	cout << "=====================" << endl;

	if (!A.drawCard(randomCard))
	{
		cout << "Player " + A.getPlayerName() + "�� �̹� ī�带 �̾ҽ��ϴ�." << endl;
	}
	else
	{
		randomCard = nullptr;
	}
	cout << "A drawn Card. " << endl;
	cout << "=====================" << endl;

	// Player A ī�� ���� �� ���� Ȯ��
	cout << "Player name		: " << A.getPlayerName() << endl;
	cout << "Player drawCheck	: " << A.getDrawCheck() << endl;

	A.printPlayerDeck();

	cout << "Player drawn Card	: ";

	//randomCard = A.discardCard();

	return 0;
}