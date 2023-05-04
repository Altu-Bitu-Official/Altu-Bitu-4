#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;//deque로 구성된 카드. 카드니까 deque
const int DO = 0, SU = 1;//도도 수연 상수로 표시

// 승리 판단하기
string judge(cards& deck)//갖고있는 카드로 판단한다.
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();//갯수를 알아야 누가 이겼나 보니까
	if (do_deck > su_deck) {//도도거가 많으면
		return "do";//도도이김
	}
	else if (do_deck < su_deck) {//수연이가 많으면
		return "su";//수연 이김
	}
	return "dosu";
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {//그라운드에있는거 덱으로 옮길거니까 2개인자
	while (!ground.empty()) {//그라운드 없을 때까지
		deck.push_back(ground.back());//계속 넣는다. 새로 얻는 카드는 뒤에 넣으니까 back
		ground.pop_back();//그라운드는 삭제함
	}
}

// 종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {//땅에있는거를 플레이어 덱으로 옮길거니까 3개 인자
	//그라운드에 있는 거 이긴 애가 싸그리 가져가니까 함수 2번 호출
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}


// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	//도도는 5짜리만 칠 수 있고 수진이는 합쳐서 5일 때만 칠 수 있다.
	if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도
		return DO;//수진이 안 냈고 자기가 냈는데 자기거가 5인 경우
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { // 도도
		return DO;//도도 안 넀고 수진이거가 5인 경우
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 수연
		return SU;//둘 다 냈고 둘이 합쳐 5인경우
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {//m번 하고, 덱을 알아야하고, 그라운드를 알아야 함
	bool turn = DO; // 도도 먼저
	while (m--)//게임횟수만큼 반복
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front();//내려놨으니까 카드 없앰
		if (deck[turn].empty()) {//덱이 비면은 끝나니까 break
			break;
		}
		int bell = whoCanRingTheBell(deck, ground); // 종을 울릴 수 있는 사람
		if (bell != -1) { // 종을 울린 경우
			ringTheBell(bell, deck, ground);//bell: 종 울린 사람 
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck);//차례 다 쓰면 누가 이겼나 판단
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
	int n, m, card1, card2;//n장 받음. 턴을 m번. 도도의 카드, 수연의 카드
	cards deck(2), ground(2); // 0: 도도, 1: 수연. 덱이 두 개다(카드더미 두 개.) 큐가 2개 있어서 [0][1]임. 각 인덱스는 큐 자체를 가리킴 
	// 입력
	cin >> n >> m;//입력
	while (n--) {//n만큼 반복
		cin >> card1 >> card2;//카드 입력받고
		deck[DO].push_front(card1);//덱 목록에 넣는다. 아래장부터 입력에 주어지므로 front에 넣는다.
		deck[SU].push_front(card2);//덱 목록에 넣는다. 아래장부터 입력에 주어지므로 front에 넣는다.
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';//연산, 출력
	return 0;
}