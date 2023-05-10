#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;

int ans; // 최댓값 저장

void dfs(int x, int y, int depth, int sum) {

	vector<int> dx = { -1,0,1,0 }; // 선택할 수 있는 칸의 방향(가로)
	vector<int> dy = { 0,1,0,-1 }; // 선택할 수 있는 칸의 방향(세로))

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신, 리턴
		ans = max(ans, sum);
		return;
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

	for (int i = 0; i < 4; i++) {
		// 선택할 칸 
        // 왼쪽, 아래, 오른쪽, 위 중 하나가 선택됨
		int nx = x + dx[i]; 
		int ny = y + dy[i];

        // 선택할 칸의 좌표가 0보다 작거나 종이의 크기보다 크면 continue하여 다음 반복문으로 넘어감
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;
		}

		int temp = board[nx][ny]; // temp에 선택할 칸의 값을 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		// 다음 dfs는 depth 1 증가, sum값에 현재 칸의 값 더하기
		if (depth == 2) { // ㅜ 모양은 두개 블록 선택했을 시점에서 다시 탐색
			dfs(x, y, depth + 1, sum + temp); // 선택한 nx, ny사용 X. 블록을 두개 선택했을 시점의 x,y 사용
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // board[nx][ny]값을 원래대로 저장해줌

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
	int n, m;
	cin >> n >> m;
	board.assign(n, vector<int>(m, 0));

    // 종이에 쓰여있는 수 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = board[i][j]; //temp에 board[i][i]값 저장
			board[i][j] = 0; //board[i][j] 0으로 초기화
			dfs(i, j, 1, temp);
			board[i][j] = temp; //기존 board[i][j]값 다시 저장
		}
	}

	// 출력
	cout << ans;
	return 0;
}