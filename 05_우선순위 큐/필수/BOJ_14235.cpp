#include <iostream>
#include <queue>

using namespace std;

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, g;
	priority_queue<int> gift;

	// 입력
	cin >> n;

	// 연산 및 출력
	while (n--) {
		cin >> a;
		if (a == 0) {
			if (gift.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << gift.top() << '\n';
				gift.pop();
			}
		}

		else {
			while (a--) {				
				cin >> g;
				gift.push(g);
			}
		}
	}

	return 0;
}
