#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dy[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };


using namespace std;

const int MAX = 50;


void dfs(vector<vector<int>> map, vector<vector<bool>> &visited, int y, int x) {
    
    visited[y][x] = true; // 시작점

    for (int i = 0; i < 8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (0 <= tx && 0 <= ty && tx < MAX && ty < MAX) {
            if (map[ty][tx] && !visited[ty][tx]) {
                visited[ty][tx] = true;
                dfs(map, visited, ty, tx);
            }
        }
    }
}

int main() {

    while (1) {
        int x, y;
        int island = 0;

        vector<vector<int>> map(MAX, vector<int>(MAX, 0));
        vector<vector<bool>> visited(MAX, vector<bool>(MAX, false)); // 방문표시
        
        // 입력
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                // 방문하지 않은 섬에 대해 dfs
                if (map[i][j] && !visited[i][j]) {
                    island++;
                    dfs(map, visited, i, j);
                }
            }
        }

        cout << island << endl;

    }
    return 0;
}
