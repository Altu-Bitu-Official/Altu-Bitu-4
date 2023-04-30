#include <iostream>
#include <deque>

using namespace std;

//수연이와 도도가 종을 치는 조건이 되는지 확인
int check(deque<int>& dodo_ground, deque<int>& suyeon_ground) {
	//두 그라운드가 비어있지 않고 두 카드의 합이 5가 되는 경우 수연이가 종을 침
	if (!dodo_ground.empty() && !suyeon_ground.empty() && dodo_ground.front() + suyeon_ground.front() == 5) {
		return 1;
	}

	//가장 위의 카드 중 5가 있는 경우 도도가 종을 침
	if ((!dodo_ground.empty() && dodo_ground.front() == 5) || (!suyeon_ground.empty() && suyeon_ground.front() == 5)) {
		return 2;
	}

	return 0;
}

//그라운드에 있는 카드를 자신의 카드 더미로 옮기는 함수
void moveCard(deque<int>& card, deque<int>& ground1, deque<int>& ground2) {
	//카드 더미가 합쳐질 때 뒤집어서 가져오므로
	//그라운드에서 가장 아래에 있는 카드 먼저 추가해야 함

	//상대방 그라운드에 있는 카드 가져오기
	while (!ground1.empty()) {
		card.push_back(ground1.back());
		ground1.pop_back();
	}

	//자신의 그라운드에 있는 카드 가져오기
	while (!ground2.empty()) {
		card.push_back(ground2.back());
		ground2.pop_back();
	}
}

//종을 치는 조건을 확인하고 카드를 옮기는 함수
void checkAndMove(deque<int>& dodo_card, deque<int>& suyeon_card, deque<int>& dodo_ground, deque<int>& suyeon_ground) {
	int check_state = check(dodo_ground, suyeon_ground);

	//1) 수연이가 종을 치는 조건이 만족되는 경우
	if (check_state == 1) {
		moveCard(suyeon_card, dodo_ground, suyeon_ground);
	}
	//2) 도도가 종을 치는 조건이 만족되는 경우
	else if (check_state == 2) {
		moveCard(dodo_card, suyeon_ground, dodo_ground);
	}
}

string game(int m, deque<int>& dodo_card, deque<int>& suyeon_card) {
	//front(): 그라운드 중 가장 위, back(): 그라운드 중 가장 아래
	deque<int> dodo_ground;
	deque<int> suyeon_ground;

	//m번동안 반복
	for (int i = 0; i < m; i++) {
		//도도 차례
		if (i % 2 == 0) {
			//1) 그라운드에 가장 위에 있는 카드 내려놓기
			dodo_ground.push_front(dodo_card.front());
			dodo_card.pop_front();

			//2) 카드가 0개가 되었는지 검사하고 맞다면 바로 종료
			if (dodo_card.empty()) {
				return "su";
			}
		}

		//수연이 차례
		else {
			//1) 그라운드에 가장 위에 있는 카드 내려놓기
			suyeon_ground.push_front(suyeon_card.front());
			suyeon_card.pop_front();

			//2) 카드가 0개가 되었는지 검사하고 맞다면 바로 종료
			if (suyeon_card.empty()) {
				return "do";
			}
		}

		//3) 종치는 조건 검사하고 카드 이동
		checkAndMove(dodo_card, suyeon_card, dodo_ground, suyeon_ground);
	}

	//더 많은 카드를 가진 사람이 이김
	if (dodo_card.size() > suyeon_card.size()) {
		return "do";
	}
	else if (dodo_card.size() < suyeon_card.size()) {
		return "su";
	}
	else {
		return "dosu";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, c1, c2;
	cin >> n >> m;

	//front(): 카드 더미 중 가장 위, back(): 카드 더미 중 가장 아래
	deque<int> dodo_card;
	deque<int> suyeon_card;

	while (n--) {
		cin >> c1 >> c2; //도도, 수연의 카드
		dodo_card.push_front(c1);
		suyeon_card.push_front(c2);
	}

	//연산 & 출력
	cout << game(m, dodo_card, suyeon_card);

	return 0;
}