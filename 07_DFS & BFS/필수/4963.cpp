#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

void dfs(int x, int y, int h, int w, vector<vector<int>> &map) { // dfs 탐색
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dc[8] = {0, 0, -1, 1, 1, -1, 1, -1}; // 상 하 좌 우 + 대각선
    map[x][y] = 2; // 방문한 땅은 2로 표시

    for(int i = 0; i < 8; i++) { // 8방향 탐색
        int nr = x + dr[i];
        int nc = y + dc[i];
        // 아직 방문하지 않은 땅이면 dfs 탐색
        if(nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) { 
            dfs(nr, nc, h, w, map);
        }
    }
}

int solution(int h, int w, vector<vector<int>> &map, vector<pi> &to_find) {
    int cnt = 0;

    // 땅인 좌표들만 탐색
    for(int i = 0; i < to_find.size(); i++) {
        int x = to_find[i].first;
        int y = to_find[i].second;

        if (map[x][y] == 2) { // 이미 방문되었다면
            continue;
        }
        // 아직 방문하지 않은 땅이면 탐색 시작
        dfs(x, y, h, w, map);

        // 땅인 한 좌표에서 시작해 탐색이 끝났다면 섬이 완성된 것
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int w, h; // 너비, 높이
    vector<vector<int>> map; // 전체 땅

    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) {
            break;
        }
        map.assign(h, vector<int>(w, 0));
        vector<pi> to_find(0); // 땅의 좌표만 저장

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
                if (map[i][j]) { // 땅이면
                    to_find.push_back({i, j}); // 탐색할 좌표에 저장
                }
            }
        } 
        // 출력
        cout << solution(h, w, map, to_find) << '\n';
    }   
    return 0;
}