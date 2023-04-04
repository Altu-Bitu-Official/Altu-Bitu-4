//참고 : https://github.com/Altu-Bitu-Official/Altu-Bitu-4/blob/main/07_DFS%20%26%20BFS/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2606.cpp

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n,int i, vector<vector<int>> &graph) {
    int cnt = 0;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(i);
    visited[i] = true;

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
    int max=0;
    vector<vector<int>> graph;
    vector<int> count;

    // 입력
    cin >> n >> m;
    graph.assign(n+1, vector<int> (0));
    count.assign(n+1,0);

    while(m--) {
        cin >> n1 >> n2;
        graph[n2].push_back(n1);
    }

    for(int i=1;i<=n;i++){
        count[i] = bfs(n,i,graph);
        if(max<=count[i]){
            max=count[i];
        }
    }

    for(int i=1;i<=n;i++){
        if(count[i] == max){
            cout<<i<<' ';
        }
    }

    return 0;
}