#include <iostream>
using namespace std;

const int SIZE = 19; // 상수 선언 - 오목판의 크기

int winner = 0, row, col;      // 승리자 초기화, 행idx, 열idx
int board[SIZE + 1][SIZE + 1]; // 오목판
/*
[오목]
 방향은 우향, 하향, 우상향, 우하향만 고려한다.
 왼쪽에서 오른쪽으로, 위에서 아래로 탐색
 => 나머지 방향들은 사전에 발견 가능!
 */
int dr[4] = {0, 1, -1, 1}, dc[4] = {1, 0, 1, 1}; // dr과 dc의 조합으로 상하좌우 표현함

bool isFirstTravel(int r, int c, int dir, int color){
    // 이전에 탐색된 방향인지 판단하는 함수 
    // => 반대방향에 해당 색상의 돌이 있었는지 확인해야 함
    int br = r - dr[dir]; // 반대방향 행
    int bc = c - dc[dir]; // 반대방향 열

    if (br >= 1 && br <= SIZE && bc >= 1 && bc <= SIZE && board[br][bc] == color){
        // 바둑이 조건범위내에 존재, 색상이 동일한 경우
        return false; // 탐색한 적 없음 => false
    }
    return true; // 조건을 만족하지 않는 경우 탐색
}

int dfs(int r, int c, int dir, int color) // dfs방식으로 탐색하는 함수{
    int cnt = 1; // cnt를 현위치 1로 초기화함
    int nr = r + dr[dir]; // 새로운 행
    int nc = c + dc[dir]; // 새로운 열
    if (nr >= 1 && nr <= SIZE && nc >= 1 && nc <= SIZE && board[nr][nc] == color){
        // 바둑이 조건범위내에 존재, 색상이 같은 경우
        cnt += dfs(nr, nc, dir, color); // 연결된 돌을 더해서 저장
    }
    return cnt; // 돌의 개수 return
}

void game(){
    for (int j = 1; j <= SIZE; j++){
        for (int i = 1; i <= SIZE; i++){
            if (board[i][j] == 0){ // 빈칸인 경우 PASS
                continue;
            }
            for (int k = 0; k < 4; k++){ // 방향별 탐색을 시작
                if (!isFirstTravel(i, j, k, board[i][j])){ // 이전에 탐색한 경우 PASS
                    continue;
                }
                if (dfs(i, j, k, board[i][j]) == 5){                         
                    // 이기는 경우를 발견함
                    winner = board[i][j]; // 현재 위치의 숫자가 승리
                    row = i; // 행 저장
                    col = j; // 열 저장
                    return; // 종료
                }
            }
        }
    }
}

int main()
{
    // 입력
    // 행 19번 반복
    for (int i = 1; i <= SIZE; i++){
        // 열 19번 반복
        for (int j = 1; j <= SIZE; j++) {
            cin >> board[i][j]; // 오목판 사용자입력
        }
    }

    game(); // game을 실행
    cout << winner << '\n';
    if (winner){
        //승리한 경우
        cout << row << ' ' << col; // 저장한 행과 열의 인덱스 출력
    }
    return 0;
}