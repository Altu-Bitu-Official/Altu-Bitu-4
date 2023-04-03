#include <iostream>
#include <vector>
using namespace std;
int d[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
void dfs(int w, int h, int i, int j,vector<vector<int>> &map, vector<vector<int>> &vstd) {
	for (int n = 0; n < 8; n++) {
		int nx, ny;
		nx = i + d[n][0];
		ny = j + d[n][1];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (vstd[nx][ny] == false && map[nx][ny]) {
				vstd[nx][ny] = true;
				dfs(w,h,nx, ny,map,vstd);
			}
		}
	}
}
int main() {
	while (true) {
		vector<vector<int>> map;
		map.assign(50, vector<int>(50, 0));
		vector<vector<int>> vstd;
		vstd.assign(50, vector<int>(50, 0));
		int w, h;//너비와 높이.
		int count = 0;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];//w가 가로 h가 세로이므로 반대다
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (vstd[i][j] == false && map[i][j]==1) {
					vstd[i][j] = 1;
					dfs(w, h, i, j, map,vstd);
					count++;
				}
			}
		}
		cout << count << "\n";



		
		
	}
	return 0;
}