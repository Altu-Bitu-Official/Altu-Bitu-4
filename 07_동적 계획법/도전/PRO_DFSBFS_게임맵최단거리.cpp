#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	int n = maps.size();
	int m = maps[0].size();

	queue<ii> q; //앞으로 가야하는 길 저장
	q.push({ 0,0 }); //시작 지점

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		answer = maps[r][c];
		q.pop();

		//4개의 방향으로 탐색
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			//갈 수 있는 길인데 아직 가지 않은 경우 탐색할 큐에 저장
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && maps[nr][nc] == 1) {
				q.push({ nr,nc });
				maps[nr][nc] = answer + 1;
			}
		}
	}

	//마지막 칸에 도달하지 못한 경우 -1 출력
	if (maps[n - 1][m - 1] == 1) {
		answer = -1;
	}
	else {
		answer = maps[n - 1][m - 1];
	}
    return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> maps(5, vector<int>(5));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> maps[i][j];
		}
	}

	//연산 & 출력
	cout << solution(maps);

	return 0;
}