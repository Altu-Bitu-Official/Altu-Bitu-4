#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board; // 종이에 쓰인 수를 저장하는 vector 선언
int ans;                   // 구하는 값을 전역변수로 선언

void dfs(int x, int y, int depth, int sum)
{ // ㅗ모양 빼고 나머지 도형들은 한 점에서 depth 4인 깊이 우선 탐색으로 구할 수 있음

    vector<int> dx = {-1, 0, 1, 0}; // 상하좌우를
    vector<int> dy = {0, 1, 0, -1}; // 표현하는 벡터

    if (depth == 4)
    {                        // Depth가 4인 경우 -> ans 갱신
        ans = max(ans, sum); // max값으로 갱신!
        return;
    }

    // 하나 더 선택
    // 현재 위치를 기준으로 유효한 한칸을 선택
    for (int i = 0; i < 4; i++)
    {
        // 선택할 칸
        int nx = x + dx[i]; // i에 따른 선택할 y
        int ny = y + dy[i]; // i에 따른 선택할 y

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny])
        {             // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
            continue; // 유효하지 않은 경우 다음i에 대해 진행
        }

        int temp = board[nx][ny]; // 해당 칸 저장
        board[nx][ny] = 0;        // 방문 처리해주기 -> 중복 제외할려고
                                  // 다음 탐색 -> 예외처리 필요
        if (depth == 2)
        { // ㅜ 모양일 경우 -> 현재 위치에서 다시 탐색
            dfs(x, y, depth + 1, sum + temp);
        }
        dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

        board[nx][ny] = temp; // 재방문할 수 있으므로 원래대로 돌려줌
    }
}

int main()
{

    // 입력
    int n, m;
    cin >> n >> m;                      // 세로크기 n, 가로크기 m
    board.assign(n, vector<int>(m, 0)); // n행 m열이 0으로 채워진 벡터 생성

    // 입력
    for (int i = 0; i < n; i++) // i번의 행 반복
    {
        for (int j = 0; j < m; j++) // j번의 열 반복
        {
            cin >> board[i][j]; // 사용자정의
        }
    }

    // 연산
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 여기서 한칸을 선택
            // 방문표시 -> 선택한 칸의 가중치를 0으로 바꾸고 다음 depth
            int temp = board[i][j]; // i행, j열의 수를 임시변수 temp에 저장
            board[i][j] = 0;        // 방문표시
            dfs(i, j, 1, temp);     // 탐색하여 가장 큰수 -> ans 저장
            board[i][j] = temp;     // 원래의 값을 다시 저장
        }
    }

    // 출력
    cout << ans;
    return 0;
}