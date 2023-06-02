#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX_X = 1e4 + 1;

typedef pair<int, int> ii;

int finishTime(int n, vector<vector<bool>>& apple, vector<char>& dir) {
	int t = 0; //시간
	
	int r = 1, c = 1; //뱀의 처음 위치 (행, 열)
	int d = 0; //뱀의 처음 방향 (오른쪽)
	
	//4가지 방향: 오른쪽, 아래쪽, 왼쪽, 위쪽
	int dr[4] = { 0,1,0,-1 };
	int dc[4] = { 1,0,-1,0 };

	vector<vector<bool>> snake(n + 1, vector<bool>(n + 1, false)); //뱀의 몸이 있는지의 여부 저장
	snake[1][1] = true;

	deque<ii> position; //뱀의 몸이 있는 위치를 머리(front)부터 꼬리(back)까지 저장
	position.push_front({ 1,1 });

	while (true) {
		t++; //시간 증가

		//1. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		//다음 칸의 위치
		int nr = r + dr[d];
		int nc = c + dc[d];
		
		//2-1. 벽에 부딪히면 게임이 끝난다.
		if (nr < 1 || nr > n || nc < 1 || nc > n) {
			return t;
		}

		//2-2. 자기자신의 몸과 부딪히면 게임이 끝난다.
		if (snake[nr][nc]) {
			return t;
		}
		snake[nr][nc] = true;
		position.push_front({ nr,nc });

		//3-1. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
		if (apple[nr][nc]) {
			apple[nr][nc] = false;
		}
		//3-2. 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.
		else {
			ii tail = position.back();
			snake[tail.first][tail.second] = false;
			position.pop_back();
		}

		//4. 뱀의 방향을 변환한다.
		//왼쪽으로 방향 회전
		if (dir[t] == 'L') {
			d = (d + 3) % 4;
		}
		//오른쪽으로 방향 회전
		else if (dir[t] == 'D') {
			d = (d + 1) % 4;
		}

		r = nr, c = nc;
	}
	
	return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, row, col, l, x;
	char c;

	//입력
	cin >> n >> k;

	vector<vector<bool>> apple(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		apple[row][col] = true;
	}

	cin >> l;
	vector<char> dir(MAX_X, '.');
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		dir[x] = c;
	}

	//연산 & 출력
	cout << finishTime(n, apple, dir);

	return 0;
}