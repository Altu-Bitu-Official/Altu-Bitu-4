// 소수상근수
#include <iostream>

using namespace std;

int GCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int a, b;
	cin >> a >> b;
	int gcd = GCD(max(a, b), min(a, b));
	int lcm = a * b / gcd;
	cout << gcd << '\n' << lcm;
}




