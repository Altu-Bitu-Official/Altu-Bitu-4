
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<bool> visited;

void cntSubTrees(int v, int p, vector<vector<int>> &edge) { // 현재 노드, 부모 노드
    for(int child : edge[v]) { // v에 연결된 노드들
        if(visited[child]) { // 이미 방문되었으면
            continue;
        }
        // 방문 체크
        visited[v] = true;

        cntSubTrees(child, v, edge); // 자식 노드, 현재 노드를 전달
        dp[v] += dp[child];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, q, v1, v2, u; // 정점 수, 루트 번호, 쿼리 수

    // 입력
    cin >> n >> r >> q;
    vector<vector<int>> edge(n+1);
    dp.assign(n+1, 1); // 자기 자신도 카운트에 포함
    visited.assign(n+1, false);

    for(int i = 0; i < n - 1; i++){ 
        cin >> v1 >> v2;

        // 양방향 구현
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }

    // 연산
    cntSubTrees(r, -1, edge);

    while(q--) {
        cin >> u;
        // 출력
        cout << dp[u] << '\n';
    }

    return 0;
}