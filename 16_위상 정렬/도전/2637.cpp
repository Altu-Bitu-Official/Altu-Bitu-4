#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

// 위상 정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<ci>>& graph) {
	vector<int> result(n + 1, 0);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) { // 기본 부품
			q.push(i);
			result[i] = 1;
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			result[next_node] += result[node] * graph[node][i].second; // (부품의 개수) x (부품을 만들기 위해 필요한 기본 부품의 개수)를 더함
			indegree[next_node]--;
			if (!indegree[next_node]) {
				q.push(next_node);
			}
		}
	}
	return result;
}

/*
 * 완제품을 만들기 위해 필요한 기본 부품의 개수를 구하는 문제
 * y(필요한 부품) -> x(만들어지는 부품)의 관계를 역으로 만들면 x -> y가 되면서 루트 노드가 완제품이 되고 리프 노드가 기본 부품이 됨
 * 위상 정렬을 이용하여 부품의 개수를 계산
 */

int main()
{
	int n, m, x, y, k;
	// 입력
	cin >> n >> m;
	vector<int> indegree(n + 1, 0);
	vector<vector<ci>> graph(n + 1, vector<ci>(0));
	vector<bool> basic(n + 1, true); // 기본 부품: true, 중간 부품, 완제품: false
	while (m--) {
		cin >> x >> y >> k;
		indegree[y]++;
		graph[x].push_back({ y, k }); // y가 k개 필요
		basic[x] = false; // 다른 부품을 조립하여 만들어짐 -> 기본 부품이 아님
	}
	// 연산
	vector<int> result = topologicalSort(n, indegree, graph);
	// 출력
	for (int i = 1; i < n; i++) {
		if (basic[i]) { // 기본 부품만 출력
			cout << i << ' ' << result[i] << '\n';
		}
	}
	return 0;
}