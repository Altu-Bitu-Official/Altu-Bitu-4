/* 질문있습니다!
depth가 2인 경우는 우모양이기 때문에 현재 위치에서 다시탐색된다고 이해했습니다.
그런데 테트로미노는 총 5가지의 경우에서 우모양 1개와  depth가 4인 나머지 4개의 모양이 존재하는데
depth가 4인 나머지 모양일 경우, dfs함수를 돌리다보면 depth가 2인경우가 나타날텐데 그러면
if (depth == 2) {
            dfs(x, y, depth + 1, sum + temp);
    }
조건식에 걸릴거라고 생각되는데 나머지 모양에 해당하는 경우, 이 조건식을 만족시켜도 크게 상관은 없는 걸까요?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board; // 2차원 벡터 보드
int ans;                   // 정답값
void dfs(int r, int c, int depth, int sum)
{
    vector<int> dr = {-1, 0, 0, 1}; // 좌 상 하 우의 row 인덱스
    vector<int> dc = {0, 1, -1, 0}; // 좌 상 하 우의 col 인덱스

    if (depth == 4)
    {
        ans = max(ans, sum); // sum의 최대값을 ans에 넣으면서 갱신시키기
        return;              // 종료
    }

    for (int i = 0; i < 4; i++) // 상하좌우 4가지 방향을 탐색하기
    {
        int nr = r + dr[i]; // row값 갱신
        int nc = c + dc[i]; // col값 갱신

        if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size() || !board[nr][nc]) // nr과 nc값이 0보다 작거나 각각 행/렬 길이의 size이상일 경우 혹은 이미 방문한 칸이라면
        {
            continue; // 다음걸로 넘어가기
        }

        int temp = board[nr][nc]; // 방문처리하기전 temp에 해당 칸의 가치 저장
        board[nr][nc] = 0;        // 방문처리하기 : 0으로

        if (depth == 2) // depth가 2인 우 모양
        {
            dfs(r, c, depth + 1, sum + temp); // 현재위치에서 다시탐색
        }

        dfs(nr, nc, depth + 1, sum + temp); // dfs 재귀호출 sum+temp를 해서 블록의 최댓값을 구해주기
        board[nr][nc] = temp;               // 원래대로
    }
}
int main()
{
    int n, m;
    cin >> n >> m;                      // 행 열 값들 입력하기
    board.assign(n, vector<int>(m, 0)); // n행 m열 보드 초기화하기

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j]; // 칸의 가치 입력하기
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = board[i][j]; // temp에 칸의 가치를 넣기
            board[i][j] = 0;        // 선택된 칸은 가치를 0으로 만들기
            dfs(i, j, 1, temp);     // dfs함수 호출하기
            board[i][j] = temp;     // 다음을 위해 칸의 가치를 원래대로 넣어두기
        }
    }

    cout << ans; // 출력하기
    return 0;
}