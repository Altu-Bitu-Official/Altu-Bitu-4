#include <iostream>

using namespace std;

const int SIZE = 50;    //최대 방 크기
const int CLEAN = 2;    //청소한 경우를 2로 나타내 표시
int n, m, cnt = 0; // 세로 크기, 가로 크기, 청소한 칸 개수

int board[SIZE][SIZE]; // (0: 빈 칸, 1: 벽, 2: 청소 완료)
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; // 북 동 남 서

void dfs(int row, int col, int dir) {
    // 1. 현재 위치 청소
    if(board[row][col] != CLEAN) {  //현재 구역이 청소되지 않았다면
        cnt++;  //청소하는 칸의 개수 +1
    }
    board[row][col] = CLEAN;    //해당 칸 청소 처리

    // [현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는가]
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for(int i = 0; i < 4; i++) { // 3-1. 반시계 방향으로 90º 회전
        int new_dir = (dir-i+3) % 4;    //탐색할 방향
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir];   //탐색할 행, 열

        if(board[new_row][new_col] == 0) { // 3-2. 아직 청소되지 않은 빈 칸 발견
            dfs(new_row, new_col, new_dir); // 한 칸 전진
            return;     //반환
        }
    }

    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    int back_dir = (dir+2) % 4;     //후진할 방향
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir];       //후진할 행,열

    // [바라보는 방향을 유지한 채로 한 칸 후진할 수 있는가]
    if(board[back_row][back_col] == 1) { // 2-2. 뒤쪽 칸이 벽이라 후진할 수 없는 경우
        return; //반환
    }
    // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진
    dfs(back_row, back_col, dir); // 방향 유지한 상태로 후진 (2-3)
    return; //반환
}

int main() {
    int r, c, d; // 로봇 청소기 정보

    cin >> n >> m;  //방 크기 입력받기
    cin >> r >> c >> d; //로봇 청소기 정보 입력 받기

    for(int i = 0; i < n; i++) {    //가로
        for(int j = 0; j < m; j++) {    //세로
            cin >> board[i][j]; //장소의 상태 입력
        }
    }

    dfs(r, c, d);   //dfs 연산
    cout << cnt;    //출력
    return 0;
}