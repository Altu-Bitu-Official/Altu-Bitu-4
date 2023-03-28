#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[505][505];
	//세로n 가로m 크기의 집터
	//인벤토리에는 b개의 블록 존재
	int n, m, b;
	//첫째 줄에 n, m b 주어진다
	cin >> n >> m >> b;
	int max = 0;
	int min = 257;

	//둘째줄부터 nxm좌표에 (세로n 가로m)땅 높이 출력
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[j][k];
			if (arr[j][k] > max) {
				max = arr[j][k];
			}
			else if (arr[j][k] <= min) {
				min = arr[j][k];
			}
		}
	}
	int min_t = 2147483600;
	int height = 0;
	//블록제거 2초, 블록 쌓기 1초
	//최대한 블록 쌓기가 많은 방법으로 진행
	for (int i = min; i <= max; i++) {//땅의 높이로 경우의 따지기기
		int tmp = b;
		int t = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				//땅 메꾸기
				if (arr[j][k] < i) {
					t += i - arr[j][k];
					tmp -= i - arr[j][k];
				}
				//땅 제거
				else if (arr[j][k] > i) {
					t += (arr[j][k] - i) * 2;
					tmp += arr[j][k] - i;
				}
				else {
					continue;
				}
			}
		}
		if (tmp >= 0) {
			if (t <= min_t) {
				min_t = t;
				height = i;
			}
		}
	}
	cout << min_t << " " << height;
}