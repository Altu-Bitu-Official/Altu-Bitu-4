#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

/**뱀 게임이 종료되는 시간 계산*/
int game(int n, vector<vector<int>>& state, map<int, int>& direction) {
    int dx[4] = { 0, 1, 0, -1 }; // 동(→), 남(↓), 서(←), 북(↑)
    int dy[4] = { 1, 0, -1, 0 };
    int time = 0; // 게임 시간
    int dir = 0;  // 뱀의 방향
    int x, y, nx, ny;

    deque<ci> snake;    // 뱀의 위치
    snake.push_back({ 1, 1 });  // 뱀의 시작 좌표 추가
    state[1][1] = 2;    // (1, 1)에 뱀이 있음을 표시

    while (true) {//뱀의 머리가 벽에 부딪치거나 몸과 부딪치는 경우를 break로 설정하고 무한 반복
        x = snake.front().first;  // 뱀의 머리 좌표
        y = snake.front().second;
        if (direction[time] != 0) { // 뱀의 방향 변환 정보가 있으면
            dir = (dir + direction[time]) % 4; // 뱀의 방향 갱신
        }
        time++; // 게임 시간 1초 추가
        nx = x + dx[dir]; // 뱀 머리의 다음 좌표
        ny = y + dy[dir];

        // 뱀의 머리가 벽에 부딪히거나 자기 자신의 몸과 부딪히면 게임 종료
        if (!(0 < nx && nx <= n) || !(0 < ny && ny <= n) || state[nx][ny] == 2) {
            break; //앞의 두조건은 벽에 부딪쳤을 때, 맨 뒤의 조건은 특정 칸=2->뱀은 한마리이므로 자기자신의 몸이 중복됨을 의미
        }

        snake.push_front({ nx, ny }); // 뱀의 머리 좌표 추가
        if (state[nx][ny] != 1) {   // 새로 이동한 좌표에 사과가 없으면 꼬리 위치 비워주기
            state[snake.back().first][snake.back().second] = 0;//사과도 뱀도 없음
            snake.pop_back();//뱀의 좌표에서 빼줌
        }
        state[nx][ny] = 2;//새로 이동한 좌표 표시
    }
    return time;//시간 반환
}
/**[백준 3190: 뱀]
 * 뱀의 머리와 꼬리 좌표에 대한 접근 필요 -> deque 사용!
 * state에 사과가 존재하면 해당 위치를 1, 뱀이 존재하면 2, 아무것도 없으면 0으로 설정
 * 1. 뱀의 첫 시작 좌표인 {1, 1}을 s에 추가
 * 2. 현재 뱀의 머리가 있는 좌표를 {x, y}로 받기
 * 3. 뱀의 방향이 바뀌면 방향을 업데이트하고, 새로운 뱀의 머리 좌표를 {nx, ny}로 설정
 * 4. 게임 시간 업데이트(time++)
 * 4. 뱀의 머리가 벽이나 몸에 부딪히면 while문 종료
 * 5-1. 새로 이동한 좌표를 s 앞부분에 추가
 * 5-2. 새로 이동한 좌표에 사과가 없으면 기존 꼬리 좌표 값을 0으로 바꾸고 s에서 pop
 *   -> 사과가 있으면 몸길이가 1 늘어나지만 사과가 없으면 몸길이가 변하지 않으므로
 * 6. 새로 이동한 좌표를 2로 표시
*/
int main() {
    int n, k, l, x;
    char c;
    vector<vector<int>> state;//좌표
    map<int, int> direction;//뱀이 움직은 방향

    // 입력
    cin >> n >> k;
    state.assign(n + 1, vector<int>(n + 1, 0));
    while (k--) {//사과:k개
        int a, b;
        cin >> a >> b;
        state[a][b] = 1; //사과 위치 표시
    }

    cin >> l;//방향변환 횟수
    while (l--) {
        cin >> x >> c;
        if (c == 'D') {
            direction[x] = 1; // 오른쪽으로 회전
        }
        else {
            direction[x] = 3; // 왼쪽으로 회전
        }
    }

    // 연산
    int time = game(n, state, direction);

    // 출력
    cout << time;
    return 0;
}