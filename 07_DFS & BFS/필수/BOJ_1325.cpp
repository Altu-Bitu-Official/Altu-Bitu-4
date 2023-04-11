#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// N개의 컴퓨터, a가 b를 신뢰 -> b 해킹 시 a도 해킹 가능
// 한번에 가장 많은 컴퓨터 해킹할 수 있는 컴퓨터의 번호 출력
// 인접 행렬로 풀면 메모리 초과 발생 -> 인접 리스트로 해결

// n: 노드 개수, v: 시작 노드 번호
int bfs(int n,int v, vector<vector<int>>& graph) {
	int cnt=0;
	vector<bool> visited(n + 1, false);
	queue<int> q;

	q.push(v);
	visited[v] = true; 

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];
			if (!visited[next_node]) {
				q.push(next_node);
				visited[next_node] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m;
	int a, b; // a가 b를 신뢰한다
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector <int> v(n+1);

	while (m--) {
		cin >> a >> b; // a가 b를 신뢰할 경우
		graph[b].push_back(a); // b를 통해 a 해킹 가능
	}
	// v에 노드마다 해킹 가능한 컴퓨터 수 넣음
	v[0] = 0; 
	for (int i = 1; i <= n; i++) {
		v[i]=(bfs(n, i, graph));
	}
	// 최댓값을 가지는 인덱스 오름차순으로 출력
	int max = *max_element(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		if (max == v[i]) cout << i << " ";
	}
	return 0;
}