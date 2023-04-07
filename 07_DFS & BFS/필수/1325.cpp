#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int n, int i, vector<vector<int>> &edge) {
    int cnt = 0; // 컴퓨터 개수 카운트
    vector<bool> visited(n+1, false); // 해킹 여부 저장
    queue<int> q;
    
    // 시작 정점 방문 체크
    visited[i] = true;
    q.push(i);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        // 연결된 컴퓨터 탐색
        for(int i = 0; i < edge[node].size(); i++) { 
            int next_node = edge[node][i]; // 연결된 컴퓨터
            if(!visited[next_node]) {
                visited[next_node] = true; // 방문 체크
                cnt++;                     // 해킹 개수 더하기
                q.push(next_node);         // 연결된 다음 컴퓨터 탐색
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; // 컴퓨터 개수, 입력 줄 개수
    int a, b;
    // 인접 리스트 이용
    vector<vector<int>> edge;

    cin >> n >> m;
    edge.assign(n+1, vector<int>(0));

    while(m--) {
        cin >> a >> b; 
        edge[b].push_back(a); // a가 b를 신뢰한다
    }

    int max = 0;           // 해킹 최대값
    vector<int> max_idx(0); // 가장 많이 해킹할 수 있는 컴퓨터를 저장하는 벡터

    for (int i = 1; i <= n; i++) {
        if(edge[i].size() == 0) { // 연결된 컴퓨터가 없다면 넘어감
            continue;
        }
        
        int cnt = bfs(n, i, edge); // 해킹할 수 있는 개수 구하기

        if(cnt > max) {          // 새로운 최대값 등장
            max_idx.clear();
            max = cnt;
            max_idx.push_back(i);
        }
        else if(cnt == max) {    // 이전 최대값과 같다면
            max_idx.push_back(i); // 벡터에 저장
        }
    }

    // 1번부터 n번까지 차례대로 bfs를 실행하므로 정렬 필요 X
    for(int i = 0; i < max_idx.size(); i++) {
        cout << max_idx[i] << " "; 
    }

    return 0;
}