// 바이러스
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<bool> visited_dfs;
void dfs(int node, vector<vector<int>> &edges){
    visited_dfs[node] = true;
    
    for (int i=0; i<edges[node].size(); i++){
        int next_node = edges[node][i];
        if (!visited_dfs[next_node])
            dfs(next_node, edges);
    }
}

int bfs(int n, vector<vector<int>> &edges){
    int cnt = 0; // 감염된 컴퓨터 수
    vector<bool> visited(n+1, false);
    queue<int> q;
    
    // 첫번째 노드 처리
    visited[1] = true;
    q.push(1);
    
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (int i=0; i<edges[node].size(); i++){
            int next_node = edges[node][i];
            if (!visited[next_node]){
                visited[next_node] = true;
                q.push(next_node);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, m, v1, v2;
    vector<vector <int>> edges;
    
    cin >> n >> m;
    edges.assign(n+1, vector<int> (0));
    
    for (int i=0; i<m; i++){
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    // BFS
    cout << "BFS: " << bfs(n, edges);
    
    //DFS
    int cnt = 0;
    visited_dfs.assign(n+1, false);
    dfs(1, edges);
    for (int i=2; i<=n; i++){ // 두번째 노드부터 탐색한 노드 세기
        if(visited_dfs[i]){
            cnt++;
        }
    }
    cout << '\n' << "DFS: " << cnt;
    return 0;
}