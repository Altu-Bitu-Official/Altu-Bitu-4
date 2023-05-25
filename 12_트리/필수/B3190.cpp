#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터 객체를 사용하기 위한 헤더
#include <deque> // 자료구조 덱을 사용하기 위한 라이브러리
#include <map> // map을 사용하기 위한 라이브러리

using namespace std;
typedef pair<int, int> ci; // 위치 좌표를 저장하기 위해 pair 선언

// 뱀 게임이 종료되는 시간 계산하는 함수
int game(int n, vector<vector<int>>& state, map<int, int>& direction) {
    int dx[4] = { 0, 1, 0, -1 }; // 동(→), 남(↓), 서(←), 북(↑)
    int dy[4] = { 1, 0, -1, 0 }; // 원 방향으로 회전하도록
    int time = 0; // 게임 시간
    int dir = 0;  // 뱀의 방향 (처음에 동쪽 방향 가리키도록 0으로 설정)
    int x, y, nx, ny;  // 현재 위치, 이동한 위치 좌표를 저장할 변수 선언

    deque<ci> snake;    // 뱀의 위치
    snake.push_back({ 1, 1 });  // 뱀의 시작 좌표 추가
    state[1][1] = 2;    // (1, 1)에 뱀이 있음을 표시

    while (true) {
        x = snake.front().first;  // 뱀의 머리 x좌표
        y = snake.front().second; // 뱀의 머리 y좌표
        if (direction[time] != 0) { // 뱀의 방향 변환 정보가 있으면
            dir = (dir + direction[time]) % 4; // 뱀의 방향 갱신
        }
        time++; // 게임 시간 1초 추가
        nx = x + dx[dir]; // 뱀 머리의 다음 x좌표
        ny = y + dy[dir]; // 뱀 머리의 다음 y좌표

        // 뱀의 머리가 벽에 부딪히거나 자기 자신의 몸과 부딪히면 
        if (!(0 < nx && nx <= n) || !(0 < ny && ny <= n) || state[nx][ny] == 2) { 
            break; // 게임 종료
        }

        snake.push_front({ nx, ny }); // 이동한 후의 뱀의 머리 좌표 추가
        if (state[nx][ny] != 1) {   // 새로 이동한 좌표에 사과가 없으면 (1이면 사과가 존재함)
            state[snake.back().first][snake.back().second] = 0;  // 보드에서 꼬리 위치 비워주기
            snake.pop_back(); // 스네이크에서 꼬리 위치 비워주기
        }
        state[nx][ny] = 2; // 새로운 머리 좌표 위치 갱신
    }
    return time; // 계산한 종료 시간 반환
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
int main() { // 가장 먼저 실행되는 main 함수
    int n, k, l, x; // 보드 크기, 사과 개수, 방향 변환 횟수, 시작 후 지난 시간 
    char c; // 방향 변환 (L: 왼쪽, D: 오른쪽)
    vector<vector<int>> state; // 보드의 정보 저장
    map<int, int> direction; // 방향 전환 정보 저장

    // 입력
    cin >> n >> k; // 보드 크기, 사과 수 입력
    state.assign(n + 1, vector<int>(n + 1, 0)); // 입력받은 크기로 보드의 크기 할당 및 0으로 초기화
    while (k--) { // k번 동안
        int a, b; // 위치의 x,y 좌표 
        cin >> a >> b; // 입력받기
        state[a][b] = 1; //사과 위치 표시
    }

    cin >> l; // 방향 변환 횟수 입력 
    while (l--) { // l번 동안
        cin >> x >> c; // 변환되는 시간, 변환 방향 입력
        if (c == 'D') {
            direction[x] = 1; // 오른쪽으로 회전
        }
        else {
            direction[x] = 3; // 왼쪽으로 회전
        }
    }

    // 연산
    int time = game(n, state, direction); // 게임이 끝나는 시간

    // 출력
    cout << time; // 끝나는 시간 출력
    return 0; // 메인 함수 종료
}