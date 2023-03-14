#include <iostream>
using namespace std;

struct fraction {
	int a;
	int b;
};

int gcdIter(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

fraction addFraction(fraction f1, fraction f2) {
	fraction f;
	f.a = f1.a * f2.b + f2.a * f1.b;
	f.b = f1.b * f2.b;
	int gcd = gcdIter(f.a, f.b);
	f.a /= gcd;
	f.b /= gcd;
	return f;
}

int main() {
	fraction f1, f2, f;

	//입력
	cin >> f1.a >> f1.b;
	cin >> f2.a >> f2.b;

	//연산
	f = addFraction(f1, f2);

	//출력
	cout << f.a << " " << f.b;
	return 0;
}