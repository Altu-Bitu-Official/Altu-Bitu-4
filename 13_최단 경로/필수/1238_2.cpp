// 파티
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5;

void floydWarshall(int end, int n, vector<vector<ci>> &way, vector<vector<int>> &graph){
    for (int k = 1; k<=n; k++){ // 중간 정점
        for (int i = 1; i<=n; i++){ // 출발 정점
            for (int j = 1; j<=n; j++){ // 도착 정점
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
    int max_cost = 0;
    for (int i = 1; i<=n; i++){
        max_cost = max(max_cost, graph[i][end] + graph[end][i]);
    }
    cout << max_cost;
}

int main()
{  
    int n, m, x, start, end, t;
    cin >> n >> m >> x;
    vector<vector<ci>> way(n+1, vector<ci>(0)); // 특정 지점에서 출발해 갈 수 있는 곳과 시간
    vector<vector<int>> graph(n+1, vector<int>(n+1,INF));
    
    for (int i = 1; i<=n; i++){
        graph[i][i] = 0; // 출발지점과 도착지점이 같은 경우
    }
    
    for (int i = 2; i <= m+1; i++){
        cin >> start >> end >> t;
        way[start].push_back({end, t});
        graph[start][end] = min(graph[start][end], t);
    }
    floydWarshall(x, n, way, graph);
    
    return 0;
}