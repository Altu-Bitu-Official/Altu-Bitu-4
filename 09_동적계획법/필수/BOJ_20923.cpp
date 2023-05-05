#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;   // 카드 정보 저장할 구조체 변수
const int DO = 0, SU = 1;   // 도도와 수연이의 순서를 가리킬 변수

// 승리 판단하기
string judge(cards& deck)   // 덱 정보 전달받아서 이긴 사람을 리턴하는 함수
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();   // 도도와 수연이의 덱에 남아있는 카드의 개수를 변수에 각각 저장
	if (do_deck > su_deck) {    // 도도의 덱에 남아있는 카드 개수가 수연이보다 많다면
		return "do";    // 도도 승리
	}
	else if (do_deck < su_deck) {   // 수연이의 덱에 남아있는 카드 개수가 도도보다 많다면
		return "su";    // 수연 승리
	}
	return "dosu";  // 덱에 남아있는 카드 개수가 같다면 무승부
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {   // 플레이어의 덱과 상대방의 그라운드 정보를 전달받아 그라운드에서 덱으로 카드 옮기는 함수
	while (!ground.empty()) {   // 상대방 그라운드가 빌 때까지
		deck.push_back(ground.back());  // 상대방 그라운드의 카드를 플레이어의 덱으로 옮기기
		ground.pop_back();  // 상대방 그라운드의 카드 지우기
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {  // 종을 친 사람과 덱, 그라운드 정보를 전달받고 카드 옮기는 함수를 호출
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) { // 덱과 그라운드의 정보를 전달받아서 누가 종을 울리는지 판단하는 함수
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도의 그라운드가 비어있지 않고 도도의 그라운드의 가장 위에 위치한 카드가 5이면
		return DO;  // 도도가 종을 울림
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 수연이의 그라운드가 비어있지 않고 수연이의 그라운드의 가장 위에 위치한 카드가 5이면
		return DO;  // 도도가 종을 울림
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 도도와 수연이의 그라운드가 모두 비어있지 않고, 각각의 카드 더미의 가장 위에 위치한 카드의 숫자 합이 5이면
		return SU;  // 수연이가 종을 울림
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {    // 진행 횟수, 덱, 그라운드 정보 전달받아서 게임 진행하는 함수
	bool turn = DO; // 도도 먼저
	while (m--) // 정해진 진행 횟수만큼 반복
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드) : 도도의 덱의 가장 위에 위치한 카드를 도도의 그라운드에 내려놓기
		deck[turn].pop_front(); // 내려놓은 카드 덱에서 지우기
		if (deck[turn].empty()) {   // 만약 덱이 비게 되면
			break;  // 게임 종료
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람을 판단해서 bell에 저장
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);    // 종을 울린 사람과 덱, 그라운드 정보를 ringTheBell 함수에 전달
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); // 덱 정보를 judge 함수에 전달해서 이긴 사람 리턴
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
	int n, m, card1, card2; // 카드 개수, 게임 진행 횟수, 덱 저장할 변수 선언
	cards deck(2), ground(2); // 0: 도도, 1: 수연, 덱과 그라운드 초기화
	// 입력
	cin >> n >> m;  // 카드 개수와 게임 진행 횟수 입력받기
	while (n--) {
		cin >> card1 >> card2;  // 도도와 수연이의 덱 정보 입력받기
		deck[DO].push_front(card1); // 도도의 덱에 카드 정보 저장
		deck[SU].push_front(card2); // 수연이의 덱에 카드 정보 저장
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';  // 게임 진행 횟수, 덱, 그라운드 정보를 game 함수에 전달 후 결과 출력
	return 0;
}