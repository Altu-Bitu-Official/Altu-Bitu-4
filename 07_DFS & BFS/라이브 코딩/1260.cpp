#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<bool> visited_recur;

vector<int> dfs(int n, int v, vector<vector<bool>> &edge) {
    vector<int> result;
    vector<bool> visited (n+1, false);
    stack<int> s;

    s.push(v);
    visited[v] = true;
    result.push_back(v);

    while(!s.empty()) {
        int node = s.top();
        bool child = false;

        for(int i = 1; i <= n; i++) {
            if(edge[node][i] && !visited[i]) {
                child = true;
                s.push(i);
                visited[i] = true;
                result.push_back(i);
                break;
            }
        }
        if(!child) {
            s.pop();
        }
    }
    return result;
}

void dfsRecur(int n, int node, vector<vector<bool>> &edge) {
    visited_recur[node] = true;
    cout << node << ' ';

    for(int i = 1; i <= n; i++) {
        if(edge[node][i] && !visited_recur[i]) {
            dfsRecur(n, i, edge);
        }
    }
}

vector<int> bfs(int n, int v, vector<vector<bool>> &edge) {
    vector<int> result;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int i = 1; i <= n; i++) {
            if(edge[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return result;
}

int main() {
    int n, m, v, n1, n2;
    vector<vector<bool>> edge;

    // 입력
    cin >> n >> m >> v;
    edge.assign(n+1, vector<bool> (n+1, false));
    visited_recur.assign(n+1, false);
    while(m--) {
        cin >> n1 >> n2;
        edge[n1][n2] = true;
        edge[n2][n1] = true;
    }

    // 연산
    vector<int> dfs_result = dfs(n, v, edge);
    vector<int> bfs_result = bfs(n, v, edge);

    // 출력
    for(int i = 0; i < dfs_result.size(); i++) {
        cout << dfs_result[i] << ' ';
    }
    cout << '\n';
    //dfsRecur(n, v, edge);
    for(int i = 0; i < bfs_result.size(); i++) {
        cout << bfs_result[i] << ' ';
    }
    return 0;
}