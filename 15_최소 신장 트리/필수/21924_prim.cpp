#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e6 + 1;

long long prim(int v, int start, vector<vector<ci>>& graph) {
	int cnt = 0; //visit한 정점 수
	long long sum = 0;
	vector<bool> visited(v + 1, false); //방문 check
	vector<int> cost(v + 1, INF); //cost
	priority_queue<ci, vector<ci>, greater<>> pq; // min heap

	//초기화
	pq.push({ 0, start });
	cost[start] = 0;

	while (!pq.empty()) {
		auto [curr_w, curr] = pq.top();
		pq.pop();

		if (visited[curr]) { 
			continue;
		}
		cnt++; // 연결된 건물의 수 세기
		visited[curr] = true;  
		sum += curr_w; 

		for (auto [next_w, next] : graph[curr]) {
			if (!visited[next] && cost[next] > next_w) { 
				cost[next] = next_w;
				pq.push({ next_w, next });
			}
		}
	}
	if (cnt != v) { // 모든 건물을 연결할 수 없는 경우
		return -1;
	}
	return sum;
}

/*
* 주의: 최소한의 도로를 건설하는 비용이 아닌 절약한 비용을 구해야 함
* 모든 건물이 연결되어 있는지 확인해야 함
* 프림 알고리즘을 이용하여 총 비용 구하기
*/

int main() {
	int n, m, a, b, c;
	long long total_price = 0;
	// 입력
	cin >> n >> m;
	vector<vector<ci>> graph(n + 1);
	while (m--) {
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
		total_price += c;
	}
	// 연산 & 출력
	long long result = prim(n, 1, graph);
	if (result == -1) { 
		cout << result << '\n';
	}
	else { // 절약한 비용 = 총 비용 - 최소한의 도로를 연결하는데 드는 비용
		cout << total_price - result << '\n';
	}
	return 0;
}