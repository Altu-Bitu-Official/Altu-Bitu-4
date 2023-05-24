#include <iostream>
#include <vector>

// 내 코드와 비교하며 배울 점 :
//  문제를 자연스러운 흐름으로 재구성함. 청소되지 않은 빈칸이 있는가? 있다면 바로 3번 시행.
//  가독성 좋은 변수명을 활용함. int isDirty -> bool find, cur_r -> row,
//  불필요한 변수 할당을 최소화함. row, col 등등.
//  if와 else문이 있을때, else문을 쓰지 않아도 된다면 쓰지 않는다.
//  중간 단계 (nr, nc, nd)를 둠으로써 while문이 도는 경우를 줄였다. 대신 메모리도 그만큼 조금 늘어난듯?

using namespace std;

const int CLEAN = 2; // 확실히 '깨끗하다' 처럼 긍정적인 의미일경우 -1 대신 2 같은 positive number를 쓰는게 나은 거 같다.

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

int clean(int n, int m, int r, int c, int d, vector<vector<int>> &board)
{
    int cnt = 0; // 청소한 칸 갯수 초기화

    while (true)
    {
        // 1. 현재 칸이 아직 청소되지 않은 경우,
        if (board[r][c] != CLEAN)
        {
            cnt++; // 청소한 칸을 센다.
        }
        board[r][c] = CLEAN; // 현재 칸을 청소한다. 이건 근데 위 if문 안에 넣어도 될 것 같은데.

        bool find = false;          // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가
        for (int i = 0; i < 4; i++) // 주변 4칸 탐색
        {
            int nd = (d - i + 3) % 4;             // 3-1. 반시계 방향으로 90도 회전 (임의로)
            int nr = r + dy[nd], nc = c + dx[nd]; // 3-2. 바라보는 방향을 기준으로 앞쪽 칸이

            if (board[nr][nc] == 0)
            {                // 3-2. 아직 청소되지 않은 첫 빈 칸임을
                find = true; // 발견하여
                r = nr;      // 전!
                c = nc;      // 진!
                d = nd;      // 완전히 회전한다.
                break;       // 나머지 방향들은 볼 필요 없이 떠난다.
            }
        }
        if (find)
        {             // 3-3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우 1번으로 돌아감
            continue; // 이 continue는 위의 for문 밖에서 써야 while문에 적용되기 때문에 굳이 find라는 flag 변수를 만들어줘야함.
        }

        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        int bd = (d + 2) % 4;                 // 북남, 동서는 2 차이씩 나기 때문에 backward direction은
        int br = r + dy[bd], bc = c + dx[bd]; // 이런식으로 임의로 정함.

        // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
        // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        if (board[br][bc] == 1)
        {
            return cnt; // 바로 끝낸다. break를 사용해도 좋다.
        }
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
        r = br; // 임의의 위치였던 것을
        c = bc; // 완전히 후진!
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
    int n, m, r, c, d;
    vector<vector<int>> board; // 청소할 room

    // 입력
    cin >> n >> m;
    cin >> r >> c >> d;
    board.assign(n, vector<int>(m, 0)); // 이때 n, m 대신 n, n 을 쓰게되면 invalid next 런타임 에러가 난다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) // m 인거 조심하자.
        {
            cin >> board[i][j]; // 초기화
        }
    }

    // 연산 & 출력
    cout << clean(n, m, r, c, d, board);
    return 0;
}