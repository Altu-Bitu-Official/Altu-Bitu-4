#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards; //cards 구조체, 자료구조 deque 사용
const int DO = 0, SU = 1;  //가독성을 위해 

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();
	if (do_deck > su_deck) {
		return "do";
	}
	else if (do_deck < su_deck) {
		return "su";
	}
	return "dosu";
}

//그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) { //그라운드가 empty가 아닌 경우 
		deck.push_back(ground.back()); //그라운드 -> 덱 
		ground.pop_back(); //덱에서 옮겼기 때문에 pop 
	}
}

//종을 쳤을 때
void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); //카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); //카드 가져가기 (본인 그라운드 -> 본인 덱)
}


//종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) { 
	    //도도의 그라운드가 empty가 아니면서, 가장 위의 숫자가 5인 경우 
	    //도도
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) { 
	    //수연의 그라운드가 empty가 아니면서, 가장 위의 숫자가 5인 경우
	    //도도
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { 
	    //두 그라운드 다 empty가 아니고, 두 그라운드에 있는 카드 합이 5인 경우우
	    //수연
		return SU;
	}
	return -1; // 종을 울릴 수 없음
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; //게임 번갈아서 진행됨: turn으로 표현
	                //도도 먼저
	while (m--)
	{
		ground[turn].push_front(deck[turn].front()); //자신의 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front(); //덱에는 카드가 없기 때문에 pop 
		if (deck[turn].empty()) {
			break; //승리 조건 1. 자신의 덱에 있는 카드 수가 0인 경우 
		}
		int bell = whoCanRingTheBell(deck, ground); //종을 울릴 수 있는 사람 판별 
		                                            //경우의 수: 도도, 수연, 아무도 울리지 못함 
		if (bell != -1) { //종을 울린 경우
			ringTheBell(bell, deck, ground); //그라운드에 있는 카드를 옮김 
		}
		turn = !turn; //차례 바꾸기
	}
	return judge(deck);
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
	cards deck(2), ground(2); //카드를 저장할 deck, 카드를 내려놓을 ground
	                          // 0: 도도, 1: 수연
	//입력
	cin >> n >> m;
	while (n--) { //n개의 줄에 입력받음 
		cin >> card1 >> card2;
		deck[DO].push_front(card1);
		deck[SU].push_front(card2);
	}
	//출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}
