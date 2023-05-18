#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//조카 1명에게 줄 수 있는 막대 과자의 최대 길이 반환
int maxLength(int m, int n, vector<int>& length) {
	int result = 0;

	int left = 1; //최소 과자 길이
	int right = length[0]; //최대 과자 길이
	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0; //과자의 길이가 mid일 때 만들어지는 과자의 개수
		for (int i = 0; i < n; i++) {
			cnt += length[i] / mid;
		}

		//과자의 총 개수가 조카 수보다 크거나 같으면 나눠줄 수 있는 상황
		if (cnt >= m) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int m, n;
	cin >> m >> n;

	vector<int> length(n);
	for (int i = 0; i < n; i++) {
		cin >> length[i];
	}

	//length 배열 내림차순 정렬
	sort(length.rbegin(), length.rend());

	//연산 & 출력
	cout << maxLength(m, n, length);

	return 0;
}