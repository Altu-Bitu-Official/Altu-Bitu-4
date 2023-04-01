#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> dfs(int n, int v, vector<vector<bool> > &edge) {
    vector<int> dfs_result;
    vector<bool> visited (n+1, false);
    stack<int> s;

    s.push(v);
    visited[v]=true;
    dfs_result.push_back(v);

    while(!s.empty()) {
        int node = s.top();
        bool child = false;

        for(int i=1; i<=n; i++) {
            if(edge[node][i] && !visited[i]) {
                child = true;
                s.push(i);
                visited[i] = true;
                dfs_result.push_back(i);
                break;
            }
        }
        //인접 정점 못 찾으면 끝까지 탐색 완료한거니까 pop
        if(!child) {
            s.pop();
        }
    }

    return dfs_result;
}

vector<int> bfs(int n, int v, vector<vector<bool> > &edge) {
    vector<int> bfs_result;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(v);
    visited[v]=true;
    bfs_result.push_back(v);

    while(!q.empty()) {
        int node = q.front();

        for(int i=1; i<=n; i++) {
            if(edge[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                bfs_result.push_back(i);
            }
        }

        q.pop();
    }

    return bfs_result;
}

int main() {
    int n, m, v, n1, n2;
    cin >> n >> m >> v;

    vector<vector<bool> > edge;
    edge.assign(n+1, vector<bool> (n+1, false));

    for(int i=0; i<m; i++) {
        cin >> n1 >> n2;
        edge[n1][n2] = true;
        edge[n2][n1] = true;
    }

    vector<int> dfs_result = dfs(n, v, edge);
    vector<int> bfs_result = bfs(n, v, edge);

    for(int d: dfs_result) {
        cout << d << " ";
    }
    cout << "\n";
    for(int b: bfs_result) {
        cout << b << " ";
    }

    return 0;
}