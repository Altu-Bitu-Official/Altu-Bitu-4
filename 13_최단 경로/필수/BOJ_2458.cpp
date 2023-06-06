#include <iostream>
#include <vector>

using namespace std;

void floyWarshall(int n, vector<vector<int>>& graph) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//i < k < j인 경우 i < j
				if (graph[i][k] == 1 && graph[k][j] == 1) {
					graph[i][j] = 1;
				}

				//i > k > j인 경우 i > j
				if (graph[i][k] == 2 && graph[k][j] == 2) {
					graph[i][j] = 2;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, a, b;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1)); //graph[i][j] = 1: i가 j보다 작음, 2: i가 j보다 큼

	//자기 자신과는 비교 못하므로 0으로 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 2;
	}

	//연산
	floyWarshall(n, graph);
	
	vector<int> cnt(n + 1, 0); //cnt[i]: i번째 학생과 비교할 수 없는 학생의 수
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == -1) {
				cnt[i]++;
			}
		}
	}

	int result = 0; //자신의 키가 몇 번째인지 알 수 있는 학생의 수
	for (int i = 1; i <= n; i++) {
		//비교할 수 없는 학생의 수가 없는 경우에만 자신의 키 순위를 정확하게 알 수 있음
		if (cnt[i] == 0) {
			result++;
		}
	}

	//출력
	cout << result;

	return 0;
}