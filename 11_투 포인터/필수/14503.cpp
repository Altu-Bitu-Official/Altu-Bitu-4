#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, 0 }; // 북, 동, 남, 서
int dy[] = { 0, 1, 0, -1 };

int countCleanedArea(vector<vector<int>>& room, vector<vector<int>>& cleaned, int r, int c, int d) {
    int count = 0;

    while (true) {
        if (room[r][c] == 0 && cleaned[r][c] == 0) { // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
            cleaned[r][c] = 1;
            count++;
        }

        bool flag = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4; // 반시계 방향으로 회전
            int nx = r + dx[d];
            int ny = c + dy[d];

            if (room[nx][ny] == 0 && cleaned[nx][ny] == 0) {
                r = nx;
                c = ny;
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (room[r - dx[d]][c - dy[d]] == 1) break; // 후진이 불가능하면 작동 멈춤
            else {
                r -= dx[d];
                c -= dy[d];
            }
        }
    }

    return count;
}

int main() {
    int N, M, r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    vector<vector<int>> room(N, vector<int>(M)); // 방 구조
    vector<vector<int>> cleaned(N, vector<int>(M, 0)); // 치운 방 표시

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    cout << countCleanedArea(room, cleaned, r, c, d) << '\n';

    return 0;
}