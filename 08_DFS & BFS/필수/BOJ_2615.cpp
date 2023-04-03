#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 19
using namespace std;
bool vstd[20][20][4];
int d[][2] = { {0,1},{1,1},{1,0},{1,-1} };//torbjorn.tistory.com/230 에서 고려해야 할 이동 방향 4가지를 참고했습니다.
vector<pair<int, int>> p;
int v[20][20];


bool rangeCheck(int y, int x) {
	if (y < 0 || y >= N || x<0 || x>=N) {
		return false;
	}
	else {
		return true;
	}
}
bool cmp(pair<int, int> q, pair<int, int> r) {
	if (q.second >= r.second) {
		if (q.second == r.second) {
			if (q.first > r.first) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}
int dfs(int ny, int nx, int dir, int w, int cnt) {
	vstd[ny][nx][dir] = true;
	p.push_back(make_pair(ny, nx));

	int next_y = ny + d[dir][0];
	int next_x = nx + d[dir][1];
	if (!rangeCheck(next_y, next_x) || v[next_y][next_x] != w) {
		return cnt;
	}
	return dfs(next_y, next_x, dir, w, cnt + 1);
}
int main() {
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int w = v[i][j];
			if (v[i][j] !=0) {//돌이 존재하면
				for (int a = 0; a < 4; a++) {
					int y = i + d[a][0];
					int x = j + d[a][1];
					if (!rangeCheck(y,x)) {
						continue;
					}
					if (v[y][x] == w && !vstd[i][j][a]) {//기존에 큐를 이용하여 순서쌍들을 저장하는 방법을 택하고 처음 값들을 넣는 과정에서 자연스럽게 순서쌍이 정렬되게 하려 했지만 자꾸 틀리다는 결과가 나와 jangcenter.tistory.com/49 를 참고하여 벡터pair를 사용하는 방법으로 바꾸었습니다.
						p.clear();
						vstd[i][j][a] = true;
						p.push_back(make_pair(i, j));
						if (dfs(y, x, a, v[i][j], 2) == 5) {
							sort(p.begin(), p.end(), cmp);
							cout << v[i][j] << "\n";
							cout << (p[0].first)+1 << " " << (p[0].second)+1;
							return 0;
						}
					}
				}
			}
			
		}
	}
	cout << 0;
	return 0;
}