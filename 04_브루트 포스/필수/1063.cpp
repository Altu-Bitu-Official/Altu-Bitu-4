#include <iostream>
#include <vector>
using namespace std;
//R, L, B, T, RT, LT, RB, LB 순서
int dx[8] = { 0, 0, +1, -1, -1, -1, +1, +1 };
int dy[8] = { +1, -1, 0, 0, +1, -1, +1, -1 };

/*
주의 사항 1. 킹이 좌표 내에 있는지
주의 사항 2. 그 위치가 돌의 위치인지 체크할 것
*/

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

    //첫번째 줄 입력
	int kx, ky, sx, sy, n;
	string king, stone;
	cin >> king >> stone >> n;
	ky = king[0] - 'A'; //열은 A~H 계산
	sy = stone[0] - 'A';
	kx = '8' - king[1]; //행은 8~1로 바꿔 계산
	sx = '8' - stone[1];

	//이동시키기
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int j = 0;
		if (str == "R") {
		}
		else if (str == "L") {
			j = 1;
		}
		else if (str == "B") {
			j = 2;
		}
		else if (str == "T") {
			j = 3;
		}
		else if (str == "RT") {
			j = 4;
		}
		else if (str == "LT") {
			j = 5;
		}
		else if (str == "RB") {
			j = 6;
		}
		else {
			j = 7;
		}
		int kmx = kx + dx[j];
		int kmy = ky + dy[j];

		//주의사항 1. 건너뛰기
		if (kmx < 0 || kmx > 7 || kmy < 0 || kmy > 7) {
			continue;
		}
		//주의사항 2. 돌의 위치
		if (sx == kmx && sy == kmy) {
			int smx = sx + dx[j];
			int smy = sy + dy[j];
			if (smx < 0 || smx >7 || smy < 0 || smy > 7) {
				//돌이 좌표 밖으로 나간다면 건너뛰기
				continue;
			}
			else {
				sx = smx; sy = smy; //돌 위치 변경
			}
		}
		//주의사항을 벗어났다면 king 옮기기
		kx = kmx; ky = kmy;
	}
	//출력
	cout << (char)(ky + 'A') << 8 - kx << endl;
	cout << (char)(sy + 'A') << 8 - sx << endl;

    return 0;
}