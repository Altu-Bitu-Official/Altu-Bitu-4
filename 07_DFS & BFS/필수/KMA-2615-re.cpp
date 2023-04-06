#include <iostream>

using namespace std;

const int SIZE = 19;    // 오목판 가로세로 선 개수

int winner = 0, row, col;   // 승자(아직 승자가 없는 경우 그대로 0)와 오목의 위치 저장할 변수
int board[SIZE+1][SIZE+1]; // 오목판
/*
 * 방향은 우향, 하향, 우상향, 우하향만 고려한다.
 * 왼쪽에서 오른쪽으로, 위에서 아래로 탐색하기 때문에 나머지 방향들은 사전에 발견할 수 있기 때문이다.
*/
int dr[4] = {0, 1, -1, 1}, dc[4] = {1, 0, 1, 1};

bool isFirstTravel(int r, int c, int dir, int color) { // 이전에 탐색된 방향인가 (반대방향에 해당 색상의 돌이 있었는가)
    // 반대방향으로 탐색 방향 설정
    int br = r - dr[dir];
    int bc = c - dc[dir];
    // br과 bc의 범위가 오목판 안이고, 반대방향에 해당 색상의 돌이 있다면
    // 전에 이미 탐색했던 방향임
    if(br >= 1 && br <= SIZE && bc >= 1 && bc <= SIZE && board[br][bc] == color) {
        return false;
    }
    return true;
}

int dfs(int r, int c, int dir, int color) { //해당 돌부터 같은 색일 때까지 탐색해서 탐색한 개수(연속된 같은 색의 돌 개수) 반환함
    int cnt = 1;    // 연속된 돌 개수 1에서 시작
    int nr = r + dr[dir];   // 탐색할 방향들
    int nc = c + dc[dir];
    // nr과 nc가 범위 안이고, 해당 방향에 같은 색 돌 있으면
    // 재귀 호출을 통해 계속 탐색 (cnt 개수 증가시키며)
    if(nr >= 1 && nr <= SIZE && nc >= 1 && nc <= SIZE && board[nr][nc] == color) {
        cnt += dfs(nr, nc, dir, color);
    }
    return cnt;
}

void game() {   //오목판 탐색해서 승자와 오목의 위치를 찾는다
    for(int j = 1; j <= SIZE; j++) {
        for(int i = 1; i <= SIZE; i++) {
            if(board[i][j] == 0) { // 빈칸이면 PASS
                continue;
            }
            // 빈칸이 아니면, 즉 돌이 있으면
            for(int k = 0; k < 4; k++) { // 방향별 탐색 시작
                if(!isFirstTravel(i, j, k, board[i][j])) { // 이전에 탐색한 경우 PASS
                    continue;
                }
                if(dfs(i, j, k, board[i][j]) == 5) { // 이기는 경우(돌이 다섯개 연속으로 있어서 dfs로 다섯번 탐색한 경우) 발견
                    winner = board[i][j];   // 그 돌의 숫자가 승자
                    row = i;    // 오목의 가장 상단 위치
                    col = j;
                    return;
                }
            }
        }
    }
}

int main() {
    // 입력
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            cin >> board[i][j];
        }
    }

    // 오목판을 탐색하고
    // 게임의 승자 혹은 아직 승부가 나지 않았다면 0을 출력하고
    // 승자가 있다면
    // 승자 오목의 가장 왼쪽 위의 위치를 출력한다
    game();
    cout << winner << '\n';
    if(winner) {
        cout << row << ' ' << col;
    }
    return 0;
}