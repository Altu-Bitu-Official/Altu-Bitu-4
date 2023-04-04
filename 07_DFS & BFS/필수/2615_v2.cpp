#include <iostream>

using namespace std;

const int SIZE = 19;

int winner = 0, row, col;
int board[SIZE+1][SIZE+1]; // 오목판
/*
 * 방향은 우향, 하향, 우상향, 우하향만 고려한다.
 * 왼쪽에서 오른쪽으로, 위에서 아래로 탐색하기 때문에 나머지 방향들은 사전에 발견할 수 있기 때문이다.
*/
int dr[4] = {0, 1, -1, 1}, dc[4] = {1, 0, 1, 1};

bool isFirstTravel(int r, int c, int dir, int color) { // 이전에 탐색된 방향인가 (반대방향에 해당 색상의 돌이 있었는가)
    int br = r - dr[dir];
    int bc = c - dc[dir];
    if(br >= 1 && br <= SIZE && bc >= 1 && bc <= SIZE && board[br][bc] == color) {
        return false;
    }
    return true;
}

int dfs(int r, int c, int dir, int color) {
    int cnt = 1;
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    if(nr >= 1 && nr <= SIZE && nc >= 1 && nc <= SIZE && board[nr][nc] == color) {
        cnt += dfs(nr, nc, dir, color);
    }
    return cnt;
}

void game() {
    for(int j = 1; j <= SIZE; j++) {
        for(int i = 1; i <= SIZE; i++) {
            if(board[i][j] == 0) { // 빈칸 PASS
                continue;
            }
            for(int k = 0; k < 4; k++) { // 방향별 탐색 시작
                if(!isFirstTravel(i, j, k, board[i][j])) { // 이전에 탐색한 경우 PASS
                    continue;
                }
                if(dfs(i, j, k, board[i][j]) == 5) { // 이기는 경우 발견
                    winner = board[i][j];
                    row = i;
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

    game();
    cout << winner << '\n';
    if(winner) {
        cout << row << ' ' << col;
    }
    return 0;
}