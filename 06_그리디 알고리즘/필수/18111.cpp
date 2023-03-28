#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INT_MAX 2147483647
using namespace std;

void minecraft(int b, vector<vector<int>>& land) {
	int time = INT_MAX; // 시간
	int height = 0; // 땅의 높이

	//입력 받은 땅의 높이에서 최대, 최소 알아내기
	int min = 256;
	int max = 0;
	for (int n = 0; n < land.size(); n++) {
		int tmp = *min_element(land[n].begin(), land[n].end());
		if (tmp <= min) {
			min = tmp;
		}
	}
	for (int n = 0; n < land.size(); n++) {
		int tmp = *max_element(land[n].begin(), land[n].end());
		if (tmp >= max) {
			max = tmp;
		}
	}

	// min 부터 max 까지의 높이에 맞춰보며 최단시간 구하기
	for (int i = min; i <= max; i++) {
		int build = 0, remove = 0;
		// 기준이 되는 높이 i
		// i 보다 크면 빼고 작으면 더한다
		for (int j = 0; j < land.size(); j++) {
			for (int k = 0; k < land[j].size(); k++) {
				int diff = land[j][k] - i;
				if (diff < 0) {
					build += (-diff); // 쌓기
				}
				else {
					remove += diff; // 제거하기
				}
			}
		}

		if (build <= remove + b) {
			int tmp_time = build + remove * 2;
			if (tmp_time <= time) {
				time = tmp_time;
				height = i;
			}
		}
	}
	cout << time << " " << height;
}

int main() {
	int n, m, b;
	// 입력
	cin >> n >> m >> b;
	vector<vector<int>> land(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i][j];
		}
	}
	minecraft(b, land);

	return 0;
}