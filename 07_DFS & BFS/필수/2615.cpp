#include <iostream>

using namespace std;
const int MAX = 20;
int board[MAX][MAX];
//동 남 북동 남동
int dr[4] = {0, 1, -1, 1};
int dc[4] = {1, 0, 1, 1};

int dfs(int r, int c, int dir, int color){
    //오목알 개수
    int count = 1;
    //다음에 탐색할 좌표
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    //탐색한 좌표의 바둑알 색이 현재와 같다면 개수 +1
    if(nr >= 1 && nr < MAX && nc >= 1 && nc < MAX && board[nr][nc] == color) {
        count += dfs(nr, nc, dir, color);
    }
    return count;
}

bool isCheck(int r, int c, int dir, int color)
{
    int br = r - dr[dir];
    int bc = c - dc[dir];
    //탐색한 좌표의 바둑알 색이 현재와 같다면 이미 탐색한 것
    if(br >= 1 && br < MAX && bc >= 1 && bc < MAX && board[br][bc] == color) {
        return true;
    }
    return false;
}

void solution(int &win, int &r, int& c){
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            //오목알이 놓여져 있지 않으면 패스
            if(board[i][j] == 0){
                continue;
            }
            //m = 0 : 동, m=1 남 m= 2 북동 m=3 남동 방향 체크
            for(int m = 0; m < 4; m++){
                //이전에 탐색한 거라면 패스
                if(isCheck(i, j, m, board[i][j])){
                    continue;
                }
                //이긴 경우
                if(dfs(i, j, m, board[i][j]) == 5){
                    win = board[i][j];
                    r = i;
                    c = j;
                    return;
                }
            }

        }
    }
}

int main() {
    int win, r, c;
    //입력
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            cin >> board[i][j];
        }
    }
    //계산
    solution(win, r, c);
    //출력
    cout << win << '\n';
    if(win > 0){
        cout << r << " " << c;
    }
}