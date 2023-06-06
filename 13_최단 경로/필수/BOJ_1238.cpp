#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int INF = 1e5;

//start 도시부터 x까지 가는 데 걸리는 소요 시간 반환
int cityToX(int start, int n, int x, vector<vector<ii>>& graph) {
	//1. start -> x 시간 계산
	vector<int> time1(n + 1, INF);
	priority_queue<ii, vector<ii>, greater<>> pq1; //{ 시작점으로부터의 시간, 정점 } 내림차순 정렬
	
	//시작 정점 초기화
	time1[start] = 0;
	pq1.push({ 0, start });

	while (!pq1.empty()) {
		int time = pq1.top().first;
		int node = pq1.top().second;
		pq1.pop();

		//이미 저장된 시간이 새로 구한 시간보다 작을 경우 넘어감
		if (time > time1[node]) {
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_time = time + graph[node][i].second;

			if (next_time < time1[next_node]) {
				time1[next_node] = next_time;
				pq1.push({ next_time, next_node });
			}
		}
	}
	return time1[x];
}

//x부터 각 도시까지 가는 데 걸리는 소요 시간 벡터 반환
vector<int> xToCity(int n, int x, vector<vector<ii>>& graph) {
	vector<int> time2(n + 1, INF);
	priority_queue<ii, vector<ii>, greater<>> pq2; //{ 시작점으로부터의 시간, 정점 } 내림차순 정렬

	//시작 정점 초기화
	time2[x] = 0;
	pq2.push({ 0, x });

	while (!pq2.empty()) {
		int time = pq2.top().first;
		int node = pq2.top().second;
		pq2.pop();

		//이미 저장된 시간이 새로 구한 시간보다 작을 경우 넘어감
		if (time > time2[node]) {
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_time = time + graph[node][i].second;

			if (next_time < time2[next_node]) {
				time2[next_node] = next_time;
				pq2.push({ next_time, next_node });
			}
		}
	}
	return time2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, x, a, b, t;
	cin >> n >> m >> x;

	vector<vector<ii>> graph(n + 1, vector<ii>()); //graph[시작점]: { 끝점, 소요시간 }
	while (m--) {
		cin >> a >> b >> t;
		graph[a].push_back({ b,t });
	}

	//연산
	vector<int> time = xToCity(n, x, graph);
	int max_time = 0;
	for (int i = 1; i <= n; i++) {
		max_time = max(max_time, cityToX(i, n, x, graph) + time[i]);
	}

	//출력
	cout << max_time;

	return 0;
}