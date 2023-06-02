#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9; 
// 자신의 키가 몇 번째인지 알 수 있는 학생 수 출력 
// 두 학생 사이에 간선 존재 O -> 비교 가능 == 몇 번째인지 알 수 있음
// 간선 존재 X -> 비교 불가능 (가중치가 초기화한 값인 INF로 설정되어있음)

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M; // 학생 수, 비교한 횟수
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF)); 
    for (int i = 1; i <= N; i++) { // 자기 자신과의 거리
        graph[i][i] = 0;
    }

    int a, b;
    while (M--) {
        cin >> a >> b;  // a<b == a->b
        graph[a][b] = 1; // 두 학생사이의 간선이 있는 경우
    }
    floydWarshall(N, graph);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        bool check = true; // 비교 가능
        for (int j = 1; j <= N; j++) {
            if (i != j && graph[i][j] == INF && graph[j][i] == INF) {
                // 둘이 같지 않고 가중치가 INF이면
                // i번째 학생과 j번째 학생 사이의 경로가 없음 
                check = false; // 비교 불가능 
                break;
            }
        }
        if (check) count++; 
    }
    cout << count;
	return 0;
}