#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, b;
	int map[500][500];
	int min_time = 0x7f7f7f7f;
	int max_height = 0;

	//입력
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//연산
	for (int h = 0; h <= 256; h++) {
		int add = 0, sub = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int height = map[i][j] - h;
				if (height > 0) { //지워야 할 블록
					sub += height;
				}
				else if (height < 0) { //채워야 할 블록
					add -= height;
				}
			}
		}
		if (sub + b >= add) { //가지고 있는 블록이 필요한 블록보다 많다면
			int time = sub * 2 + add; //시간 계산
			if (min_time >= time) {
				min_time = time;
				max_height = h; //h 갱신
			}
		}
	}

	//출력
	cout << min_time << ' ' << max_height;
	return 0;
}