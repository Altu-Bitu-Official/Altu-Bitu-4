// 플로이드
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e7; // V * 가중치의 최댓값

void floydWarshall(int n, vector<vector<int>> &graph){
    for (int k = 1; k <=n; k++){ // 중간 정점
        for (int i = 1; i<=n; i++){ // 출발 정점
            for (int j=1; j<=n; j++){ // 도착 정점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main()
{
    int n, m, a, b, c;
    
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector(n+1, INF));
    for (int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }
    while (m--){
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    floydWarshall(n, graph);
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}