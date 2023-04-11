#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(int n, int v, vector<vector<int> > &map) {
    int cnt = 0;
    vector<bool> visited (n+1, false);
    queue<int> q;

    q.push(v);
    visited[v]=true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i=0; i<map[node].size(); i++) {
            int next = map[node][i];
            if(!visited[next]) {
                q.push(next);
                visited[next]=true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, i, j, max=0;
    set<int> result;
    cin >> n >> m;

    vector<vector<int> > map(n+1, vector<int> (0));

    while(m--) {
        cin >> i >> j;
        map[j].push_back(i);
    }

    for(int i=1; i<=n; i++) {
        //각 노드로 해킹할 수 있는 컴퓨터 수 BFS 탐색
        int tmp = bfs(n, i, map);
        //더 많으면 max 값 바꿔주고 결과 배열 초기화
        if(tmp > max) {
            max=tmp;
            result.clear();
            result.insert(i);
        //같으면 결과 배열에 추가
        } else if (tmp == max) {
            result.insert(i);
        }
    }

    for (auto node : result) {
        cout << node << " ";
    }

    return 0;
}