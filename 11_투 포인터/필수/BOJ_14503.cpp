#include <iostream>
#include <vector>

using namespace std;

const int CLEAN = 2; // 청소칸에 저장하는 상수 선언

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북  남 서 동

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board)
{
    int cnt = 0; // 청소한 칸 개수 초기화

    while (true)
    {
        // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
        if (board[r][c] != CLEAN)
        {
            cnt++; // 청소한 칸+1
        }
        board[r][c] = CLEAN; // 현재 칸 청소

        bool find = false;          // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가
        for (int i = 0; i < 4; i++) // 주변 4칸을 청소
        {
            int nd = (d - i + 3) % 4;             // 반시계 방향으로 90도 회전
            int nr = r + dy[nd], nc = c + dx[nd]; // 좌표 new row,column으로 초기화

            if (board[nr][nc] == 0)
            {                // 3-2. 아직 청소되지 않은 빈 칸 발견
                find = true; // 발견
                r = nr;      // r초기화
                c = nc;      // c초기화
                d = nd;      // 방향 초기화
                break;
            }
        }
        if (find)
        { // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue;
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int bd = (d + 2) % 4;
        int br = r + dy[bd], bc = c + dx[bd];

        // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if (board[br][bc] == 1)
        {
            return cnt; // 종료
        }
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; // 방항은 유지하는 상태로
        c = bc; // r,c를 후진
    }
    return cnt;
}

/*
 * [로봇 청소기 작동]
 * 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
 *  2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
 *  2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
 *  3-1. 반시계 방향으로 90º 회전한다.
 *  3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
 *  3-3. 1번으로 돌아간다.
 */

int main()
{
    int n, m, r, c, d;         // 가로,세로 x좌표, y 좌표, qkdgid
    vector<vector<int>> board; // 방의 상태를 나타내는 이중벡터 선언

    // 입력
    cin >> n >> m;                      // 방의 가로n, 세로m 사용자 정의
    cin >> r >> c >> d;                 // 좌표 (r,c), 방향d 사용자 정의
    board.assign(n, vector<int>(m, 0)); // 청소되지 않는 경우(0)로 설정
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j]; // 사용자정의 0(청소x), 1(벽), 2(청소완)
        }
    }

    // 연산 & 출력
    cout << clean(n, m, r, c, d, board);
    return 0;
}