#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> pi;
//
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int n = maps.size();
    int m = maps[0].size();

    // 시작점 0,0에서 BFS 실행
    queue<pi> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < n && nr >= 0 && nc < m && nc >= 0 && maps[nr][nc] == 1)
            {
                maps[nr][nc] = maps[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    if (maps[n - 1][m - 1] == 1)
    {
        answer = -1;
    }
    else
    {
        answer = maps[n - 1][m - 1];
    }
    return answer;
}