#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int cnt[200001] = {};

int main() {
	ios::sync_with_stdio(false);

	//입력
	int n, k;
	cin >> n >> k;

	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0; int right = 0;
	int max_length = -1;

	for (int left = 0; left < n; left++) {
		while (right < n && cnt[arr[right]] < k) {
			cnt[arr[right]]++;//개수 카운트
			right++;
			
		}
		//right를 한칸이동하는 방식으로 수열이 더 길이질 수 없으므로 최대값을 저장
		//
		max_length = max(max_length, right - left);//right는 실제수열의 마지막 원소의 번호+1이므로 따로 right-left+1을 해주지 않아도 괜찮음
		if (right == n) {
			break;//더이상 추가할 원소가 없으므로 break
		}
		cnt[arr[left]]--;//중복 원소가 k이하가 되도록 left의 원소를 제외
	}
	//출력
	cout << max_length;

	return 0;
}