#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards; //카드 저장 장소
const int DO = 0, SU = 1;

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size(); //도도의 덱 크기와 수연의 덱 크기 구하기
	if (do_deck > su_deck) { //도도와 수연의 덱 크기 비교: 도도 덱이 수연 덱 보다 크면
		return "do"; // 도도 승리
	}
	else if (do_deck < su_deck) { //도도 덱이 수연 덱 보다 작으면
		return "su"; //수연 승리
	}
	return "dosu"; //둘 다 경우 아니면 (도도 덱 = 수연 덱) 
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) { 
	while (!ground.empty()) { //그라운드가 비어있지 않으면
		deck.push_back(ground.back()); //그라운드의 뒤 값 부터 덱의 맨 뒤에 추가 
		ground.pop_back(); //추가 된 그라운드의 값 삭제
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) { 
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도의 ground 덱이 비어있지 않고, 도도 앞에 그라운드 덱에 있는 값이 5일경우
		return DO; //도도 승리
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 수연의 ground 덱이 비어있지 않고, 수연 앞에 그라운드 덱에 있는 값이 5일경우
		return DO; //도도 승리
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { //도도&수연의 ground 덱이 비어있지 않고 도도와 수연의 ground에 있는 값의 합이 5일 경우
		return SU; //수연 승리
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--) //게임 횟수 만큼 반복
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //덱에서 내려놓은 카드 삭제
		if (deck[turn].empty()) { //덱이 비어있으면 게임에서 지는 거 -> 반복 break
			break;
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck); //judge 함수에서 return 한 값을 return함
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
	int n, m, card1, card2;
	cards deck(2), ground(2); // card형태의 자료 deck, ground각각 2개씩 생성 0: 도도, 1: 수연
	// 입력
	cin >> n >> m; //카드 개수, 게임 진행 횟수 입력
	while (n--) { //카드 갯수 만큼
		cin >> card1 >> card2; //도도, 수연 카드 값 입력받음
		deck[DO].push_front(card1); //도도 카드 값 덱의 맨 위에 저장
		deck[SU].push_front(card2); //수연 카드 값 덱의 맨 위에 저장
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}