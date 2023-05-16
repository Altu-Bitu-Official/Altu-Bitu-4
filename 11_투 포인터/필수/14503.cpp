// 14503 로봇 청소기
/*
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int convertDir(int &dir){ // 방향 전환
    if(dir == NORTH) {
        return WEST;
    }
    else if(dir == EAST) {
        return NORTH;
    }
    else if(dir == SOUTH) {
        return EAST;
    }
    else {
        return SOUTH;
    }
}

int goBackDir(int &dir){ // 현재 방향에서 후진 구현
    if(dir == NORTH){
        return WEST;
    }
    else if(dir == EAST) {
        return SOUTH;
    }
    else if(dir == SOUTH) {
        return NORTH;
    }
    else {
        return EAST;
    }
}

void dfs(vector<vector<int>> &map, vector<vector<bool>> vis, int &N, int &M, int x, int y, int dir, int cnt) {
    bool flag = false; // 현재 위치에서 4방향 탐색 했을 시 청소할 수 있는 좌표가 있다면
    for(int i = 0; i < 4; i++){
        int n_dir = convertDir(dir);
        int nx = x + dx[n_dir];
        int ny = y + dy[n_dir];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }
        if(vis[nx][ny] || map[nx][ny] != 0) {
            continue;
        }

        vis[nx][ny] = true; // 해당 좌표 청소해주고
        dfs(map, vis, N, M, nx, ny, n_dir, cnt+1); 
    }
    if(!flag){ // 현재 위치에서 청소할 수 있는 좌표가 없다면 후진 oR 종료
        int prev_dir = goBackDir(dir);
        int prev_x = x + dx[prev_dir];
        int prev_y = y + dy[prev_dir];
        if(prev_x >= 0 && prev_y >= 0 && prev_x < N && prev_y < M){ // 맵 탐색에 벗어나지 않고
            if(map[prev_x][prev_y] != 1) { // 뒤 좌표가 벽이 아니라면 
                dfs(map, vis, N, M, prev_x, prev_y, dir, cnt);
            }
        }
        else {
            cout << cnt << "\n"; 
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M;
    int st_x, st_y, st_d;
    cin >> N >> M;
    cin >> st_x >> st_y >> st_d;
    vector<vector<int>> map(N, vector<int>(M, 0)); // 맵
    vector<vector<bool>> vis(N, vector<bool>(M, false)); // 청소했는지 안했는지 체크해주는 배열
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    dfs(map, vis, N, M, st_x, st_y, st_d, 1);
    return 0;
}