#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//5가지 테트로미노 모양
int dx[5][4] = {
	{0,1,2,3}, //파랑
	{0,1,0,1}, //노랑
	{0,0,0,1}, //주황
	{0,0,1,1}, //초록
	{0,1,2,1} //분홍
};
int dy[5][4] = {
	{0,0,0,0}, //파랑
	{0,0,1,1}, //노랑
	{0,1,2,2}, //주황
	{0,1,1,2}, //초록
	{0,0,0,1} //분홍
};

//회전 8가지
int rx[4] = { 1,-1,1,-1 };
int ry[4] = { 1,1,-1,-1 };

//(x, y)칸을 포함하는 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값 반환
int maxSum(int n, int m, int x, int y, vector<vector<int>>& num) {
	int max_sum = 0;

	//4가지 회전 탐색
	for (int k = 0; k < 4; k++) {

		//5가지 모양 탐색
		for (int i = 0; i < 5; i++) {
		
			//이웃한 4개의 칸 탐색
			int sum_num = 0;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[i][j] * rx[k];
				int ny = y + dy[i][j] * ry[k];

				//이웃한 칸이 범위를 벗어나는 경우 해당 모양 탐색 끝내기
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					sum_num += num[nx][ny];
				}
				else {
					sum_num = 0;
					break;
				}
			}
			//최댓값으로 갱신
			max_sum = max(max_sum, sum_num);

			//대칭 (x, y) -> (y, x)
			sum_num = 0;
			for (int j = 0; j < 4; j++) {
				int nx = x + dy[i][j] * rx[k];
				int ny = y + dx[i][j] * ry[k];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					sum_num += num[nx][ny];
				}
				else {
					sum_num = 0;
					break;
				}
			}
			max_sum = max(max_sum, sum_num);
		}
	}
	return max_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<vector<int>> num(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num[i][j];
		}
	}

	//연산
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//모든 칸에 대해서 실행
			result = max(result, maxSum(n, m, i, j, num));
		}
	}

	//출력
	cout << result;

	return 0;
}