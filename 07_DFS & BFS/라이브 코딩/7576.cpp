#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int m, vector<vector<int> > edge, queue<pair<int, int> > &q, int raw) {
    int day = 0;
    vector<int> bfs_result;

    //대각선 방향 영향주지 않으므로 상하 좌우만 확인
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        day = edge[r][c];

        for(int i=0; i<4; i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && edge[nr][nc]==0) {
                edge[nr][nc] = day+1;
                q.push(make_pair(nr, nc));
                raw--;
            }
        }
        q.pop();
    }

    if(raw>0) {
        return -1;
    }
    return day-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    queue<pair<int, int> > q;
    int raw = 0;

    cin >> m >> n;

    vector<vector<int> > edge;
    edge.assign(n, vector<int> (m, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> edge[i][j];
            if(edge[i][j]==1) {
                q.push(make_pair(i,j));
            } else if(edge[i][j]==0) {
                raw++;
            }
        }
    }

    cout << bfs(n, m, edge, q, raw);

    return 0;
}