#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, num;
	cin >> n;

	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//card 배열 정렬
	sort(card.begin(), card.end());

	cin >> m;
	while (m--) {
		cin >> num;

		//연산 & 출력
		cout << binary_search(card.begin(), card.end(), num) << " ";
	}

	return 0;
}