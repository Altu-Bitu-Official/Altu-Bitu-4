#include <iostream>
using namespace std;
int gcdIter(int a, int b);
int main() {
	//최대공약수 * a의 서로소약수 * b의 서로소약수=최대공배수
	//1. 최대공약수 구한다.
	//2. A/최대공약수, B/최대공약수, 최대공약수를 곱한다.=최소공배수

	int A, B;
	//입력받기
	cin >> A >> B;

	//최대공약수 구하기
	int gcd=gcdIter(A, B);
	//최소공배수 구하기
	int lcm = (A / gcd) * (B / gcd) * gcd;
	//출력하기
	cout << gcd << "\n" << lcm;
	return 0;
}

int gcdIter(int a, int b) {
	while (b) {//b==0, a가 최대공약수
		a %= b;
		swap(a, b);
	}
	return a;
}
