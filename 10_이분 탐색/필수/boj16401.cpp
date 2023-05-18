#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getNumber(int mid, vector<int>& length) { //mid값에 따른 과자 갯수
	int cnt = 0;
	for (int i = 0; i < length.size(); i++) {
		cnt += length[i] / mid;
	}
	return cnt;
}

int binarySearch(int left, int right, int target, vector<int>& length) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = getNumber(mid, length);
		if (num >= target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left - 1;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	int m, n;
	cin >> m >> n; //조카의 수, 과자의 수
	vector<int> length(n);
	for (int i = 0; i < n; i++) {
		cin >> length[i];
	}
	sort(length.begin(), length.end());
	cout << binarySearch(1, length[n - 1], m, length);
}