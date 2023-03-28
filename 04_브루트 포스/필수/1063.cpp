
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// R, L, B, T, RT, LT, RB, LB
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, -1, 1, 1, 1, -1, -1};

void chess(int kx, int ky, int sx, int sy, vector<string> moves) {
	
	for (int i = 0; i < moves.size(); i++) {
		string move = moves[i];
		int idx = 0;
		int tmpkx = kx;
		int tmpky = ky;
		int tmpsx = sx;
		int tmpsy = sy;
		if (move == "R") {
			idx = 0;
		}
		else if (move == "L") {
			idx = 1;
		}
		else if (move == "B") {
			idx = 2;
		}
		else if (move == "T") {
			idx = 3;
		}
		else if (move == "RT") {
			idx = 4;
		}
		else if (move == "LT") {
			idx = 5;
		}
		else if (move == "RB") {
			idx = 6;
		}
		else if (move == "LB") {
			idx = 7;
		}

		//킹 옮기기
		tmpkx += dx[idx];
		tmpky += dy[idx];

		//돌 옮기기
		if (tmpkx == tmpsx && tmpky == tmpsy) {
			tmpsx += dx[idx];
			tmpsy += dy[idx];
		}

		//안쪽인지 확인한다
		if ((tmpkx > 0 && tmpkx <= 8) && (tmpky > 0 && tmpky <= 8) && (tmpsx > 0 && tmpsx <= 8) && (tmpsy > 0 && tmpsy <= 8)) {
			kx = tmpkx;
			ky = tmpky;
			sx = tmpsx;
			sy = tmpsy;
		}
		else {
			continue;
		}
	}
	kx += 'A' - 1;
	sx += 'A' - 1;
	// 어떻게 하면 입출력을 메인에서 할 수 있을지 잘 모르겠습니다.
	printf("%c%d\n", kx, ky);
	printf("%c%d\n", sx, sy);
	return;
}

int main() {
	int kx, ky, sx, sy;

	string king;
	cin >> king;
	kx = king[0] - 'A' + 1;
	ky = king[1] - '0';

	string stone;
	cin >> stone;
	sx = stone[0] - 'A' + 1;
	sy = stone[1] - '0';

	int cnt;
	cin >> cnt;

	vector<string> moves;

	for (int i = 0; i < cnt; i++) {
		string str; cin >> str;
		moves.push_back(str);
	}

	chess(kx, ky, sx, sy, moves);

	return 0;
}