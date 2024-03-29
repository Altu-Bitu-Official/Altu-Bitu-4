#include<iostream>
#include <vector>
#include<queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5 + 1;

int prim(int v, int start, vector<vector<int>>& graph) {
	int sum = 0;
	vector<bool> visited(v, false); //방문 check
	vector<int> dist(v, INF); //cost
	priority_queue<ci, vector<ci>, greater<>> pq; // min heap

	//초기화
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		auto [curr_w, curr] = pq.top();
		pq.pop();

		if (visited[curr]) {
			continue;
		}
		visited[curr] = true;
		sum += curr_w;

		for (int i = 0; i < v; i++) {
			if (!visited[i] && graph[curr][i] < dist[i]) {
				dist[i] = graph[curr][i];
				pq.push({ graph[curr][i], i });
			}
		}
	}
	return sum;
}

/*
* 각 논들 사이의 간선도 고려하고, 우물을 파는 경우도 고려하는 것은 매우 복잡
* 논에 추가로 모든 우물과 연결되는 수원이 있다고 가정!
* -> 직접 논에 우물을 파는 경우는 수원과 각 논 사이의 간선 가중치라고 할 수 있음
*
* 0 2 2 2 5
* 2 0 3 3 4
* 2 3 0 4 4
* 2 3 4 0 3
* 5 4 4 3 0
*
* 인덱스 0 ~ n-1은 논, 인덱스 n은 수원
* 1개 이상의 논은 반드시 직접 우물을 파야 하므로 수원(n)에서 시작하는 프림 알고리즘
*/

int main() {
	int n, w;
	// 입력
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) { //수원으로부터 물을 끌어오는 비용
		cin >> w;
		graph[i][n] = graph[n][i] = w;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j]; //논들 사이에서 물을 끌어오는 비용
		}
	}
	//연산 & 출력
	cout << prim(n + 1, n, graph); //수원에서 시작하는 프림 알고리즘
	return 0;
}