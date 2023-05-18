#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchNumbers(int n, vector<int>& numbers, int search) {
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (numbers[mid] == search) { // 찾음
			return true;
		}
		else if (numbers[mid] > search) { // 더 작은 값 탐색
			right = mid - 1;
		}
		else { // 더 큰 값 탐색
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int search;
	cin >> n;
	vector<int> numbers(n);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end()); // 정렬

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> search;

		cout << (searchNumbers(n, numbers, search) ? 1 : 0) << ' ';
	}

	return 0;
}