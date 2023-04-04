#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// bfs를 통한 섬 개수 세기

int cntIsland(vector<vector<int>> &map, int h, int w)
{
    // 미개척 땅이 1이므로 2부터 셈
    int cnt = 1;
    queue<pi> ut;

    // cout << "^__^";

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // 개척 안한 땅 발견하면 "새 섬이다!"
            if (map[i][j] == 1)
            {
                cnt++;
                map[i][j] = cnt;
                ut.push({i, j});

                // 해당 섬 끝까지 마킹
                while (!ut.empty())
                {
                    pi land = ut.front();
                    ut.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        int nr = land.first + dr[k];
                        int nc = land.second + dc[k];

                        if (nr >= 0 && nr < h && nc >= 0 && nc < w && map[nr][nc] == 1)
                        {
                            map[nr][nc] = cnt;
                            ut.push({nr, nc});
                        }
                    }
                }

            }
        }
    }
    return --cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;

    while (true)
    {
        cin >> w >> h;
        if (!w && !h)
        {
            break;
        }

        vector<vector<int>> map(h, vector<int>(w, 0));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        cout << cntIsland(map, h, w) << '\n';
    }
}