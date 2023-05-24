#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5 + 1;

//같은 정수를 K개 이하로 포함한 최장 연속 부분 수열의 길이 반환
int maxLength(int n, int k, vector<int>& a) {
	vector<int> cnt(INF); //cnt[i]: i의 개수
	cnt[a[0]] = 1;

	int left = 0, right = 0;
	int length = 1; //연속 부분 수열의 길이
	int max_length = 1; //최장 연속 부분 수열의 길이

	while (left <= right && right < n - 1) {
		int num = a[right + 1]; //수열에 추가될 숫자

		//같은 원소가 K개 이하로 존재하는 경우 다음 원소를 탐색하기 위해 right 증가
		if (cnt[num] + 1 <= k) {
			cnt[num]++;
			length++;
			max_length = max(max_length, length);
			right++;
		}
		//같은 원소가 K개 초과로 존재하는 경우 left 증가
		else {
			//같은 원소가 K개 이하가 될 때까지 반복
			while (cnt[num] + 1 > k) {
				cnt[a[left]]--;
				length--;
				left++;
			}

			//left가 right보다 작거나 같아야하므로 right 반복해서 증가
			while (left > right) {
				right++;
				length++;
			}
		}
	}
	return max_length;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//연산 & 출력
	cout << maxLength(n, k, a);

	return 0;
}