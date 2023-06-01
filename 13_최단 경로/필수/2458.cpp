#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 501; // 최대 n-1개의 간선을 지나므로 n * (가중치 최대값)

// 그래프 초기화 함수
void init(int n, vector<vector<int>>& graph) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}
	// 자기 자신으로의 거리는 0으로 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
}

// 플로이드-워셜 알고리즘을 이용해 그래프의 최단 거리를 계산
void floydWarshall(int n, vector<vector<int>>& graph) {
	for (int k = 1; k <= n; k++) { // 중간 정점
		for (int i = 1; i <= n; i++) { // 출발 정점
			for (int j = 1; j <= n; j++) { // 도착 정점
				// 중간에 k를 거쳐서 i에서 j로 갈 때의 비용
				int cost = graph[i][k] + graph[k][j];
				// 더 짧은 경로 선택
				graph[i][j] = min(graph[i][j], cost);
			}
		}
	}
}

// 학생들의 키 순서를 알 수 있는 학생들의 수를 계산
int countStudents(int student, int n, vector<vector<int>>& graph) {
	int i = 1, cnt = 0;
	for (i = 1; i <= n; i++) {
		// 학생과 다른 모든 학생들과의 거리가 무한대이면 키 순서를 알 수 없음
		if (student != i && graph[student][i] == INF && graph[i][student] == INF) {
			return 0;
		}
	}
	// 학생의 키 순서를 알 수 있으면 1 반환
	return 1;
}

/*
 * 키순서
 * 내 키의 순위를 안다 <-> 내가 상대방과의 키 우열을 안다 or 상대방이 나와의 키 우열을 안다
*/
int main()
{
	int n, m;
	int answer = 0;
	vector<vector<int>> graph(INF, vector<int>(INF));
	// 입력
	cin >> n >> m;
	init(n, graph); // 초기화
	while (m--) {
		int a, b; cin >> a >> b;
		graph[a][b] = 1; // 키 우열을 아는 두 정점의 거리를 1이라고 하자
	}
	// 연산
	floydWarshall(n, graph);
	for (int i = 1; i <= n; i++) { // 자신의 키가 몇 번째인지 알 수 있는 학생들이 몇 명인지 계산
		answer += countStudents(i, n, graph);
	}
	// 출력
	cout << answer << '\n';
	return 0;
}