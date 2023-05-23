#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 뱀의 이동 방향
const int dx[] = {0, 1, 0, -1};  // 동, 남, 서, 북
const int dy[] = {1, 0, -1, 0};

int main() {
    int n;
    cin >> n;

    // 게임판 초기화
    vector<vector<int>> board(n, vector<int>(n, 0));

    int k;
    cin >> k;

    // 사과 위치 설정
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 1;  // 사과는 1로 표시
    }

    int l;
    cin >> l;

    // 방향 변환 정보 저장
    queue<pair<int, char>> directions;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        directions.push({x, c});
    }

    int dir = 0;  // 뱀의 초기 이동 방향 (동쪽)
    int time = 0; // 현재 시간
    int x = 0, y = 0;  // 뱀의 머리 위치

    // 뱀의 이동 경로를 저장하는 큐
    queue<pair<int, int>> snake;
    snake.push({x, y});
    board[x][y] = 2;  // 뱀은 2로 표시

    while (true) {
        // 시간이 경과하면 방향 변환
        if (!directions.empty() && directions.front().first == time) {
            char turn = directions.front().second;
            directions.pop();

            if (turn == 'L') {
                dir = (dir + 3) % 4;  // 왼쪽으로 90도 회전
            } else if (turn == 'D') {
                dir = (dir + 1) % 4;  // 오른쪽으로 90도 회전
            }
        }

        // 다음 칸으로 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 게임 종료 조건 검사
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {
            cout << time + 1 << '\n';  // 1부터 시작하므로 +1
            break;
        }

        // 이동한 칸에 사과가 없으면 꼬리 제거
        if (board[nx][ny] == 0) {
            int tailX = snake.front().first;
            int tailY = snake.front().second;
            snake.pop();
            board[tailX][tailY] = 0;
        }

        // 뱀 이동
        snake.push({nx, ny});
        board[nx][ny] = 2;

        // 다음 위치로 머리 갱신
        x = nx;
        y = ny;

        // 시간 증가
        time++;
    }

    return 0;
}
