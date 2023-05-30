#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

// 상하좌우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

pair<int, ci> eatFish(int n, int shark_size, ci &shark_loc, vector<vector<int>>& board) {
	priority_queue <pair<int, ci>, vector<pair<int, ci>>, greater<pair<int, ci>>> pq; // min heap으로 구현, first: 거리, second: 좌표(y, x)
	queue<ci> q; // 좌표 (y, x)
	vector<vector<int>> dist(n, vector<int>(n, 0)); // 이동한 거리
	dist[shark_loc.first][shark_loc.second] = 1;
	q.push(shark_loc);
	while (!q.empty()) {
		ci curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) { // bfs
			ci next = { curr.first + dy[i], curr.second + dx[i] };
			if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) { // 공간 범위
				if (dist[next.first][next.second]) {
					continue;
				}	
				if (board[next.first][next.second] > shark_size) {
					continue;
				}
				// 먹이 후보 물고기를 우선순위 큐에 push
				if (board[next.first][next.second] && board[next.first][next.second] < shark_size) {
					pq.push({ dist[curr.first][curr.second], next });
					continue;
				}
				dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
				q.push(next);
			}
		}
	}
	if (pq.empty()) {
		return { -1, { -1, -1 } };
	}
	board[pq.top().second.first][pq.top().second.second] = 0; // 조건에 맞는 물고기를 먹음
	return pq.top(); // 살아남은 시간, 상어의 좌표를 리턴
}

int survive(int n, ci &shark_loc, vector<vector<int>>& board) {
	int shark_size = 2, cnt = 0, ans = 0;
	board[shark_loc.first][shark_loc.second] = 0;
	while (true) {
		pair<int, ci> target_fish = eatFish(n, shark_size, shark_loc, board);
		if (target_fish.first == -1) { // 엄마 상어에게 도움 요청
			break;
		}
		cnt++; // 먹은 물고기 수 증가
		ans += target_fish.first; // 시간 증가
		if (cnt == shark_size) { // 상어 크기 증가
			cnt = 0;
			shark_size++;
		}
		shark_loc = target_fish.second; // 상어 위치 이동
	}
	return ans;
}

/*
* 1. BFS로 먹을 수 있는 물고기 탐색 (우선순위 큐 사용, a~b 순으로 정렬)
* - a. 거리가 가장 가까운, b. 가장 위에 있는 물고기(y 좌표가 작은 물고기) c. 가장 왼쪽에 있는 물고기(x 좌표가 작은 물고기)
* 2. 물고기를 잡아 먹으며 먹은 물고기 수와 시간
* 3. 먹은 물고기 수가 상어의 크기와 같아지면 상어의 크기 증가
* 먹을 수 있는 물고기가 없을 때까지 1~3을 반복
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
*/

int main()
{
	int n;
	vector<vector<int>> board;
	ci shark_loc;
	// 입력
	cin >> n;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_loc = make_pair(i, j);
			}
		}
	}
	// 연산 & 출력
	cout << survive(n, shark_loc, board) << '\n';
	return 0;
}