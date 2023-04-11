#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

// 섬의 개수 출력 (1: 땅, 0: 바다)
// 섬끼리 가로,세로,대각선 중 하나로 연결-> 같은 섬

int bfs(int m, int n, vector<vector<int>>& map) {// m: 가로, n: 세로
    // 위쪽: r-1[0] , 아래: r+1[1], 왼쪽: c-1[2], 오른쪽: c+1[3]
    // 대각선 왼쪽 위: r-1 & c-1[4], 대각선 오른쪽 위: r-1 & c+1[5]
    // 대각선 왼쪽 아래: r+1 & c-1[6], 대각선 오른쪽 아래: r+1 & c+1[7]

    int cnt = 0; // 섬의 개수
    queue<pi> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int dr[8] = { -1, 1, 0, 0 ,-1,-1, 1, 1 };
    int dc[8] = { 0, 0, -1, 1, -1, 1,-1, 1 };

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                q.push({ i, j }); // 초기 큐에 (i, j)를 추가
                visited[i][j] = 1;
                
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second; // 큐에 저장된 (r,c) 좌표
                    q.pop();
                    
                    // 대각선 포함 인접 8칸 확인
                    for (int k = 0; k < 8; k++) { 
                         // 새로운 좌표
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        
                        // 지도 내에 있고 땅이라면 
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 1) {
                            if (!visited[nr][nc] && map[nr][nc]) {
                                visited[nr][nc] = 1;
                                q.push({ nr, nc });
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int w, h;
    while (1) {
        cin >> w >> h; // 너비, 높이 
        if (w == 0 && h == 0) break; // 0 0 입력시 종료
        vector<vector<int>>map(h, vector <int>(w, 0)); // 벡터 0으로 초기화

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        cout << bfs(w, h, map) << "\n";
    }
    return 0;
}
