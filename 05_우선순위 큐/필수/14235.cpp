#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int givePresent( priority_queue<int> & bag) {
	int present;
	if (bag.empty()) {
		present = -1;
	}
	else {
		present = bag.top();
		bag.pop();
	}
	return present;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 선물 저장
	priority_queue<int> bag;
	// 입력
	int n, a;
	cin >> n;

	int p;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) { // 아이들을 만남
			cout << givePresent(bag) << endl;
		}
		else { // 선물 충전
			for (int j = 0; j < a; j++) {
				cin >> p;
				bag.push(p);
			}
		}
	}
	return 0;
}