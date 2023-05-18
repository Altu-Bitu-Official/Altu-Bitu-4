#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;  

int ans; //구하려는 값 ans 

void dfs(int x, int y, int depth, int sum) {

	vector<int> dx = { -1,0,1,0 }; //x방향 벡터값들 (칸 이동 시 사용)  
	vector<int> dy = { 0,1,0,-1 }; //y방햑 벡터값들 (칸 이동 시 사용용)

	if (depth == 4) { // 칸 4개 선택했으면 ans 최대값 갱신
		ans = max(ans, sum);
		return;
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

	for (int i = 0; i < 4; i++) {
		// 선택할 칸
		int nx = x + dx[i]; //i에 따라 방향 선택 
		int ny = y + dy[i]; //i에 따라 방향 선택 

		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) { 
		    // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
			continue; //다음 i에 대해 진행 
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
	int n, m; //종이의 세로 크기 n 가로 크기 m
	cin >> n >> m; //n과 m 입력 
	board.assign(n, vector<int>(m, 0)); //n행 m열 벡터 


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; //차례대로 board에 입력 
		}
	}

	// 연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    //한 칸을 선택
		    //방문표시 -> 선택한 칸의 가중치를 0으로 바꾸고 다음 depth
			int temp = board[i][j]; //임시 변수 선언 
			board[i][j] = 0; //방문 표시 
			dfs(i, j, 1, temp); //dfs 탐색 -> 가장 큰 경우 ans에 저장 
			board[i][j] = temp; //다음 탐색을 위헤 되돌려 놓음
		}
	}

	// 출력
	cout << ans;
	return 0;
}
