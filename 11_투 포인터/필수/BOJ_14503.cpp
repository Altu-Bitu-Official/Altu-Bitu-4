#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

//로봇 청소기를 조건에 따라 이동시키고, 청소한 칸의 수를 세어 리턴하는 함수
int countCleanedCells (vector<vector<int>>& coor, pi current_cell, int dir) {
    int cnt = 0;    //청소한 칸 수
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool is_stop = false;   //멈추면 true.

    while (!is_stop) {
        if (coor[current_cell.first][current_cell.second] == 0) {   //현재 셀이 빈 칸일 때
            coor[current_cell.first][current_cell.second] = 2;
            cnt++;  //청소한 칸 수 증가
        }
        int ori_dir = dir;
        while (true){
            //먼저, 반시계 방향으로 회전.
            if (dir != 0) {
                dir--;
            } else {
                dir = 3;
            }
            int nx = current_cell.first + dx[dir], ny = current_cell.second + dy[dir];
            if (coor[nx][ny] ==0) {    //바라보는 방향 기준 앞 칸이 청소되지 않은 빈 칸일 때
                current_cell.first = nx; current_cell.second = ny;  //그 방향으로 전진
                break;  //반복 종료
            }
            if (dir == ori_dir) {   //한 바퀴를 다 돌았는데도 청소되지 않은 빈 칸이 없는 경우
                nx = current_cell.first - dx[dir], ny = current_cell.second - dy[dir];  //바라보는 방향 기준 뒷 칸 확인
                if (coor[nx][ny] == 1) {    //뒷칸이 벽일 때
                    is_stop = true;     //정지
                }
                else {
                    current_cell.first = nx; current_cell.second = ny;  //후진
                }   
                break;  //반복 종료
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    vector<vector<int>> coor;
    pi current_cell;
    int dir;

    //입력
    cin >> n >> m;
    coor.assign(n, vector<int> (m, 0));
    cin >> current_cell.first >> current_cell.second >> dir;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> coor[i][j];
        }
    }

    //출력
    cout << countCleanedCells(coor, current_cell, dir);
}