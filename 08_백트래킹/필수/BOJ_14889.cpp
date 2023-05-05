#include <iostream>
#include <vector>

using namespace std;

int n;
int min_diff = 10000000;
vector<vector<int>> stats;
vector<bool> is_start;

//스타트팀과 링크팀의 능력치 차이 계산
int getDiff() {
	int start_sum = 0;
	int link_sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			//스타트팀 능력치
			if (is_start[i] && is_start[j]) {
				start_sum += stats[i][j] + stats[j][i];
			}
			//링크팀 능력치
			else if (!is_start[i] && !is_start[j]) {
				link_sum += stats[i][j] + stats[j][i];
			}
		}
	}
	return abs(start_sum - link_sum);
}

//cnt: 스타트팀의 인원 수, idx: 다음 탐색 인덱스
void backtracking(int cnt, int idx) {
	//종료 조건1: 차이가 0이라면 바로 종료
	if (min_diff == 0) {
		return;
	}

	//종료 조건2: n/2의 인원이 모인 경우
	if (cnt == n / 2) {
		min_diff = min(min_diff, getDiff());
		return;
	}

	for (int i = idx; i <= n; i++) {
		//사용
		is_start[i] = true;

		//다음 사람 넣기
		backtracking(cnt + 1, i + 1);
		
		//반납
		is_start[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;
	stats.assign(n + 1, vector<int>(n + 1));
	is_start.assign(n + 1, false);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	//연산
	backtracking(0, 1);

	//출력
	cout << min_diff;

	return 0;
}