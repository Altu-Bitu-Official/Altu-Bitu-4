#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;

int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int h, int w, vector<vector<int>> graph)
{
    queue<pair<int, int>> q;

    q.push(make_pair(h, w));
    visited[h][w] = true;

    while (!q.empty())
    {
        int h = q.front().first;
        int w = q.front().second;
        q.pop();

        for (int idx = 0; idx < 8; idx++)
        {
            int hx = h + x[idx];
            int wx = w + y[idx];

            if (hx < 0 || wx < 0 || hx >= 50 || wx >= 50) // 범위는 0~49까지만 생각하기위해
            {
                continue;
            }
            if (graph[hx][wx] && !visited[hx][wx])
            {
                visited[hx][wx] = true;
                q.push(make_pair(hx, wx));
            }
        }
    }
}

int main()
{
    int w, h;
    vector<vector<int>> graph;
    while (true)
    {
        int cnt = 0;

        cin >> w >> h;

        graph.assign(h + 1, vector<int>(w + 1, 0));
        visited.assign(h + 1, vector<bool>(w + 1, false));

        if (w == 0 && h == 0)
        {
            break; // while문 빠져나가기, 종료
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (graph[i][j] && !visited[i][j]) // graph가 존재 && 아직 방문하지않음
                {
                    cnt++;
                    bfs(i, j, graph);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}