#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> dx = { 0, 0, 1, -1 }; // 상하좌우 이동을 위한 dx, dy 이동 값 설정
const vector<int> dy = { 1, -1, 0, 0 };

int dfs(int x, int y, int depth, int sum, int ans, vector<vector<int>>&board) {
	if (depth == 4) {//depth가 4인 경우
		return max(ans, sum); //ans 최대값 갱신
	}
	//하나 더 선택
	//현재 위치를 기준으로 유효한 한 칸을 선택
	for (int i = 0; i < 4; i++) {
		//후보 위치
		int nx = x + dx[i];
		int ny = y + dy[i];

		//후보 위치가 유효한 칸인지 판단->범위, 이전에 선택
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { //범위를 벗어났거나 이미 방문한 블록일 경우 
			continue; //다른 칸으로 탐색 넘어감
		}
		//범위에 있는 아직 방문하지 않은 위치이면
		int temp = board[nx][ny]; //위치 값 저장
		board[nx][ny] = 0; //방문처리

		//다음 탐색
		if (depth == 2) {//우모양-> 선택한 칸으로 이동하지 않고 현재 위치에서 다시 탐색
			ans = max(ans, dfs(x, y, depth + 1, sum + temp, ans, board));
		}
		//모든 경우를 탐색->우모양->다시 탐색
		ans =dfs(nx, ny, depth + 1, sum + temp, ans, board); //선택한 칸 (nx, ny)로 이동 후 dfs 실행

		//보드 원래대로 돌려놓기
		board[nx][ny] = temp; //최대값이 아닐 경우 
	}
	return ans; //최대값 출력
}

int main(){
	//입력
	int n, m; //변수 선언
	int ans = -1; //초기값 설정, 최대 ans값은 -1보다는 무조건 크므로
	vector<vector<int>> board; //종이

	cin >> n >> m; //m, n값 입력받기
	board.assign(n, vector<int>(m, 0)); //종이값 저장공간 0으로 초기화
	for (int i = 0; i<n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; //종이 칸마다 값 입력받기
		}
	}

	//연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//여기서 한 칸을 선택
			// 방문표시->선택한 칸의 가중치를 0으로 바꾸고 다음 depth
			int temp = board[i][j];//첫번째 자리 선택
			board[i][j] = 0; //선택한 자리 방문으로 변경
			ans = max(ans, dfs(i, j, 1, temp, ans, board)); //테트로미노 최대값 호출
			board[i][j] = temp; //처음 자리 원래 값으로 돌려놓기
		}
	}
	cout << ans; //최대값 출력
	return 0;
}