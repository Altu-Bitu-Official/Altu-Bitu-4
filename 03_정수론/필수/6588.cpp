#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

void isPrime(int n, vector<bool>& is_prime) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

bool goldbach(int n, vector<bool>& is_prime, vector<int> &result) {

	for (int i = 3; i <= n/2; i++) {
		if (is_prime[i]) { //a가 홀수 소수이고
			if (is_prime[n - i]) { // b = n-a 도 홀수 소수이면 result에 저장
				result[0] = i;
				result[1] = n - i;
				return true;
			}
		}
	}
	return false; //끝까지 돌렸는데도 return을 하지 못했다면 짝이 없는 것이므로 false
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<bool>is_prime;
	is_prime.assign(MAX + 1, true);
	vector<int>result;
	result.assign(2, 0); // 두 소수를 저장할 벡터

	//미리 홀수 소수 판별 
	isPrime(MAX, is_prime);

	//입력
	while (true) {
		cin >> n;

		if (n == 0) { // 0이면 종료
			break;
		}

		//연산 
		if (goldbach(n, is_prime, result)) {
			cout << n << " = " << result[0] << " + " << result[1]<<"\n";
		}
		else {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}