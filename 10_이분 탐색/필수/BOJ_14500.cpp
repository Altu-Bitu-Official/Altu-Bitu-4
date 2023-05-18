#include<iostream> // 입출력을 위한 헤더
#include<vector> // 벡터 객체를 사용하기 위한 헤더
#include <algorithm> // 최대를 구하기 위한 알고리즘 라이브러리
using namespace std;

// 테트로미노: 정사각형 4개 이어붙인 도형
// 숫자가 적힌 n x m 종이에 테트로미노를 놓아 숫자들의 합 최대값 출력

vector<vector<int>>board; // 테트로미노를 놓을 보드 선언

int ans; // 최대값 저장할 변수 선언
void dfs(int x, int y, int depth, int sum) { // 연속으로 연결된 도형 찾아야 함 -> dfs 함수 정의
	// 현재 위치 (x, y), 정사각형이 연속으로 이어진 길이인 depth, 숫자들의 합 저장할 sum 입력받음

	vector<int> dx = { -1,0,1,0 }; // 좌 상 우 하
	vector<int> dy = { 0,1,0,-1 }; // 좌 상 우 하

	if (depth == 4) { // 칸 4개 선택했으면 
		ans = max(ans, sum); // ans 최대값 갱신 후
		return;  // 함수 종료
	}

	// 아래 코드가 들어가면 가지치기가 돼 백트래킹이 돼요!
	//if (ans >= MAX * (4 - cnt) + sum) {
	//	return;
	//}

	for (int i = 0; i < 4; i++) { // 현재 위치를 기준으로 상하좌우 4칸 중 한 칸 선택 
		// 선택할 칸
		int nx = x + dx[i]; // x좌표
		int ny = y + dy[i]; // y좌표

		// 유효한 칸인지 판단 -> 범위, 이전에 선택 여부
		if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) {
			// 범위를 벗어났거나 이미 방문한 블록이라면
			continue; // 넘어가기
		}

		int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
		board[nx][ny] = 0; // 방문 처리 : 4개를 선택함에 있어서 똑같은 블록을 선택하지 않기 위해

		if (depth == 2) { // ㅜ 모양은 현재 위치에서 다시 탐색!
			dfs(x, y, depth + 1, sum + temp); // 다음 탐색 -> depth 1 증가 && sum값에 현재 칸 가치 더하기
		}
		// 모든 경우를 탐색해야 함 -> 다시 탐색
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


int main() { // 가장 먼저 실행되는 main 함수

	// 입력
	int n, m; // 세로 가로 
	cin >> n >> m; // 세로 가로 크기 입력
	board.assign(n, vector<int>(m, 0)); // n x m 크기의 보드의 모든 칸을 0으로 초기화

	for (int i = 0; i < n; i++) { // n행
		for (int j = 0; j < m; j++) { // m열의
			cin >> board[i][j]; // 보드에 입력
		}
	}
	// 연산
	for (int i = 0; i < n; i++) { // 첫번째 시작 칸은
		for (int j = 0; j < m; j++) { // 보드의 모든 칸이 가능
			int temp = board[i][j]; // 한 칸 선택
			board[i][j] = 0; // 방문 표시 -> 선택한 칸의 가중치를 0으로 변경 
			dfs(i, j, 1, temp); // 탐색 진행
			board[i][j] = temp; // 보드를 원래 상태로 돌려놓음
		}
	}
	// 출력
	cout << ans; // 갱신한 최대값인 ans 출력
	return 0; // 메인 함수 종료
}