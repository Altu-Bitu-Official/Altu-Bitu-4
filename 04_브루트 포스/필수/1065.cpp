#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;// 한수의 수 카운트

	for (int i = 1; i <= n; i++) {//범위는 1~1000
		if (i < 100) {
			++cnt; //1~99는 다 한수
		}
		else {//세자리수 일 때
			int one = i % 10;
			int ten =i % 100 / 10;
			int hund = i / 100;

			if ((ten - one) == (hund - ten)) {
				++cnt;
			}
		}
	}
	cout << cnt;
}