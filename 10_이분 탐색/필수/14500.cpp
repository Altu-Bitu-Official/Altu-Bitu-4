#include<iostream> 
#include<vector> 
#include <algorithm> 

using namespace std;

vector<vector<int>>board;//2차배열

int ans; // 정답

void dfs(int x, int y, int depth, int sum) { // 깊이 우선 탐색 함수

	vector<int> dx = { -1,0,1,0 }; // x 좌표 이동 배열
	vector<int> dy = { 0,1,0,-1 }; // y 좌표 이동 배열

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);// 큰 거로 선택
		return;
	}

	for (int i = 0; i < 4; i++) {
		// 선택할 칸
		int nx = x + dx[i];//지금 x에서 다음 x로
		int ny = y + dy[i];//지금 y에서 다음 y로 

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;
		}

		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp);// 현재 위치에서 다시 dfs 함수 호출
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

	}
}

int main() {

	int n, m;
	cin >> n >> m;//가로,세로 크기
	board.assign(n, vector<int>(m, 0));//2차배열에 할당. 행: n, 열: m. 0으로 초기화


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];//숫자 넣어주기
		}
	}

	for (int i = 0; i < n; i++) { // board의 모든 행에 대해
		for (int j = 0; j < m; j++) { // board의 모든 열에 대해
			int temp = board[i][j]; // 현재 위치의 값을 저장
			board[i][j] = 0; // 현재 위치를 방문 처리
			dfs(i, j, 1, temp); // dfs 함수 호출
			board[i][j] = temp; // 현재 위치의 값을 원래대로 복구
		}
	}

	cout << ans;//출력
	return 0;
}
