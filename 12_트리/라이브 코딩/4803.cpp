// 트리 
#include <iostream>
#include <vector>
using namespace std;

/*
* 각 그래프가 트리인지 아닌지 판단
* 사이클이 생기면 트리 아님
* 사이클이 생긴다 -> DFS로 자기 자신으로 돌아올 수 있다.
*/


void dfs(bool &flag, int cur, int prev, vector<vector<int>> &g, vector<bool> &visited){
    // 방문한 곳을 다시 방문 -> 트리 X
    if (visited[cur]){
        flag = false;
        return;
    }
    // 방문한 곳 표시
    visited[cur] = true;
    
    // 다음 탐색 -> 부모 노드는 X (이전 노드)
    for (int next : g[cur]){
        if (next == prev){
            continue;
        }
        dfs(flag, next, cur, g, visited);
    }
    return;
}
// 트리 개수 출력
void printTree(int t, int cnt){
    cout << "Case " << t << ": ";
    if (cnt >= 2){
        cout << "A forest of "<< cnt << " trees.\n";
    }
    else if (cnt == 1){
        cout << "There is one tree.\n";
    }
    else{
        cout << "No trees.\n";
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v1, v2, t = 0;
    while (true){
        cin >> n >> m;
        if (!n && !m){
            break;
        }
        t++;
        // 그래프 입력
        vector<vector<int>> g(n+1, vector<int>(0));
        for (int i = 0; i < m; i++){
            cin >> v1 >> v2;
            g[v1].push_back(v2); // 간선 연결
            g[v2].push_back(v1);
        }
        // 탐색
        int cnt = 0; // 트리 개수
        vector<bool> visited(n+1, false); // 방문여부
        
        // 모든 정점을 루트 노드로 탐색
        for (int i = 1; i <= n; i++){
            if (visited[i]){
                continue;
            }
            bool flag = true; // 트리인지 여부
            dfs(flag, i, 0, g, visited);
            if (flag){ // 트리이면
                cnt ++;
            }
        }
        printTree(t, cnt);
    }
    return 0;
}