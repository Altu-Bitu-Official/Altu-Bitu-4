#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 갖고 있는 카드인지 검사하는 함수
int binarySearch(int ch, int n, vector<int> &cards ) {
	int left = 0;
	int right = n - 1;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		if (ch < cards[mid]) {
			right = mid - 1;			
		}
		else if (ch > cards[mid]) {
			left = mid + 1;
		}

		else if (ch == cards[mid]) {
			return 1;
		}
	}

	return 0;
}

int main() {
	// 입력
	int n, m;
	cin >> n;

	vector<int> cards(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	cin >> m;

	vector<int> test_set(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> test_set[i];
	}

	// 연산 및 출력
	for (int i = 0; i < m; i++) {
		cout << binarySearch(test_set[i], n, cards) << " ";
	}

	return 0;
}