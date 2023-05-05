#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;   //카드 덱을 저장하는 벡터
const int DO = 0, SU = 1;   //도도에게는 0, 수연에게는 1이라는 상수를 부여.

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();   //도도와 수연이의 덱 크기
	if (do_deck > su_deck) {    //도도의 덱이 수연이의 덱보다 카드가 많을 때
		return "do";    //도도 승리
	}   
	else if (do_deck < su_deck) {   //수연이의 카드 수가 더 많을 때
		return "su";    //수연 승리
	}
	return "dosu";  //둘 다 아니면 무승부
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {   //그라운드가 빌 때 까지
		deck.push_back(ground.back());  //카드를 뒤집으므로 그라운드의 맨 아래 카드를 덱에 푸쉬.
		ground.pop_back();  //맨 아래에 있는 카드 빼기
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도 : 비어있지 않고, (코드 죽음 방지용) 그라운드 맨 위의 카드가 5.
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도 : 비어있지 않고, (코드 죽음 방지용) 그라운드 맨 위의 카드가 5.
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연 : 어느 그라운드도 비어있지 않고, 그라운드 맨 위 카드의 합이 5.
		return SU;
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--)    //m번 진행
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //덱에서 맨 앞 카드 제거
		if (deck[turn].empty()) {   //덱이 비었을 시
			break;  //게임 종료
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);    //카드 가져가기
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck);     //판정 결과를 리턴.
}

/*
* 도도, 수연이 각각 덱과 그라운드를 가짐
* 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
* 1. 카드를 덱에서 한 장 내려놓음
* 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
* 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
* 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
*/

int main()
{
	int n, m, card1, card2;     //카드 개수 n, 게임 횟수 m, 카드 숫자 수 입력용 변수 card1, 2
	cards deck(2), ground(2); // 0: 도도, 1: 수연
	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;  //카드 숫자 입력
		deck[DO].push_front(card1);     //도도의 덱에 푸쉬
		deck[SU].push_front(card2);     //수연의 덱에 푸쉬
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}