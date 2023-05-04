#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1;

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size(); //각자 가지고 있는 카드의 수
	if (do_deck > su_deck) {
		return "do";
	}
	else if (do_deck < su_deck) {
		return "su";
	}
	return "dosu";
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) { //모든 카드를 다 옮겨줘야 함
		deck.push_back(ground.back()); //덱에다가 한번 뒤집어서 카드를 넣어줌
		ground.pop_back();
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}

// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도가 벨을 울릴 수 있는 경우(1)
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도가 벨을 울릴 수 있는 경우(2)
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연이가 종을 치는 경우
    	return SU;
	}
	return -1; // 종을 칠 수 없는 경우
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--) //m번 게임을 진행
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드) (자신의 카드)
		deck[turn].pop_front(); //덱에는 카드가 더 이상 없기 때문에
        if (deck[turn].empty()) { //자기가 가지고 있는 카드가 0일 경우. 카드를 내려놨으면 바로 체크해 주어야 한다.
			break;
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground); //카드 옮기기
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); //승자 판별하기
}

int main()
{
	int n, m, card1, card2;
	cards deck(2), ground(2); // 0: 도도, 1: 수연, 카드 저장 -> deck, 카드를 내려놓을 -> ground
	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;
		deck[DO].push_front(card1);
		deck[SU].push_front(card2);
	}

	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}