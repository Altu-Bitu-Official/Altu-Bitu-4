#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터를 사용하기 위한 라이브러리
#include <deque> // 덱을 사용하기 위한 라이브러리

using namespace std;

typedef vector<deque<int>> cards; // int형 데이터를 저장한 덱 자료구조의 벡터를 구조체로 선언
const int DO = 0, SU = 1; // 도도와 수연의 벡터의 가독성을 위한 상수 선언

// 승리 판단하기
string judge(cards& deck) 
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();
	// 도도가 가진 카드의 수, 수연이 가진 카드의 수 -> 벡터 사이즈를 활용하여
	if (do_deck > su_deck) { // 도도의 카드 수가 더 많다면 
		return "do"; // 도도가 승리 
	}
	else if (do_deck < su_deck) { // 수연의 카드 수가 더 많다면 
		return "su"; // 수연이 승리
	}
	return "dosu"; // 둘의 카드 수가 같다면 비김 
}
// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {// 그라운드에 있는 모든 카드 덱으로 옮김
	while (!ground.empty()) { // 그라운드에 카드가 빌 때까지
		deck.push_back(ground.back()); // 그라운드에서 덱으로 카드 옮기고
		ground.pop_back(); // 그라운드에서 카드 삭제
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) { // 카드 옮기는 함수 
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도가 울리는 경우 1
		// 자신의 숫자가 5인 경우
		return DO; // 도도가 종 칠 수 있음 
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도가 울리는 경우 2
		// 수연의 숫자가 5인 경우
		return DO; // 도도가 종 칠 수 있음 
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { 
		// 수연이가 울리는 경우
		// 도도의 숫자와 수연의 숫자의 합이 5가 되는 경우
		return SU; // 수연이 종 칠 수 있음
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {// 게임 진행 횟수, 덱과 그라운드 인자 입력받음
	bool turn = DO; // 도도 먼저
	while (m--){ // 게임을 m번 동안 진행하면서 

		// 카드 내려놓기
		ground[turn].push_front(deck[turn].front()); // (덱 -> 그라운드)
		deck[turn].pop_front(); // 자신의 덱의 가장 윗부분 삭제

		if (deck[turn].empty()) { // 자신이 가진 카드가 없다면 
			break; // 게임 종료 -> 상대방이 이김
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground); // 그라운드에 있는 카드를 덱으로 옮김
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); // 덱으로 승리자 판별 후 반환
}

/*
* 도도, 수연이 각각 덱과 그라운드를 가짐
* 도도->수연->도도->수연... 순으로 차례를 바꿔가며 게임 진행 (game 함수)
* 1. 카드를 덱에서 한 장 내려놓음
* 2. 어떤 플레이어가 종을 칠 수 있는지 판단 (whoCanRingTheBell 함수)
* 3. 종을 친 경우 그라운드의 카드를 덱으로 이동(ringTheBell, groundToDeck 함수)
* 종료 조건 만족 시 승리한 사람 리턴(judge 함수)
*/

int main() { // 가장 먼저 실행되는 main 함수
	int n, m, card1, card2; // 카드 개수, 게임 진행 횟수, 도도 카드에 적힌 수, 수연 카드에 적힌 수
	cards deck(2), ground(2); // 0: 도도, 1: 수연
	// 입력
	cin >> n >> m;
	while (n--) { // n번 동안 
		cin >> card1 >> card2; // 도도와 수연의 카드에 적힌 수 입력 받음
		deck[DO].push_front(card1); // 해당 수를 도도의 벡터에 저장
		deck[SU].push_front(card2); // 해당 수를 수연의 벡터에 저장
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0; // 메인 함수 종료 
}