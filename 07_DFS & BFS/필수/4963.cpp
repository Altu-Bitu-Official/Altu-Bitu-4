#include<iostream>
#include <string.h>
#include<queue>

using namespace std;
int island[50][50];
 bool visit[50][50];

void dfs(int y, int x, int w, int h) {
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nextx = x + dx[i];
			int nexty = y + dy[i];

			if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h) {
				continue;//값이 유효한 범위 내인지 확인
			}
			if (island[nexty][nextx] == 1 && !visit[nexty][nextx]) {//땅인데 아직 방문하지 않았다면
				visit[nexty][nextx] = true; //방문한 것으로 갱신
				q.push(make_pair(nextx, nexty));
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	while (1) {// 0 0을 입력받으면 종료
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		int num = 0;//섬의 개수
		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> temp;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];//섬인지 바다인지 입력 받음
				if (island[i][j] == 1) {
					temp.push(make_pair(j, i));
				}
			}
		}
		
		while (!temp.empty()) {
			int tempx = temp.front().first;
			int tempy = temp.front().second;
			if (!visit[tempy][tempx]) { // 밟지 않은 땅일 경우
				visit[tempy][tempx] = true;
				dfs(tempx, tempy, w, h); // bfs호출
				num++;
			}
			temp.pop();
		}
		cout << num << "\n";
	}
	return 0;
}