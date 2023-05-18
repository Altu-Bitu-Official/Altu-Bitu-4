#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;

int ans;

void dfs(int x, int y, int depth, int sum) { // ㅗ모양 빼고 나머지 도형들은 한 점에서 depth 4인 깊이 우선 탐색으로 구할 수 있음

	vector<int> dx = { -1,0,1,0 };
	vector<int> dy = { 0,1,0,-1 };

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 선택할 칸
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;
		}

		int temp = board[nx][ny]; //해당 칸 저장
		board[nx][ny] = 0; // 방문 처리해주기 -> 중복 제외할려고

		if (depth == 2) { // ㅜ 모양일 경우 -> 현재 위치에서 다시 탐색
			dfs(x, y, depth + 1, sum + temp);
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // 재방문할 수 있으므로 원래대로 돌려줌

	}
}



int main() {

	// 입력
	int n, m;
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = board[i][j];
			board[i][j] = 0;
			dfs(i, j, 1, temp);
			board[i][j] = temp;
		}
	}

	// 출력
	cout << ans;
	return 0;
}