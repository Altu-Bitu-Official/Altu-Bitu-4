
#include <iostream>
using namespace std;

// 유클리드 호제법 사용해서 분자와 분모의 최대 공약수 구한 후
// 분모와 분자를 최대공약수로 나누면 기약분수 만들 수 있음

//재귀 이용하여 최대공약수(gcd) 구하기
int getGcdRecur(int A, int B) {
	if (B == 0) {
		return A;
	}
	return getGcdRecur(B, A % B);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	// 입력
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int n1, n2, n3, n4;

	n1 = a * d + c * b; //분자
	n2 = b * d;  // 분모
	// 최대공약수
	int gcd = getGcdRecur(max(n1, n2), min(n1, n2));
	n3 = n1 / gcd; // 기약분수의 분자
	n4 = n2 / gcd; // 기약분수의 분모

	//출력
	cout << n3 << " " << n4;
	return 0;
}
