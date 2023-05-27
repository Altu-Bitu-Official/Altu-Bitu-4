#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

const int INF = 9999999; // 최대 n-1개의 간선을 지나므로 n * (가중치 최대값)

int floydWarshall(int n, vector<vector<int>> &graph) {
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

    int count =0, result =0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            // 조건을 만족한다면 i와 j 사이의 대소 관계는 서로 알 수 있다는 뜻
            if(graph[i][j] != INF || graph[j][i] != INF){
                count++;
            }
        }
        // 서로의 키 대소관계를 아는 사람의 수가 n-1 + 자기 자신은 항상 알수 있으므로 1
        // 즉 count가 n이라면 자신의 키 순위를 알 수 있을 것이다.
        if(count == n){
            result++;
        }
        count =0;
    }
    return result;
}

int main() {
    int n, m;
    int taller, smaller;

    // 입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) { // 자기 자신과의 거리
        graph[i][i] = 0;
    }
    while (m--) {
        cin >> taller >> smaller;
        graph[taller][smaller] = 1;
    }

    // 연산 및 출력
    cout << floydWarshall(n, graph);
}