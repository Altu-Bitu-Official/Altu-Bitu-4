#include <iostream>
#include <deque>

using namespace std;

deque<int> do_card;
deque<int> su_card;

deque<int> do_ground;
deque<int> su_ground;

void game(int m) { // ���� �� �� ������ �� ��

	int turn = 0;

	while (turn < m) {
		if (turn % 2 == 0) {// ����
			do_ground.push_front(do_card.front());
			do_card.pop_front();
		}
		else {// ����
			su_ground.push_front(su_card.front());
			su_card.pop_front();
		}

		if (do_card.empty() || su_card.empty()) {
			break;
		}

		// ������ �ִ� �κ�
		// ó������ while ���� �ƴ϶� for ���� �̿��Ͽ�
			//for (int i = 0; i < do_ground.size(); i++) {
			//	su_card.push_back(do_ground.back());
			//	do_ground.pop_back();
			//}
		// �̷��� �ۼ��ߴµ� Ʋ�ȴ�.
		// while ������ �ٲ��ִ� �¾Ҵµ� ���� ���̰� ���� �𸣰ڴ�.

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

	// ���
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

	// ���� �ִ� ���� front

	for (int i = 0; i < n; i++) {
		cin >> temp;
		do_card.push_front(temp);
		cin >> temp;
		su_card.push_front(temp);
	}

	game(m);

	return 0;
}