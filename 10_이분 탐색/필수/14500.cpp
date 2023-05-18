#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;  //종이에 쓰여있는 수 저장할 벡터

int ans;	//답 저장할 변수

void dfs(int x, int y, int depth, int sum) {

	vector<int> dx = { -1,0,1,0 };	//방향계 x 좌표
	vector<int> dy = { 0,1,0,-1 };	//방향계 y좌표

	if (depth == 4) { // 칸 4개 선택했으면
		ans = max(ans, sum);	//ans와 sum 중 최대값으로 갱신
		return;	//dfs 종료
	}
	
	for (int i = 0; i < 4; i++) { // 선택할 칸
		int nx = x + dx[i];  //다음 칸 선택 (가로)
		int ny = y + dy[i];  //다음칸 선택(세로)

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue;
		}
		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		// 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
		if (depth == 2) { // ㅜ 모양일 경우
			dfs(x, y, depth + 1, sum + temp);//재 위치에서 다시 탐색
		}
		dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

		board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

	}
}

int main() {

	int n, m;	//n:종이의 세로 m:종이의 가로
	cin >> n >> m;	//입력
	board.assign(n, vector<int>(m, 0));  //종이 입력받을 벡터 초기화

	for (int i = 0; i < n; i++) {		//세로
		for (int j = 0; j < m; j++) {	//가로
			cin >> board[i][j];	//종이 숫자 입력받기
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {	//세로만큼
		for (int j = 0; j < m; j++) {	//가로만큼 반복문
			int temp = board[i][j];	//temp에 칸 숫자 저장
			board[i][j] = 0;	//해당 칸 초기화
			dfs(i, j, 1, temp);	//dfs 연산
			board[i][j] = temp;	//해당 칸 돌려놓기
		}
	}

	cout << ans;	//출력
	return 0;
}
