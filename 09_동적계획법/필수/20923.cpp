#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;   //덱 저장할 setting
const int DO = 0, SU = 1;   //벡터 내 순서

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();   //각자의 덱 사이즈
	if (do_deck > su_deck) {    //도도 덱에 남은 카드가 더 많으면
		return "do";    //승리자 : 도도
	}
	else if (do_deck < su_deck) {   //수연이 덱에 남은 카드가 더 많으면
		return "su";    //수연이 승리
	}
	return "dosu";  //덱 카드 개수 똑같으면 비김
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {   //그라운드가 빌 때까지 반복
		deck.push_back(ground.back());     //덱에 그라운드 카드 추가
		ground.pop_back();  //그라운드 카드 제거
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도
		return DO;  //도도 반환
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도
		return DO;  //도도 반환
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연
		return SU;  //수연이 반환
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--) //문제에서 주어진 게임 진행 횟수만큼 반복
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //덱에서 맨 앞 카드 제거
		if (deck[turn].empty()) {   //덱이 비었을 경우
			break;  //게임 stop
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);    //종 쳤을 경우 함수 호출
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); //승리 판단
}

int main()
{
	int n, m, card1, card2; //n : 카드 개수 m: 게임 진행 횟수 card1:도도 꺼 card2:수연이 꺼
	cards deck(2), ground(2); // 0: 도도, 1: 수연
	// 입력
	cin >> n >> m;
	while (n--) {   //카드 수만큼 반복
		cin >> card1 >> card2;  //도도와 수연이 카드 입력
		deck[DO].push_front(card1); //도도 카드 덱에 추가
		deck[SU].push_front(card2); //수연이 카드 덱에 추가
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}