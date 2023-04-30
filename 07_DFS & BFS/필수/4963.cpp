#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
typedef pair<int, int> pi;
// 좌 우 상 하 좌상 우상 좌하 우하
int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1};

void dfs(int r, int c, int h, int w, vector<vector<int>> &graph)
{
    // 시작점 방문
    visited[r][c] = true;
    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 지도를 벗어나지 않음, 섬일 것, 방문하지 않음
        if (nr >= 0 && nr < h && nc >= 0 && nc < w)
        {
            if (graph[nr][nc] == 1 && !visited[nr][nc])
            {
                dfs(nr, nc, h, w, graph);
            }
        }
    }
}

int main()
{
    // 너비, 높이
    int w, h;
    vector<vector<int>> graph; // 지도
    
    while (true)
    {
        int count = 0;
        // 섬의 개수
        cin >> w >> h;
        // 0 0 입력받으면 종료
        if (w == 0 && h == 0)
        {
            return 0;
        }

        //초기화
        graph.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));
        //입력
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
            }
        }

        // dfs
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (graph[i][j] == 1 && !visited[i][j])
                {
                    count++;
                    dfs(i, j, h, w, graph);
                }
            }
        }

        cout << count << "\n";
    }
}