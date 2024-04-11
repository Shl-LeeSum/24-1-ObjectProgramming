#include <iostream>
#include <string>
#include <cstdlib> // 랜덤 숫자 생성을 위해 추가
#include <ctime>   // 시간 기반 시드 값 설정을 위해 추가

using namespace std;

// Card 클래스: 카드 한 장을 나타냄
class Card
{
private:
	int number; // 카드의 숫자 (1~13, Ace, Jack, Queen, King을 포함)
	int suit;	// 카드의 모양 (0: CLUB, 1: DIAMOND, 2: HEART, 3: SPADE)
public:
	Card();				// 랜덤 카드생성자
	Card(int n, int s); // 카드 정보 지정 생성자
	~Card();			// 소멸자

	void printCard(); // 카드정보 출력
};
// 기본 생성자: 랜덤한 숫자와 모양으로 카드 초기화
Card::Card()
{
	number = rand() % 13 + 1;
	suit = rand() % 4;
}
// 매개변수가 있는 생성자: 지정된 숫자와 모양으로 카드 초기화
Card::Card(int n, int s)
{
	number = n;
	suit = s;
}
// 소멸자
Card::~Card() {}

// 카드 정보 출력
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

// Player 클래스: 플레이어를 나타냄
class Player
{
private:
	string name;
	Card *deck; // 플레이어가 뽑은 카드
public:
	Player();
	~Player(); // 소멸자

	string getPlayerName();
	void printPlayerDeck();
	bool getDrawCheck();
	bool drawCard(Card *card);
	// Card* discardCard();
};

// Player 생성자: 초기화
Player::Player()
{
	name = "A";
	deck = NULL;
}
// Player 소멸자: 동적 할당된 메모리 정리
Player::~Player()
{
	if (getDrawCheck())
		delete deck;
}
Card* discardCard() {
	/*
	*
	* 
	* 작성 필요
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
		cout << this->getPlayerName() + "은 다음 카드를 가지고 있습니다.";
		this->deck->printCard();
	}
}

// 카드 뽑기: 랜덤 카드 생성 및 정보 업데이트
bool Player::drawCard(Card *card)
{
	if (getDrawCheck()) {
		cout << this->getPlayerName() + "은 이미 카드를 뽑았습니다.";
		return false;
	}

	cout << this->getPlayerName() + "은 다음 카드를 뽑았습니다.";
	card->printCard();

	deck = card; // 새 카드 생성
	return true;
}

int main()
{
	// 랜덤 시드 초기화
	srand(time(NULL));

	// 랜덤카드 생성 및 출력
	Card *randomCard = nullptr;

	// 임의 카드 설정 생성 및 출력
	int suit;
	int number;

	cout << "카드 모양을 입력하시오(CLUB:0, DIAMOND:1, HEART:2, SPADE:3 ): ";
	cin >> suit;

	cout << "카드 번호를 입력하시오(1~13): ";
	cin >> number;
	if (number < 1 || number > 13 || suit < 0 || suit > 3)
	{
		cout << "잘못 입력하셨습니다." << endl;
	}
	else
	{
		randomCard = new Card(number, suit);
	}
	randomCard->printCard();

	// Player 생성
	Player A;

	// Player A 생성후 instance 내용 확인
	cout << "Player name		: " << A.getPlayerName() << endl;
	cout << "Player drawCheck	: " << A.getDrawCheck() << endl;

	// Player A 카드 뽑기
	cout << "=====================" << endl;

	if (!A.drawCard(randomCard))
	{
		cout << "Player " + A.getPlayerName() + "는 이미 카드를 뽑았습니다." << endl;
	}
	else
	{
		randomCard = nullptr;
	}
	cout << "A drawn Card. " << endl;
	cout << "=====================" << endl;

	// Player A 카드 뽑은 후 내용 확인
	cout << "Player name		: " << A.getPlayerName() << endl;
	cout << "Player drawCheck	: " << A.getDrawCheck() << endl;

	A.printPlayerDeck();

	cout << "Player drawn Card	: ";

	//randomCard = A.discardCard();

	return 0;
}