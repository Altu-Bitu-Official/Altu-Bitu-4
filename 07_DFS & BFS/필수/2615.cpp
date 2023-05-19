#include <iostream>
#include <vector>

using namespace std;

const int A = 19;
// 아래, 오른쪽, 우하향 대각선, 우상향 대각선
int dx[4] = { 0, 1, 1, 1 };
int dy[4] = { 1, 0, 1, -1 };

int findWinner(vector<vector<int>> table, int i, int j) {
	int ti = i; int tj = j;
	int winner = 0;
	int count = 1; // 연속된 돌의 수.

	for (int k = 0; k < 3; k++) {
		while (1) {
			if (table[ti][tj] == table[ti + dx[k]][tj + dy[k]]) {
				count++;
				ti += dx[k];
				tj += dy[k];
				if (count == 5) {
					break;
				}
			}
			else {
				break;
			}
		}
		if (count == 5) {
			// 육목인지 체크
			if ((table[i - dx[k]][j - dy[k]] == table[i][j]) || (table[ti + dx[k]][tj + dy[k]] == table[ti][tj])) {
				winner = 0;
			}
			else {
				winner = table[i][j];
			}
		}
	}
	return winner;
}

int main() {
	int flag = 0;
	int winner = 0;
	int wi, wj;
	// 바둑판
	vector<vector<int>> table(A, vector<int>(A, 0));
	// 입력
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			cin >> table[i][j];
		}
	}
	
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (table[i][j] == 1 || table[i][j] == 2) {
				flag = findWinner(table, i, j); // 0 1 2 중 하나를 반환	
				if (flag) {
					winner = flag;
					wi = i; wj = j;
				}
			}
		}
	}
	//출력

	if (winner) {
		cout << winner << endl;
		cout << wi + 1 << ' ' << wj + 1 << endl;
	}
	else {
		cout << winner << endl;
	}
		

	return 0;
}