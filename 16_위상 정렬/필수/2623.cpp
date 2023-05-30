#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 위상 정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		result.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];
			indegree[next_node]--;
			if (!indegree[next_node]) {
				q.push(next_node);
			}
		}
	}
	
	if (result.size() != n) { //사이클이 존재하는 경우
		result = { 0 };
	}
	return result;
}

/*
* 선후 관계가 주어져 있으므로 위상 정렬로 순서 정하기
* 순서를 정하는 것이 불가능한 경우 -> 사이클이 존재 (결과 배열의 길이 > 가수의 수)
*/

int main()
{
	int n, m, num, s1, s2;
	// 입력
	cin >> n >> m;
	vector<int> indegree(n + 1, 0);
	vector<vector<int>> graph(n + 1, vector<int>(0));
	while (m--) {
		cin >> num >> s1;
		for (int i = 0; i < num - 1; i++) { // 가수의 선후 관계를 저장
			cin >> s2;
			graph[s1].push_back(s2);
			indegree[s2]++;
			s1 = s2; 
		}
	}
	// 연산
	vector<int> ans = topologicalSort(n, indegree, graph);
	// 출력
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
	return 0;
}