#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

void bfsIsland(int w, int h, vector<vector<int>>& map, vector<vector<int>>& visited, queue<ii>& land) {
	//주변 8개의 방향
	int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	while (!land.empty()) {
		int r = land.front().first;
		int c = land.front().second;
		land.pop();

		//이웃한 섬들을 visited 상태로 바꿈
		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < w && nc >= 0 && nc < h && !visited[nr][nc] && map[nr][nc] == 1) {
				visited[nr][nc] = true;
				land.push({ nr,nc });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int w, h; //지도의 너비, 높이
	while (true) {
		//입력
		cin >> h >> w;
		if (w == 0 && h == 0) {
			break;
		}
		vector<vector<int>> map(w, vector<int>(h));
		vector<vector<int>> visited(w, vector<int>(h, false));
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> map[i][j];
			}
		}

		//연산
		int cnt = 0; //섬의 개수
		queue<ii> land; //탐색해야 할 땅
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				//아직 방문하지 않은 땅인 경우 (새로운 섬)
				if (map[i][j] == 1 && !visited[i][j]) {
					cnt++;
					land.push({ i,j });
					visited[i][j] = true;
					bfsIsland(w, h, map, visited, land);
				}
			}
		}

		//출력
		cout << cnt << "\n";
	}

	return 0;
}