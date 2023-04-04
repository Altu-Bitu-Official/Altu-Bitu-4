#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int bfs(int n, int m, int raw, queue<pi> &q, vector<vector<int>> &box) {
    int w;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        w = box[r][c];
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && box[nr][nc] == 0) {
                q.push({nr, nc});
                box[nr][nc] = w + 1;
                raw--;
            }
        }
    }

    if(raw == 0) {
        return w-1;
    }
    return -1;
}

int main() {
    int n, m, raw = 0;
    vector<vector<int>> box;
    queue<pi> q;

    // 입력
    cin >> m >> n;
    box.assign(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                q.push({i, j});
            }
            else if(box[i][j] == 0){
                raw++;
            }
        }
    }

    // 연산 & 출력
    if(raw == 0) {
        cout << 0;
    }
    else {
        cout << bfs(n, m, raw, q, box);
    }
    return 0;
}