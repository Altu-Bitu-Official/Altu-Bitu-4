#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //북, 동, 남, 서

int cleanRoom(int n, int m, int r, int c, int d, vector<vector<int>>& state) {
	int cnt = 0; //청소한 칸의 개수
	int x = r, y = c; //현재 칸

	while (true) {
		//1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (state[x][y] == 0) {
			cnt++;
			state[x][y] = 2; //청소 완료
		}

		bool clean = true; //주변 4칸 중 청소되지 않은 빈 칸의 여부
		for (int i = 0; i < 4; i++) {
			if ((x + dx[i] >= 0) && (x + dx[i] < n) && (y + dy[i] >= 0) && (y + dy[i] < m) && (state[x + dx[i]][y + dy[i]] == 0)) {
				clean = false;
			}
		}

		//2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		if (clean) {
			//1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
			if ((x - dir[d][0] >= 0) && (x - dir[d][0] < n) && (y - dir[d][1] >= 0) && (y - dir[d][1] < m) && (state[x - dir[d][0]][y - dir[d][1]] != 1)) {
				x -= dir[d][0];
				y -= dir[d][1];
				continue;
			}

			//2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			else {
				break;
			}
		}

		//3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		else {
			//1) 반시계 방향으로 90% 회전한다.
			d = (d + 3) % 4;

			//2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진하고 1번으로 돌아간다.
			if ((x + dir[d][0] >= 0) && (x + dir[d][0] < n) && (y + dir[d][1] >= 0) && (y + dir[d][1] < m) && (state[x + dir[d][0]][y + dir[d][1]] == 0)) {
				x += dir[d][0];
				y += dir[d][1];
				continue;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, r, c, d;
	cin >> n >> m >> r >> c >> d;

	vector<vector<int>> state(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> state[i][j];
		}
	}

	//연산 & 출력
	cout << cleanRoom(n, m, r, c, d, state);

	return 0;
}