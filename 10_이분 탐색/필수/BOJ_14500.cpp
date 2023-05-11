#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;	// 종이의 정보를 저장하기 위한 벡터

int ans;	// 최종 답을 저장할 변수

void dfs(int x, int y, int depth, int sum) {	// 현재 칸의 x 좌표, y 좌표, depth(칸 선택 횟수), 가치의 합을 전달받아서 탐색하는 함수

	// 상, 하, 좌, 우를 탐색하기 위한 벡터
	vector<int> dx = { -1,0,1,0 };
	vector<int> dy = { 0,1,0,-1 };

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);	// 최댓값 갱신해서 ans에 저장
		return;
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

	for (int i = 0; i < 4; i++) {	// 좌, 우, 상, 하 총 4번 탐색
		
		int nx = x + dx[i];	// 선택할 칸의 x 좌표
		int ny = y + dy[i];	// 선택할 칸의 y 좌표

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { // 범위를 벗어났거나(x 또는 y의 좌표가 종이의 범위 밖), 이미 방문한 블록이라면(가치가 0)
			continue;	// 넘어가기
		}

		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해 방문한 칸의 가치를 0으로 변경

		// 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp);	// depth와 sum만 증가시킨 채로 현재 위치에서 재탐색
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
	int n, m;	// 종이의 세로, 가로 크기 저장할 변수 선언
	cin >> n >> m;	// 종이의 세로, 가로 크기 입력받기
	board.assign(n, vector<int>(m, 0));	// 종이 정보 (숫자) 저장할 변수 선언


	for (int i = 0; i < n; i++) {	// 종이의 크기 n x m 만큼 반복
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];	// 종이에 적힌 숫자 입력받기
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {	// 종이의 크기 n x m 만큼 반복
		for (int j = 0; j < m; j++) {
			int temp = board[i][j];	// 방문 처리하기 전 현재 칸의 가치를 temp에 저장
			board[i][j] = 0;	// 방문 표시를 하기 위해 가치를 0으로 변경
			dfs(i, j, 1, temp);	// 현재 칸의 위치와 1(선택한 칸 1개), 현재 칸의 가치를 함수 dfs에 전달하고 탐색하기
			board[i][j] = temp;	// 현재 칸의 가치를 원래의 값으로 되돌리기
		}
	}

	// 출력
	cout << ans;	// ans에 저장된 최종 답 출력
	return 0;
}