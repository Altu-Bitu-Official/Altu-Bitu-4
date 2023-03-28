#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000000

vector<bool>is_prime(MAX + 1, true);
// 에라토스테네스의 체
void isPrime(int n, vector<bool>& is_prime) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

void goldbach(int n) {
	for (int i = 0; i < n; i++) {
		if (is_prime[i] && is_prime[n - i]) {
			cout << n << " = " << i << " + " << n - i << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	isPrime(MAX, is_prime);
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		goldbach(n);
	}
	return 0;
}