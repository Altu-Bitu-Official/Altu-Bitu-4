#include <iostream>
#include <vector>

using namespace std;

const int MAX_LEN = 19;
typedef pair<int, int> ci;

int dx[4] = { 0, 1, 1, -1 };
int dy[4] = { 1, 0, 1, 1 };

bool isValid(vector<vector<int>>& arr, ci s) {
    int cnt, x, y, nx, ny;
    // 시작점 좌표 설정
    x = s.first;
    y = s.second;

    // 4가지 방향으로 탐색
    for (int i = 0; i < 4; i++) {
        nx = x;
        ny = y;
        for (cnt = 0; cnt < 5; cnt++) { // 같은 색 돌이 5번 연속일 때까지 반복
            nx += dx[i];
            ny += dy[i];
            // 같은 색 돌이면 탐색을 계속한다.
            if ((0 < nx && nx <= MAX_LEN && 0 < ny && ny <= MAX_LEN) && arr[nx][ny] == arr[x][y]) {
                continue;
            }
            // 다른 색 돌이 등장하면 break
            break;
        }
        if (cnt == 4) { // 탐색한 방향으로 다섯 알이 연속인 경우
            // 역방향 검사
            nx = x - dx[i];
            ny = y - dy[i];
            // 역방향에는 돌을 놓을 수 없을 때 -> 오목 O
            if (!(0 < nx && nx <= MAX_LEN && 0 < ny && ny <= MAX_LEN)) {
                return true;
            }
            // 역방향에 같은 색 돌이 없을 때 -> 오목 O
            else if (arr[nx][ny] != arr[x][y]) {
                return true;
            }
            // 역방향에 같은 색 돌이 있을 때 -> 오목 x
        }
    }
    return false;
}
/** 해당 색의 돌이 게임을 이기면 가장 왼쪽 위에 있는 바둑알의 위치를, {0, 0} 리턴 */
ci solution(vector<vector<int>>& arr, vector<ci>& stones) {
    for (auto s : stones) {
        if (isValid(arr, s)) { // s를 시작점으로 오목이 가능하다면
            return s;          // s 반환
        }
    }
    //{0, 0} 반환
    return { 0, 0 };
}
/**[백준 2615: 오목]
 * (주의)
 * - 게임에서 이기면 연속된 다섯 개의 가장 왼쪽 위에 있는 바둑알을 출력해야 하므로 탐색 방향에 유의
 * - 여섯 알 이상이 연속이면 오목 X
 * 1. 바둑판의 상태를 입력받아 검은색 돌의 위치와 흰색 돌의 위치를 각각 저장
 * 2. 각각의 돌을 시작점으로 하여 오목을 만들 수 있는지 판단
 * 3. 최대 4개의 돌이 연속하거나, 5개의 돌이 연속했지만 탐색한 반대 방향에도 같은 색의 돌이 있으면 오목 실패
 * 4. 오목에 성공했으면 시작점으로 한 돌의 좌표 반환
 *           실패했으면 {0, 0} 반환
*/
int main() {
    // 입력
    vector<vector<int>> arr(MAX_LEN + 1, vector<int>(MAX_LEN + 1)); // 전체 바둑판 저장
    vector<ci> black_stones, white_stones; // 검은돌과 흰돌의 위치를 각각 저장한다. -> 검사할 위치를 줄일 수 있음
    for (int i = 1; i <= MAX_LEN; i++) {
        for (int j = 1; j <= MAX_LEN; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                black_stones.push_back({ i, j });
            }
            else if (arr[i][j] == 2) {
                white_stones.push_back({ i, j });
            }
        }
    }

    // 검은돌과 흰돌 따로 연산
    ci black_win = solution(arr, black_stones);
    ci white_win = solution(arr, white_stones);

    // 출력
    if (black_win.first) { // 검은 돌 승리
        cout << "1\n"
            << black_win.first << " " << black_win.second;
    }
    else if (white_win.first) { // 흰 돌 승리
        cout << "2\n"
            << white_win.first << " " << white_win.second;
    }
    else {
        cout << "0";
    }
    return 0;
}