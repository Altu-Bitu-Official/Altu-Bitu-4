#include <iostream>

using namespace std;

const int SIZE = 19;       // 오목판의 크기

int winner = 0, row, col;  // 승리자, 행, 열 인덱스
int board[SIZE+1][SIZE+1]; // 오목판
/*
 * 방향은 우향, 하향, 우상향, 우하향만 고려한다.
 * 왼쪽에서 오른쪽으로, 위에서 아래로 탐색하기 때문에 나머지 방향들은 사전에 발견할 수 있기 때문이다.
*/
int dr[4] = {0, 1, -1, 1}, dc[4] = {1, 0, 1, 1}; // 상하좌우, dr: 행 방향, dc: 열 방향

bool isFirstTravel(int r, int c, int dir, int color) { // 이전에 탐색된 방향인가 (반대방향에 해당 색상의 돌이 있었는가)
    int br = r - dr[dir]; // 반대방향 행 인덱스
    int bc = c - dc[dir]; // 반대방향 열 인덱스
    if(br >= 1 && br <= SIZE && bc >= 1 && bc <= SIZE && board[br][bc] == color) { // 위치가 범위 안에 있고 색상이 같으면
        return false; // 이전에 탐색하지 않았음
    }
    return true;      // 이전에 탐색했음
}

int dfs(int r, int c, int dir, int color) { // 재귀 dfs
    int cnt = 1; // 연결된 돌의 개수, 현재 위치를 포함하므로 1로 초기화
    int nr = r + dr[dir]; // 새로운 행 인덱스
    int nc = c + dc[dir]; // 새로운 열 인덱스
    if(nr >= 1 && nr <= SIZE && nc >= 1 && nc <= SIZE && board[nr][nc] == color) { // 위치가 범위 안에 있고 색상이 같으면
        cnt += dfs(nr, nc, dir, color); // 연결된 돌을 모두 더함
    }
    return cnt; // 돌의 개수 반환
}

void game() { // 게임 진행
    for(int j = 1; j <= SIZE; j++) {     // 1번~19번까지 반복
        for(int i = 1; i <= SIZE; i++) { // 1번~19번까지 반복
            if(board[i][j] == 0) { // 빈칸 PASS (돌이 올려져 있지 않음)
                continue;
            }
            for(int k = 0; k < 4; k++) { // 방향별 탐색 시작 (상하좌우)
                if(!isFirstTravel(i, j, k, board[i][j])) { // 이전에 탐색한 경우 PASS
                    continue;
                }
                if(dfs(i, j, k, board[i][j]) == 5) { // 이기는 경우 발견
                    winner = board[i][j]; // 현재 위치에 있는 숫자가 승리
                    row = i; // 가장 왼쪽 위 행 인덱스
                    col = j; // 가장 왼쪽 위 열 인덱스
                    return; // 승리했으므로 게임 종료
                }
            }
        }
    }
}

int main() {
    // 입력
    for(int i = 1; i <= SIZE; i++) {     // 1번~19번까지 반복
        for(int j = 1; j <= SIZE; j++) { // 1번~19번까지 반복
            cin >> board[i][j]; // 전역변수 오목판의 입력 받기
        }
    }

    game(); // 실행, 전역변수이므로 리턴값으로 넘겨주지 않아도 됨
    cout << winner << '\n'; // 승리 출력 (1: 흑, 2: 백, 0: 승부 결정 X)
    if(winner) { // 승부가 결정되었으면
        cout << row << ' ' << col; // 왼쪽 위의 행과 열 인덱스 출력
    }
    return 0;
}