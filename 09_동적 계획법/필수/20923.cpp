#include <iostream>
#include <deque>

using namespace std;

deque<int> do_card;
deque<int> su_card;

deque<int> do_ground;
deque<int> su_ground;

void game(int m) { // 도도 한 번 수연이 한 번

	int turn = 0;

	while (turn < m) {
		if (turn % 2 == 0) {// 도도
			do_ground.push_front(do_card.front());
			do_card.pop_front();
		}
		else {// 수연
			su_ground.push_front(su_card.front());
			su_card.pop_front();
		}

		if (do_card.empty() || su_card.empty()) {
			break;
		}

		// 질문이 있는 부분
		// 처음에는 while 문이 아니라 for 문을 이용하여
			//for (int i = 0; i < do_ground.size(); i++) {
			//	su_card.push_back(do_ground.back());
			//	do_ground.pop_back();
			//}
		// 이렇게 작성했는데 틀렸다.
		// while 문으로 바꿔주니 맞았는데 둘의 차이가 뭔지 모르겠다.

		if (!do_ground.empty() && !su_ground.empty() && (do_ground.front() + su_ground.front() == 5)) {
			while (!do_ground.empty()) {
				su_card.push_back(do_ground.back());
				do_ground.pop_back();
			}
			while (!su_ground.empty()) {
				su_card.push_back(su_ground.back());
				su_ground.pop_back();
			}
		}

		else if ((!do_ground.empty() && do_ground.front()==5) || (!su_ground.empty() && su_ground.front() == 5)) {

			while (!su_ground.empty()) {
				do_card.push_back(su_ground.back());
				su_ground.pop_back();
			}
			while (!do_ground.empty()) {
				do_card.push_back(do_ground.back());
				do_ground.pop_back();
			}
		}

		turn++;
	}

	// 출력
	if (do_card.size() > su_card.size()) {
		cout << "do";
	}
	else if (su_card.size() > do_card.size()) {
		cout << "su";
	}
	else {
		cout << "dosu";
	}
	return;
}

int main() {
	int n, m;
	int temp;
	cin >> n >> m;

	// 위에 있는 수가 front

	for (int i = 0; i < n; i++) {
		cin >> temp;
		do_card.push_front(temp);
		cin >> temp;
		su_card.push_front(temp);
	}

	game(m);

	return 0;
}