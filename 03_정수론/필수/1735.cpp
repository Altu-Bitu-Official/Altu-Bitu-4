#include <iostream>
#include <vector>

using namespace std;

// 최대공약수 구하기
int getGCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	int a1, a2, b1, b2;
	cin >> a1 >> b1;
	cin >> a2 >> b2;
	// b1, b2의 최소공배수 구하기
	int b = b1 * b2 / getGCD(b1, b2);
	int a = a1 * (b / b1) + a2 * (b / b2);
	int n = getGCD(a, b);
	cout << a / n << " " << b / n;
	return 0;
}
