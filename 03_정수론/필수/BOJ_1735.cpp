#include <iostream>
#include <algorithm>

using namespace std;

// 최대공약수 구하는 함수
int getGcd(int a, int b) {
	if (b==0) {
		return a;
	}
	return getGcd(b, a%b);
}

int main() {
	// 입력
	int a1, a2, b1, b2, c1, c2, GCD;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	
	// 덧셈 연산
	c1 = a1 * b2 + b1 * a2;
	c2 = a2 * b2;

	// 기약분수인지 확인
	GCD = getGcd(max(c1, c2), min(c1, c2));
	
	if (GCD == 1) {
		cout << c1 << " " << c2;
	}
	else {
		cout << c1 / GCD << " " << c2 / GCD;
	}

	return 0;
}