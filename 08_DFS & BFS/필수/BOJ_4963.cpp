#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

const int visited = 2; // 방문체크

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 8가지 방향 행
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 렬

void bfs(int i, int j, int h, int w, vector<vector<int>> &map)
{
    queue<pi> q;
    q.push({i, j});
    map[i][j] = visited; // 첫번째위치를 2로 만든다

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int idx = 0; idx < 8; idx++) // 8가지방향 이어진 땅 탐색
        {
            int nr = r + dr[idx];
            int nc = c + dc[idx];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1) // 범위내 && 땅이면
            {
                q.push({nr, nc});
                map[nr][nc] = visited; // 방문했다고 체크하기
            }
        }
    }
}

int cntIsland(int h, int w, vector<vector<int>> &map)
{
    int cnt = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 1) // 땅이면
            {
                cnt++;                // 일단 cnt증가시키기
                bfs(i, j, h, w, map); // 이어진 땅 탐색하기
            }
        }
    }
    return cnt; // 한개의 섬인 h w에 대해서 존재하는 섬개수 반환하기
}
int main()
{
    int w, h; // 가로 세로
    vector<vector<int>> map;

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }
        map.assign(h, vector<int>(w, 0)); // 0으로 초기화 왜냐하면 다음번에 새로 입력받아야하는 h w가 존재하기 때문에

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }
        cout << cntIsland(h, w, map) << "\n";
    }
    return 0;
}

/* 기존 제출 코드
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;
typedef pair<int,int> pi;
int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int h, int w, vector<vector<int>> graph)
{
    queue<pi> q;

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

        cin >> w >> h;  //가로 세로

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
}*/