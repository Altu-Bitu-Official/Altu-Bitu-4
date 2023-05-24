#include <iostream>

using namespace std;

const int SIZE = 50;//방의 최대 크기
const int CLEAN = 2;//청소할 때 청소칸에 저장할 상수 선언
int n, m, cnt = 0; // 세로 크기, 가로 크기, 청소한 칸 개수

int board[SIZE][SIZE]; // (0: 빈 칸, 1: 벽, 2: 청소 완료)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

void dfs(int row, int col, int dir) {//청소 함수
    // 1. 현재 위치 청소
    if(board[row][col] != CLEAN) {//청소되지 않은 칸은
        cnt++;//청소되지 않은 경우 카운트
    }
    board[row][col] = CLEAN;//청소하기

    // [현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가]
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for(int i = 0; i < 4; i++) { // 3-1. 반시계 방향으로 90º 회전
        int new_dir = (dir-i+3) % 4;//새로운 방향 설정
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir];//새로운 좌표 설정

        if(board[new_row][new_col] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
            dfs(new_row, new_col, new_dir); // 한 칸 전진
            return;
        }
    }

    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    int back_dir = (dir+2) % 4;//뒤쪽 방향 설정
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir];//뒤쪽 칸 값 갱신

    // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
    // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
    if(board[back_row][back_col] == 1) {//위쪽 칸이 벽인 경우
        return;
    }
    // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
    dfs(back_row, back_col, dir); // 방향 유지한 상태로 후진 (2-3)
    return;
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

int main() {
    int r, c, d; // 로봇 청소기 정보

    // 입력
    cin >> n >> m;//방의 크기 입력
    cin >> r >> c >> d;//로봇 청소기가 있는 칸의 좌표와 로봇 청소기가 바라보는 방향 입력

    for(int i = 0; i < n; i++) {//각 장소의 상태 입력
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];//board 배열에 각 장소의 상태 입력
        }
    }

    // 연산 & 출력
    dfs(r, c, d);//정답 함수 호출
    cout << cnt;//정답 출력
    return 0;
}