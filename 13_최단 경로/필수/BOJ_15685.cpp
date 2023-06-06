#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 101;

//0: x 증가, 1: y 감소, 2: x 감소, 3: y 증가
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void makeDragon(vector<int>& dragon, vector<vector<int>>& board) {
	int x = dragon[0], y = dragon[1], d = dragon[2], g = dragon[3];

	vector<int> dir;
	dir.push_back(d); //0세대 방향

	//1세대부터 방향 추가
	for (int i = 0; i < g; i++) {
		for (int j = pow(2, i) - 1; j >= 0; j--) {
			dir.push_back((dir[j] + 1) % 4);
		}
	}
	
	board[x][y] = 1; //시작 지점 표시
	for (int i = 0; i < dir.size(); i++) {
		int nd = dir[i]; //다음 방향
		int nx = x + dx[nd];
		int ny = y + dy[nd];

		board[nx][ny] = 1;
		x = nx, y = ny;
	}
}

int cntSqaure(int n, vector<vector<int>>& dragon) {
	vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

	//드래곤 커브 그리기
	for (int i = 0; i < n; i++) {
		makeDragon(dragon[i], board);
	}

	int cnt = 0;
	for (int x = 0; x < SIZE - 1; x++) {
		for (int y = 0; y < SIZE - 1; y++) {
			//네 꼭짓점이 모두 드래곤 커브의 일부인 경우 횟수 증가
			if (board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x, y, d, g;
	cin >> n;

	vector<vector<int>> dragon(n, vector<int>(4)); //dragon[i]: {x, y, d, g}
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		dragon[i] = { x,y,d,g };
	}

	//연산 & 출력
	cout << cntSqaure(n, dragon);

	return 0;
}