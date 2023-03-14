#include <iostream>

using namespace std;

// 한수인지 검사하는 함수
bool check(int num) {
	int a = num / 100;
	int b = (num - a * 100) / 10;
	int c = (num - a * 100 - b * 10);

	return (a - b == b - c);
}

int main() {
	int n, cnt=99;

	// 입력
	cin >> n;

	// 연산 및 출력
	if (n < 100) {
		cout << n << '\n';
	}

	else if (n < 1000) {
		for (int i = 100; i <= n; i++) {
			if (check(i)) {
				cnt += 1;
			}
		}
		cout << cnt << '\n';
	}
	
	else {
		for (int i = 100; i <= 999; i++) {
			if (check(i)) {
				cnt += 1;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}
