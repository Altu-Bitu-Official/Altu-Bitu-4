#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1}; 

int cleaned(vector<vector<int>> &room, int r, int c, int d)
{
    // robot's current position
    int cur_r = r;
    int cur_c = c;
    int cur_d = d;
    int isDirty;
    int cnt = 0;
    int b;

    while (true)
    {
        // 주변에 더러운 빈칸이 없다.
        isDirty = -1;

        // 1. 현재 칸이 청소되지 않은 경우, 현재 칸을 청소한다.
        if (!room[cur_r][cur_c])
        {
            room[cur_r][cur_c] = -1;
            cnt++;
        }

        // 주변 4칸 중 청소되지 않은 빈칸이 있는가?
        for (int i = 0; i < 4; i++)
        {
            if (!room[cur_r + dr[i]][cur_c + dc[i]])
            {
                isDirty = i;
                break;
            }
        }
        
        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        if (isDirty == -1)
        {
            //     2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
            b = (cur_d + 2) % 4;
            if (room[cur_r + dr[b]][cur_c + dc[b]] != 1)
            {
                cur_r += dr[b];
                cur_c += dc[b];
                continue;
            }
            else
            {
                //      2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
                break;
            }
        }

        // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        else
        {
            //3-1. 반시계 방향으로 90도 회전한다.
            cur_d = (cur_d +3) % 4;
            //3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            if (!room[cur_r + dr[cur_d]][cur_c + dc[cur_d]])
            {
                cur_r += dr[cur_d];
                cur_c += dc[cur_d];
            }
           //3-3. 1번으로 돌아간다.
        }
    }

    return cnt;
}

int main()
{
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> room(n, vector<int>(m, 0));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }

    cout << cleaned(room, r, c, d);
}