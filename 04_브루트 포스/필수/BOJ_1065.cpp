#include <iostream>
#include <vector>
using namespace std;

// N보다 작은 한수의 개수 출력 (N<=1000)
// 세 자리수까지만 보면 된다

int hansoo(int n) {
	int cnt = 0;
	int a, b, c;
	if (n < 100) cout<< n; // 한 자리수, 두 자리수는 모두 한수 

	else { // 세 자리수인 경우
		for (int i = 100; i <=n; i++) {
			a = i / 100;
			b = (i % 100) / 10;
			c = i % 10;

			if ((b - a) == (c - b)) cnt ++;
		}
		cout<< 99 + cnt;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int N;
	cin >> N;
	hansoo(N);
	return 0;
}