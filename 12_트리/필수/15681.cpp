// 트리와 쿼리 - 메모리 초과
#include <iostream>
#include <vector>
using namespace std;

// DFS
void dfs(int n, int parent, int cur_node, vector<int> &vertex, vector<bool> &visited, vector<vector<bool>> &edge){
    visited[cur_node] = true; // 방문
    for (int next_node = 1; next_node <= n; next_node++){
        if (edge[cur_node][next_node] and !visited[next_node]){ // 연결되어있고 아직 방문하지 않았으면
            dfs(n, cur_node, next_node, vertex, visited, edge);
        }
    }
    vertex[parent] += vertex[cur_node];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력
    int n, r, q, u, v;
    cin >> n >> r >> q;
    vector<vector<bool>> edge(n+1, vector<bool>(n+1, false)); // 간선 여부
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }
    vector<bool> visited(n+1, false); // 정점 방문 여부
    vector<int> vertex(n+1, 1); // 정점별 서브트리 정점수
    
    dfs(n, 0, r, vertex, visited, edge);
    
    // Input & Output
    while (q--){
        cin >> u;
        cout << vertex[u] << '\n';
    }
    return 0;
}