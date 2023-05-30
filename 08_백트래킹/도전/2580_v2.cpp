#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

bool is_finished;
int sudoku[MAX][MAX];
bool is_in_row[MAX][MAX + 1];    // is_in_row[r][n]: r번 행에 n이 존재하는지 여부
bool is_in_col[MAX][MAX + 1];    // is_in_col[c][n]: c번 열에 n이 존재하는지 여부
bool is_in_square[MAX][MAX + 1]; // is_in_square[s][n]: s번 정사각형에 n이 존재하는지 여부

/**
 * 정사각형 계산 함수
 * (r, c)가 속한 3*3 정사각형의 번호를 리턴
 */
int calcSquare(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void fill(int r, int c, int n) {
    sudoku[r][c] = n;
    is_in_row[r][n] = true;
    is_in_col[c][n] = true;
    is_in_square[calcSquare(r, c)][n] = true;
}

void empty(int r, int c) {
    int n = sudoku[r][c];
    sudoku[r][c] = 0;
    is_in_row[r][n] = false;
    is_in_col[c][n] = false;
    is_in_square[calcSquare(r, c)][n] = false;
}

bool check(int r, int c, int n) {
    return !is_in_row[r][n] && !is_in_col[c][n] && !is_in_square[calcSquare(r, c)][n];
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
            
            fill(r, c, i);
            fillSudoku(idx + 1);
            if (is_finished) { // 채우기에 성공했으면
                return;        // 현재 상태를 출력해야 하므로 원상태로 돌려놓지 않고 즉시 종료
            }
            empty(r, c);
        }
    }
}

/**
 * 모든 빈칸에 1~9를 넣어본다.
 * 단, 가로, 세로, 정사각형에 같은 수가 있는 경우는 가지치기해준다.
 * 가지치기를 위해 각 가로, 세로, 정사각형에 특정 숫자가 존재하는지 여부를 배열로 관리한다.
 *
 * 가지치기 시간 복잡도: O(1)
 * 약 90ms
 */
int main()
{
    int n;
    
    // 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> n;
            fill(i, j, n);
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