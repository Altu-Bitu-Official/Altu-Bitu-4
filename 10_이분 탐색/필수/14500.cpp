#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;   

int ans;    // 결과값

void dfs(int x, int y, int depth, int sum) {

    // 방향: 위, 오른쪽, 아래, 왼쪽
	vector<int> dx = { -1,0,1,0 };
	vector<int> dy = { 0,1,0,-1 };

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);    // 지금까지의 최댓값 ans와 이번에 계산해서 나온 sum 중에서 큰 값이 ans가 된다 
		return;
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

	for (int i = 0; i < 4; i++) {       //위, 오른쪽, 아래, 왼쪽을 탐색한다
		// 선택할 칸
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;
		}

		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		// 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp);
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

	}
}

/*
* HINT : 하나의 도형은 무언가 특별한 것 같아요! or 테트로미노의 모양은 탐색의 관점에서 특징이 있는 것 같아요!
* 1. ㅜ 모양을 제외한 테트로미노의 모양은 깊이가 4인 dfs의 탐색 모양
*     -> dfs로 블록을 하나씩 선택해가면서 개수(cnt)와 합(sum)을 계산
*     -> 4개 선택하면 최댓값 갱신
* 2. 예외 : ㅜ 모양은 블록을 2개 선택했을 때 현재 블록에서 다시 블록을 선택해준다.
*/


int main() {

	// 입력
	int n, m;   // 세로크기 n, 가로크기 m
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0)); // 칸의 숫자들을 저장할 벡터

    // 각 n*m 칸의 숫자들을 입력받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산: 각각의 모든 칸을 iterate
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = board[i][j];     // temp에 그 칸의 숫자를 저장하고
			board[i][j] = 0;    // 해당 칸에 0을 넣은 후 (방문)
			dfs(i, j, 1, temp); // dfs 를 수행
			board[i][j] = temp; // 보드의 해당 칸을 원래의 숫자로 되돌린다
		}
	}

	// 출력
	cout << ans;
	return 0;
}