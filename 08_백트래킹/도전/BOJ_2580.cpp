#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

typedef pair<int, int> ii;

int zero_cnt = 0; //빈 칸의 개수
vector<vector<int>> sudoku(SIZE, vector<int>(SIZE));
vector<ii> zero;
bool finish = false;

//(r, c)에 n이 들어갈 수 있는지 확인하는 함수
bool check(int r, int c, int n) {
	//같은 행에 해당 숫자가 있는지 확인
	for (int i = 0; i < SIZE; i++) {
		if (i != c && sudoku[r][i] == n) {
			return false;
		}
	}

	//같은 열에 해당 숫자가 있는지 확인
	for (int i = 0; i < SIZE; i++) {
		if (i != r && sudoku[i][c] == n) {
			return false;
		}
	}

	//3x3 정사각형 안에 해당 숫자가 있는지 확인
	int r_idx = (r / 3) * 3;
	int c_idx = (c / 3) * 3;
	for (int i = r_idx; i < r_idx + 3; i++) {
		for (int j = c_idx; j < c_idx + 3; j++) {
			if (i != r && j != c && sudoku[i][j] == n) {
				return false;
			}
		}
	}

	//모두 해당되지 않은 경우 true 반환
	return true;
}

//idx: 빈 칸의 인덱스
void backtracking(int idx) {
	//종료 조건: 모든 빈 칸이 채워진 경우
	if (idx == zero_cnt) {
		finish = true; //종료 상태를 true로 변경
		return;
	}

	//빈 칸의 좌표
	int r = zero[idx].first;
	int c = zero[idx].second;
	
	//1부터 9까지 가능한 수 채워넣기
	for (int n = 1; n <= 9; n++) {
		//빈 칸에 숫자를 놓을 수 있는 경우
		if (check(r, c, n)) {
			//사용
			sudoku[r][c] = n;

			//다음 칸 채우기
			backtracking(idx + 1);

			//완성되었다면 더 이상 for문을 진행할 필요가 없으므로 break
			if (finish) {
				break;
			}

			//반납
			sudoku[r][c] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				zero.push_back({ i,j });
				zero_cnt++;
			}
		}
	}

	//연산
	backtracking(0);

	//출력
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}