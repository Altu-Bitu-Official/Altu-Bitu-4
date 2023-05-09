#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int m, int mid, vector<int> &snack) {
	int count = 0;
	for (int i = 0; i < snack.size(); i++) {
		count += snack[i] / mid;
	}
	return count >= m;
}

int solution(int m, int n, vector<int> snack) {
	int left = 1;
	int right = snack[n - 1];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(m, mid, snack)) {
			ans = mid;
			left = mid + 1; // 큰 쪽도 확인
		}
		else {
			right = mid - 1; // 불가능하면 작은 쪽 확인
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	vector<int> snack(n);
	for (int i = 0; i < n; i++) {
		cin >> snack[i];
	}

	sort(snack.begin(), snack.end()); // 정렬

	cout << solution(m, n, snack);
	return 0;
}