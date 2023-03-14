#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int num = 0;
	const long max = 10000000; //입력 최대값이 10^4일 때 나올 수 있는 최대값은 10^7

	for (int i = 666; i < max; i++) {
		int a = i;
		while (a >= 666) {
			if (a % 1000 == 666) {
				++cnt;
				break;
			}
			else {
				a /= 10;
			}
		}
		if (cnt == n) {
			cout << i;
			break;
		}
	}
}