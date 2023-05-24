#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2;

int dx[4] = {0, 1, 0, -1}; // 북 동 남 서
int dy[4] = {-1, 0, 1, 0};

int clean(int n, int m, int r, int c, int d, vector<vector<int>> board)
{
    int cnt = 0; // cnt : 청소하는 칸의 개수

    while (true)
    {
        if (board[r][c] != CLEAN) // 현재 칸이 청소되지않았다면
        {
            cnt++; // 청소한 칸 증가시킴
        }

        board[r][c] = CLEAN; // 청소했다고 표시

        bool find = false;          // 현재 칸의 주변 4칸 중 청소되지않은 빈칸이 있는가
        for (int i = 0; i < 4; i++) // 동서남북 탐색
        {
            int nd = (d - i + 3) % 4; // 90도 반시계 회전 북 -> 서
            int nr = r + dy[nd];      // nr값 반시계 방향으로 갱신
            int nc = c + dx[nd];      // nc값 반시계 방향으로 갱신

            if (board[nr][nc] == 0) // 현재 (청소되지 않은)빈칸이라면
            {
                find = true; // 현재칸 청소함을 표시
                r = nr;      // r값 갱신
                c = nc;      // c값 갱신
                d = nd;      // d값도 갱신
                break;       // for문 빠져나가기
            }
        }

        if (find) // 청소된 현재칸의 주변 4칸을 확인할 수 있도록
        {
            continue; // while(true)문으로 되돌아감
        }

        // 현재칸 주변4칸이 모두 청소되지않은 빈칸이 없다면
        int bd = (d + 2) % 4; // 북 -> 남  한칸 후진을 위해서 인덱스 변경
        int br = r + dy[bd];  // br값 후진으로 갱신
        int bc = c + dx[bd];  // bc값 후진으로 갱신

        if (board[br][bc] == 1) // 뒤쪽 칸이 벽이라면
        {
            return cnt; // 그대로 종료
        }

        r = br; // 한 칸 뒤로 후진
        c = bc; // r과 c를 변화시켜줌으로서 while(true) 1번으로 돌아감
    }
    return cnt; // cnt 반환
}

int main()
{
    int n, m, r, c, d;
    vector<vector<int>> board;

    cin >> n >> m;
    cin >> r >> c >> d;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << clean(n, m, r, c, d, board);
}