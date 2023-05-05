#include <iostream>

using namespace std;
const int SIZE = 15;

int n, ans;
bool is_queen_in_col[SIZE];
bool is_queen_in_left[SIZE * 2];
bool is_queen_in_right[SIZE * 2];

/**
 * 각 행 당 하나의 퀸이 존재하므로 행마다 퀸을 하나씩 놓아본다.
 *
 * r: 현재 놓으려는 행
 */
void backtrack(int r) {
    // 재귀 호출 종료 조건: N개의 퀸이 모두 놓임
    if (r == n) {
        ans++;
        return;
    }
    
    // c: 열
    for (int c = 0; c < n; c++) {
        // 세로, 좌하향 대각선, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
        if (!is_queen_in_col[c] && !is_queen_in_left[r + c] && !is_queen_in_right[r - c + n]) {
            // (r, c)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            is_queen_in_col[c] = true;
            is_queen_in_left[r + c] = true;
            is_queen_in_right[r - c + n] = true;
            
            // 다음 행에도 놓기
            backtrack(r + 1);
            
            // 재탐색이 가능하도록 놓았던 퀸 회수
            is_queen_in_col[c] = false;
            is_queen_in_left[r + c] = false;
            is_queen_in_right[r - c + n] = false;
        }
    }
}

int main() {
    // 입력
    cin >> n;

    // 연산
    backtrack(0);

    // 출력
    cout << ans;
    
    return 0;
}