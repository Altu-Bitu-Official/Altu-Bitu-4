#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci; // pair<int, int> 를 ci라는 이름으로 정의

int maxEmploy(vector<ci> candidates) {
	// 서류 심사 1등(0번 인덱스)은 무조건 합격
	int cnt = 1, highest_rank = candidates[0].second;
	// i번째 사람은 0 ~ i-1번째 사람보다 서류 심사 순위가 높음
	// 0 ~ i-1번째 사람들 중 면접 순위가 가장 높은 사람보다 면접 순위가 높아야 합격
	for (int i = 1; i < candidates.size(); i++) {
		if (highest_rank > candidates[i].second) { // 이전 사람들보다 면접 순위가 높은 경우
			highest_rank = candidates[i].second; // 가장 높은 면접 순위 갱신
			cnt++; // 합격자 추가
		}
	}
	return cnt;
}

/*
* 서류, 면접 순위 중 하나를 기준(고정)으로 정렬 후 다른 하나의 순위를 비교
* 오름차순으로 정렬 후 위에서부터 순차적으로 비교
*/

int main()
{
	int t, n, cnt;
	// 입력
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ci> candidates(n, ci(0, 0));
		for (int i = 0; i < n; i++) {
			cin >> candidates[i].first >> candidates[i].second; // first: 서류 심사 순위, second: 면접 심사 순위
		}
		// 연산
		sort(candidates.begin(), candidates.end()); // 서류 심사 순위(first) 순서대로 정렬
		cnt = maxEmploy(candidates);
		// 출력
		cout << cnt << '\n';
	}
	return 0;
}