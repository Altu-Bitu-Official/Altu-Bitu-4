#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int map[501][501];
int visit[501][501];

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int ans = 0;
int n, m;

void sumMap(int x, int y, int sum, int cnt) {
	if (cnt == 4) {//4개블록을 다 탐색
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx > n || ny > m || visit[nx][ny]) {//범위를 벗어나면 다른 방향으로 탐색
			continue;
		}
		visit[nx][ny] = 1;//방문체크
		sumMap(nx, ny, sum+map[nx][ny], cnt + 1);
		visit[nx][ny] = 0;
	}

	//ㅓㅗㅜㅏ의 경우 깊이가 3이 아니므로 별도의 케이스로 탐색
	if (x - 1 >= 1 && y - 1 >= 1 && x + 1 <= n) { //ㅓ
		ans = max(ans, (map[x - 1][y] + map[x][y - 1] + map[x][y] + map[x + 1][y]));
	}
	if (x - 1 >= 1 && y + 1 <= m && x + 1 <= n) { //ㅏ
		ans = max(ans, (map[x - 1][y] + map[x][y + 1] + map[x][y] + map[x + 1][y]));
	}
	if (y - 1 >= 1 && y + 1 <= m && x + 1 <= n) { //ㅗ
		ans = max(ans, (map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1]));
	}
	if (y - 1 >= 1 && y + 1 <= m && x + 1 <= n) { //ㅜ
		ans = max(ans, (map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x + 1][y]));
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j]; //map입력 받기
			visit[i][j] = 0;//visit 초기화
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = 1; //방문체크
			sumMap(i, j, map[i][j], 1);
			visit[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}