#include <iostream>
using namespace std;

bool isArithSeq(int hun, int ten, int one) {
	if ((hun - ten) == (ten - one)) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, cnt = 0;

	//입력
	cin >> n;

	if (n < 100) {
		cout << n;
		return 0;
	}
	else {
		cnt += 99;
		for (int i = 100; i <= n; i++) {
			int hun = i / 100;
			int ten = (i % 100) / 10;
			int one = i % 10;

			if (isArithSeq(hun, ten, one)) {
				cnt++;
			}
		}
	}

	//출력
	cout << cnt;
	return 0;
}