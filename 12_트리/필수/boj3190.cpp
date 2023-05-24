#include<iostream>
#include<vector> 
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;
int game(int n, vector<vector<int>>& state, map<int, int>& direction) {
	int dx[4] = { 0, 1, 0, -1 }; //동, 남, 서, 북
	int dy[4] = { 1, 0, -1, 0 };

	int time = 0; //게임시간
	int dir = 0; //뱀의 방향
	int x, y, nx, ny;

	deque<ci> snake; //뱀의 위치
	snake.push_front({ 1, 1 }); //뱀의 시작 좌표 추가
	state[1][1] = 2; //(1,1)에 뱀 처음 위치 설정

	while (true) {
		//뱀의 현재 머리 좌표
		x = snake.front().first; //x좌표
		y = snake.front().second; //y좌표

		if (direction[time] != 0) { // 뱀의 방향 변환 정보가 있으면
			dir = (dir + direction[time]) % 4; // 뱀의 방향 갱신
		}
		time++; // 게임 시간 1초 추가

		//뱀의 머리의 다음 좌표
		nx = x + dx[dir];//x좌표
		ny = y + dy[dir];//y좌표

		//뱀의 머리가 벽에 부딧히거나(주어진 칸 범위 초과하여 이동) 자기 자신의 몸과 부딪히면 게임 종료
		if (!(0 < nx && nx <= n) || !(0 < ny && ny <= n) || state[nx][ny] == 2) {
			break;
		}
		//state에 사과가 존재하면 해당 위치를 1, 뱀이 존재하면 2, 아무것도 없으면 0으로 설정
		//1.뱀의 머리 좌표 추가
		snake.push_front({ nx, ny }); //기존의 뱀의 길이가 2였다면 현재는 3
		//2.새로 이동한 좌표에 사과가 없으면 꼬리 위치 비워주기
		if (state[nx][ny] != 1) { //새로 이동한 좌표에 사과가 없으면
			state[snake.back().first][snake.back().second] = 0; //꼬리 위치는 지나간 위치이며 이제 뱀도 없어질 위치
			snake.pop_back(); //꼬리마지막 칸 삭제 (뱀 길이 다시 2로 복귀)
		}
		state[nx][ny] = 2; //머리가 새로 이동한 위치는 이제 뱀이 조존재하는 칸이므로 state를 2로 변경
	}
	return time; //게임 종료 시점의 time return
}

int main() {
	int n, k, l, x; //
	char c;

	vector<vector<int>> state; //좌표의 사과 존재여부 저장 위치 설정
	map<int, int> direction; //방향 좌표 저장 위치 설정

	//입력
	cin >> n >> k; //보드 크기, 사과갯수 입력
	state.assign(n + 1, vector<int>(n + 1, 0));
	while (k--) { //k개의
		int a, b; 
		cin >> a >> b; //사과 위치 입력
		state[a][b] = 1; //사과 위치 표시
	}

	cin >> l; //이동변화 횟수 입력
	while (l--) { //l번의
		cin >> x >> c; //시간과 방향 입력
		if (c == 'D') { 
			direction[x] = 1;//시계방향으로 회전
		}
		else {
			direction[x] = 3;//반시계방향
		}
	}
	//연산
	int time = game(n, state, direction);
	//출력
	cout << time; //게임 종료시간 출력
	return 0; //코드 종료
}