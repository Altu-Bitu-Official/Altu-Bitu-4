#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(19, vector<int>(19, 0));
int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 같은 방향으로 계속 전진하다가 다른 숫자 만나면 or 바둑판 범위 넘어가면 depth 리턴
int inARow(int i, int d, int r, int c, int color)
{
    if (r < 0 || r >= 19 || c < 0 || c >= 19 || board[r][c] != color)
    {
        return d;
    }

    int nr = r + dr[i];
    int nc = c + dc[i];

    return inARow(i, d + 1, nr, nc, color);
}

int main()
{

    for (int r = 0; r < 19; r++)
    {
        for (int c = 0; c < 19; c++)
        {
            cin >> board[r][c];
        }
    }

    for (int r = 0; r < 19; r++)
    {
        for (int c = 0; c < 19; c++)
        {
            if (!board[r][c])
            {
                continue;
            }

            for (int i = 0; i < 8; i++)
            {
                // 리턴했을때 연속depth가 5였으면 승리!!     //양방향 고려해줌                     //양방향이므로 교집합 하나 빼줌
                if (5 == inARow(i, 0, r, c, board[r][c]) + inARow(7 - i, 0, r, c, board[r][c]) - 1)
                {
                    // 밑에서 왼쪽 방향으로 가는 경우에만 시작점이 최대왼쪽이 아니라서, 업데이트해줘야함
                    if (i == 0)
                    {
                        r += 4;
                        c -= 4;
                    }
                    cout << board[r][c] << '\n';
                    cout << r + 1 << ' ' << c + 1;
                    return 0;
                }
            }
        }
    }

    cout << '0';
}