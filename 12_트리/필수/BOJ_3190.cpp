#include <iostream>
#include <queue>

using namespace std;

int board[101][101];//사과의 위치는 모두 다르며 1행1열에는 사과가 없다.
char chg[10001];//시작 시간으로부터 몇 초가 지난 후에 어느 방향으로 방향을 틀지 저장하는 배열
int exist[101][101];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };


int main() {

    int n, k;//보드의 크가와 사과의 개수

    cin >> n >> k;

    int a, b;
    while(k--) {
        cin >> a >> b;
        board[a][b] = 1;//사과가 위치한 곳에 1 표시
    }

    int l;//뱀의 방향 변환 횟수
    cin >> l;

    int x;//게임 시작시간으로부터 x초가 끝난 뒤에
    char c;//c가 L이면 왼쪽 D이면 오른쪽으로 90도 방향을 회전시킨다.
    while(l--) {
        cin >> x >> c;
        chg[x] = c;
    }

    queue<pair<int, int>> where;//현재 뱀이 어디에 있는지 저장
    where.push({ 1,1 });//뱀은 맨 처음에 1,1에 위치
    exist[1][1] = 1;
    int t = 0;//시간
    int dir = 0;//0,1,2,3 중 하나의 값을 가짐

    while (true) {
        t++;
        int new_col = where.back().first + dy[dir];
        int new_row = where.back().second + dx[dir];

        if (new_row<1 || new_row>n || new_col<1 || new_col>n) {
            break;
        }
        where.push({ new_col, new_row });

        if (chg[t] == 'D') {//방향이 D이면
            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }
        else if (chg[t] == 'L') {
            dir--;
            if (dir == -1) {
                dir = 3;
            }
        }

        if (board[new_col][new_row] == 1) {
            board[new_col][new_row] = 0;
        }
        else {
            if (exist[new_col][new_row] == 1) {
                break;
            }
            else {
                exist[where.front().first][where.front().second] = 0;
                where.pop();
            }
        }

        if (exist[new_col][new_row] == 1) {
            break;
        }
        else {
            exist[new_col][new_row] = true;
        }

    }
    cout << t;

    return 0;
}