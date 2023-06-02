#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

bool is_finished;
int sudoku[MAX][MAX];

bool checkRow(int r, int n) {
    for (int i = 0; i < MAX; i++) {
        if (sudoku[r][i] == n) {
            return false;
        }
    }
    
    return true;
}

bool checkCol(int c, int n) {
    for (int i = 0; i < MAX; i++) {
        if (sudoku[i][c] == n) {
            return false;
        }
    }
    
    return true;
}

bool checkSquare(int r, int c, int n) {
    // (base_r, base_c): (r,c)가 속한 정사각형의 왼쪽 상단 꼭짓점 좌표
    int base_r = r / 3 * 3;
    int base_c = c / 3 * 3;
    
    for (int i = 0; i < (MAX / 3); i++) {
        for (int j = 0; j < (MAX / 3); j++) {
            if (sudoku[base_r + i][base_c + j] == n) {
                return false;
            }
        }
    }
    
    return true;
}

bool check(int r, int c, int n) {
    return checkRow(r, n) && checkCol(c, n) && checkSquare(r, c, n);
}

/**
 * (0, 0)부터 차례로 빈칸을 채워나간다
 *
 * idx: 왼쪽 상단부터 매긴 칸 번호, (row * 9) + col
 */
void fillSudoku(int idx) {
    // 재귀 호출 종료 조건: 스도쿠 판을 다 채운 경우
    if (idx == MAX * MAX) {
        is_finished = true;
        return;
    }
    
    int r = idx / MAX;
    int c = idx % MAX;
    
    // 빈칸이 아닌 경우
    if (sudoku[r][c] != 0) {
        // 바로 다음 칸 탐색
        fillSudoku(idx + 1);
    }
    // 빈칸인 경우
    else {
        // i: 이번 빈칸에 넣을 수
        for (int i = 1; i <= MAX; i++) {
            // 불가능한 경우
            if (!check(r, c, i)) {
                continue;
            }
            
            sudoku[r][c] = i;
            fillSudoku(idx + 1);
            if (is_finished) { // 채우기에 성공했으면
                return;       // 현재 상태를 출력해야 하므로 원상태로 돌려놓지 않고 즉시 종료
            }
            sudoku[r][c] = 0;
        }
    }
}

/**
 * 모든 빈칸에 1~9를 넣어본다.
 * 단, 가로, 세로, 정사각형에 같은 수가 있는 경우는 가지치기해준다.
 * 가지치기를 위해 가로 9칸, 세로 9칸, 정사각형 9칸을 모두 탐색한다.
 *
 * 가지치기 시간 복잡도: O(N)
 * 약 245ms
 */
int main()
{
    // 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> sudoku[i][j];
        }
    }
    
    // 연산
    fillSudoku(0);
    
    // 출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}