#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	//입력
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	//연산
	int result1 = a1 * b2 + a2 * b1; //분자
	int result2 = a2 * b2; //분모
	int gcd_num = gcd(max(result1, result2), min(result1, result2));

	//출력
	cout << result1 / gcd_num << " " << result2 / gcd_num;

	return 0;
}