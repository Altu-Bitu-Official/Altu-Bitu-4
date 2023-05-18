#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;

int ans;

void dfs(int x, int y, int depth, int sum) {

    vector<int> dx = { -1,0,1,0 }; //좌상우하, x축 방향으로의 움직임
    vector<int> dy = { 0,1,0,-1 }; // y축 방향으로의 움직임

    if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
        ans = max(ans, sum);
        return;
    }

    // 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
    //if (ans >= MAX * (4 - cnt) + sum) {
    //	return;
    //}

    for (int i = 0; i < 4; i++) {
        // 선택할 칸
        int nx = x + dx[i]; //i가 0 이라면 x=x-1 y=y, i가 2 라면 x=x+1 y=y,
        int ny = y + dy[i]; //i가 1이라면 x=x y=y+1, i가 4 라면 x=x y=y-1

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
            continue;
        }

        int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
        board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

        // 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
        if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
            dfs(x, y, depth + 1, sum + temp);
        }
        dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

        board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

    }
}

/*
* HINT : 하나의 도형은 무언가 특별한 것 같아요! or 테트로미노의 모양은 탐색의 관점에서 특징이 있는 것 같아요!
* 1. ㅜ 모양을 제외한 테트로미노의 모양은 깊이가 4인 dfs의 탐색 모양
*     -> dfs로 블록을 하나씩 선택해가면서 개수(cnt)와 합(sum)을 계산
*     -> 4개 선택하면 최댓값 갱신
* 2. 예외 : ㅜ 모양은 블록을 2개 선택했을 때 현재 블록에서 다시 블록을 선택해준다.
*/


int main() {

    // 입력
    int n, m; //세로 n, 가로 m
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0)); //테트로미노를 놓을 종이


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; //각 칸에 쓰여진 수 입력받기
        }
    }

    // 연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = board[i][j];
            board[i][j] = 0; //i,j 번째칸 방문했으므로 0 처리
            dfs(i, j, 1, temp);
            board[i][j] = temp; //다시 방문할 수 있으므로 원래대로 되돌려놓음
        }
    }

    // 출력
    cout << ans;
    return 0;
}