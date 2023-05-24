// 7576번
#include <iostream>
#include <queue>
#include <vector>
// 최단거리- bfs - queue
using namespace std;

typedef pair<int, int> pi;

int bfs(int n, int m, int raw, queue<pi> &q, vector<vector<int>> &box)
{
    int t;                                            // 토마토가 모두 익는 시간
    int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1}; // 상하 좌우

    while (!q.empty())
    { // 익은 토마토의 위치
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        t = box[row][col];

        // 인접한 4칸 확인
        for (int i = 0; i < 4; i++)
        { // 새로운 좌표
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && box[nr][nc] == 0)
            {
                box[nr][nc] = t + 1;
                raw--; // 덜익은 토마토가 하나 익었다
                q.push({nr, nc});
            }
        }
    }
    if (raw == 0)
    { // 토마토가 다 익은 경우
        return t - 1;
    }
    // 토마토가 하나라도 덜 익은 경우
    return -1;
}
int main()
{
    int m, n;                // 가로, 세로 칸 수
    vector<vector<int>> box; // 토마토 상자
    queue<pi> q;             // 익은 토마토 위치 저장
    int raw;                 // 익지 않은 토마토 수

    cin >> m >> n;
    box.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];

            // 익은 토마토가 나오면 위치 저장
            if (box[i][j] == 1)
            {
                q.push({i, j});
            }
            else if (box[i][j] == 0)
            { // 익지 않은 토마토가 나오면
                raw++;
            }
        }
    }
    return 0;
}