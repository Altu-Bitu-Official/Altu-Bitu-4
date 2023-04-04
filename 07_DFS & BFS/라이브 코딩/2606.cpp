#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited_dfs;

void dfs(int node, vector<vector<int>> &graph) {
    visited_dfs[node] = true;

    for(int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];
        if(!visited_dfs[next_node]) {
            dfs(next_node, graph);
        }
    }
}

int bfs(int n, vector<vector<int>> &graph) {
    int cnt = 0;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            if(!visited[next_node]) {
                q.push(next_node);
                visited[next_node] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m, n1, n2;
    vector<vector<int>> graph;

    // 입력
    cin >> n >> m;
    graph.assign(n+1, vector<int> (0));
    //visited_dfs.assign(n+1, false);
    while(m--) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    // 연산 & 출력
    cout << bfs(n, graph);
    /*dfs(1, graph);
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(visited_dfs[i]) {
            cnt++;
        }
    }
    cout << cnt;*/
    return 0;
}