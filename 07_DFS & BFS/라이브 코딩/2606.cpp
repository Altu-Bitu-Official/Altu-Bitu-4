#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(int n, vector<vector<int> > &graph) {
    int result = 0;
    vector<bool> visited(n+1, false);
    stack<int> s;

    s.push(1);

    while(!s.empty()) {
        int node = s.top();
        bool child = false;

        cout << node;

        for(int i=0; i<=graph[node].size(); i++) {
            if(!visited[graph[node][i]]) {
                child = true;
                s.push(i);
                visited[graph[node][i]] = true;
                result++;
                break;
            }
        }
        if(!child) {
            s.pop();
        }
    }

    return result;
}

int main() {
    int n, m, n1, n2;
    cin >> n >> m;

    vector<vector<int> > graph;
    //graph.assign(n+1, vector<int> (n+1, 0));
    graph.assign(n+1, vector<int> (0));

    for(int i=0; i<m; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    //cout << graph[1].size();
    cout << dfs(n, graph);

    return 0;
}