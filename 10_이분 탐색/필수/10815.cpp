#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
* 카드의 존재 여부만 판단하면 되므로, 이분 탐색을 이용해 해당 카드의 인덱스를 찾습니다.
*/

int binarySearch(int num, vector<int>& card, int n) {
	//카드 인덱스의 최소값: 0, 최대값: n
	int left = 0; int right = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num == card[mid]) {
			return 1;
		}
		if (num > card[mid]) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// 입력
	int n, m, num;
	cin >> n;
	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end()); // 이분 탐색을 위해 정렬

	cin >> m;
	while (m--) {
		cin >> num;
		// 연산 & 출력
		cout << binarySearch(num, card, n) << ' ';
	}
}