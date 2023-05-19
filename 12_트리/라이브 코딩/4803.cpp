#include<iostream>
#include<vector>

using namespace std;

// 결과 출력 함수
void printResult(int tc, int cnt) {
	cout << "Case " << tc << ": ";

	switch (cnt) {
	case 0:
		cout << "No trees.\n";
		break;
	case 1:
		cout << "There is one tree.\n";
		break;
	default:
		cout << "A forest of " << cnt << " trees.\n";
	}
	return;
}

void dfs(bool& flag, int cur, int prev, vector<vector<int>>& graph, vector<bool>& visited) {

	if (visited[cur]) { // 방문했던 곳을 또 방문했다면 트리가 아니다
		flag = false;
		return;
	}

	visited[cur] = true; // 방문 체크

	for (int next : graph[cur]) {
		if (next == prev) {
			continue;
		}
		dfs(flag, next, cur, graph, visited);
	}
	return ;
}

/*
* 각 그래프가 트리인지 아닌지 판단
* 사이클이 생기면 트리 아님
* 사이클이 생긴다 -> DFS로 자기 자신으로 돌아올 수 있다.
*/

int main() {
	int n, m, t, v1, v2;

	for (t = 1;;t++) { // 테스트 케이스 번호

		// 입력
		cin >> n >> m;

		if (!n && !m) { // 종료 조건
			break;
		}

		// 그래프 입력
		vector<vector<int>> graph(n+1, vector<int>(0)); 
		for (int i = 0; i < m; i++) {
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}

		int cnt = 0; // 트리 수 카운트
		vector<bool> visited(n + 1, false); // 방문 표시
		
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				continue;
			}

			bool flag = true; // 트리인지 여부 저장하는 변수
			dfs(flag, i, 0, graph, visited);
			if (flag) {
				cnt++;
			}
			
		}

		// 출력
		printResult(t, cnt);
	}
    return 0;
}
