#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

//뱀 게임이 종료되는 시간 계산
int game(int n, vector<vector<int>> &state, map<int, int> &direction) {
    // 뱀이 움직일 방향 저장해둔
    int dx[4] = {0, 1, 0, -1}; // 동(→), 남(↓), 서(←), 북(↑)
    int dy[4] = {1, 0, -1, 0};
    int time = 0; // 게임 시간
    int dir = 0;  // 뱀의 방향
    int x, y, nx, ny;

    // 뱀이 존재하는 위치들 저장 
    deque<ci> snake;  
    // 시작 좌표 deque에 추가
    snake.push_back({1, 1}); 
    // (1, 1)에 뱀이 있음을 표시
    state[1][1] = 2;  

    while (true) {
        x = snake.front().first;  // 뱀의 머리 좌표
        y = snake.front().second; // 뱀의 머리 다음 좌표
        if (direction[time] != 0) { // 뱀의 방향을 변환하면
            dir = (dir + direction[time]) % 4; // 뱀의 방향 갱신
        }
        time++; // 게임 시간 1초 추가
        // 뱀 머리의 다음 좌표 설정
        nx = x + dx[dir]; 
        ny = y + dy[dir];

        // 뱀의 머리가 벽에 부딪히거나 자기 자신의 몸과 부딪히면 게임 종료
        if (!(0 < nx && nx <= n) || !(0 < ny && ny <= n) || state[nx][ny] == 2) {
            break;
        }

        snake.push_front({nx, ny}); // 뱀의 머리 좌표 deque에 추가
        if (state[nx][ny] != 1) {   // 새로 이동한 좌표에 사과가 없으면 꼬리 위치 pop
            state[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        state[nx][ny] = 2;
    }
    return time;
}

int main() {
    int n, k, l, x;
    char c;
    //사과의 위치 저장
    vector<vector<int>> state;
    //뱀의 머리 방향 전환 여부 저장
    map<int, int> direction;
    
    // 입력
    cin >> n >> k;
    state.assign(n + 1, vector<int>(n + 1, 0));
    while (k--) {
        int a, b;
        cin >> a >> b;
        state[a][b] = 1; //사과 위치 표시
    }

    cin >> l;
    while (l--) {
        cin >> x >> c;
        if (c == 'D') {
            direction[x] = 1; // 오른쪽으로 회전
        } else {
            direction[x] = 3; // 왼쪽으로 회전
        }
    }

    // 연산
    int time = game(n, state, direction);

    // 출력
    cout << time;
    return 0;
}