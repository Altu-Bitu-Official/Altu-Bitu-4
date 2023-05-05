#include <iostream>
#include <vector>

using namespace std;

int n;
int max_num = -1000000000, min_num = 1000000000;
vector<int> num;
vector<int> op;

//숫자 두개와 연산자를 입력받아 계산하는 함수
int calculation(int n1, int n2, int op_num) {
	switch (op_num) {
		case 0:
			return n1 + n2;
			break;
		case 1:
			return n1 - n2;
			break;
		case 2:
			return n1 * n2;
			break;
		case 3:
			return n1 / n2;
	}
}

//cnt: 사용한 연산자의 개수, idx: 다음 탐색 숫자 인덱스, result: 지금까지의 연산 결과
void backtracking(int cnt, int idx, int result) {
	//종료 조건: 모든 연산자를 사용한 경우
	if (cnt == n - 1) {
		max_num = max(max_num, result);
		min_num = min(min_num, result);
		return;
	}

	for (int i = idx; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (op[j] == 0) {
				continue;
			}

			//사용
			op[j]--;

			//다음 연산
			backtracking(cnt + 1, i + 1, calculation(result, num[i], j));

			//반납
			op[j]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;

	num.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	op.assign(4, 0);
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	//연산
	backtracking(0, 1, num[0]);

	//출력
	cout << max_num << "\n" << min_num << "\n";

	return 0;
}