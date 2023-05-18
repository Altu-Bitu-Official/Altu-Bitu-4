#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 길이 length로 배분할 수 있는 최대 인원수 구하는 함수
int countPeople(int length, vector<int>& cookies) {
	int res = 0;
	for (int i = 0; i < cookies.size(); i++) {
		res += cookies[i] / length;	// 갖고 있는 과자 각각을 길이 length로 쪼갤 수 있는 개수를 모두 합산하기
	}

	return res;
}

// 나눠줄 수 있는 과자의 최대 길이 구하는 함수
int binarySearch(int left, int right, int num, vector<int>& cookies) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int max_num = countPeople(mid, cookies);	// 과자 길이 mid일 때 나눠줄 수 있는 최대 인원수

		if (max_num >= num) {	// 과자 길이 mid일 때 나눠줄 수 있는 최대 인원수가 실제 인원보다 많으면 과자 길이 늘리기
			left = mid + 1;
		}
		else {	// 나눠줄 수 있는 최대 인원수가 실제 인원보다 적으면 과자 길이 줄이기
			right = mid - 1;
		}
	}

	return left - 1;	// 나눠줄 수 있는 최대 인원수가 실제 인원보다 크거나 같으면서, 길이 최대일 때 리턴
}


int main() {
	int m, n;

	// 입력
	cin >> m >> n;
	vector<int> cookie(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> cookie[i];
	}

	// 연산 및 출력
	sort(cookie.begin(), cookie.end());

	cout<< binarySearch(1, cookie.back(), m, cookie);

	return 0;
}