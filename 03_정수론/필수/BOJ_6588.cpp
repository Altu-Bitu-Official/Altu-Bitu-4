#include <iostream>
#include <vector>

const int MAX = 1000000;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	// 소수라면 1 (true), 소수가 아니라면 0 (false)
	vector <int> primes (MAX+1, 1); // 소수 여부 저장

	// 에라토스테네스의 체 사용
	primes[0] = primes[1] = 0; // 0과 1은 소수 아님
	for (int i = 3; i * i < MAX; i=i+2) { // 홀수만 확인
		if (primes[i]) { // i가 소수라면 
			for (int j = i * i; j < MAX; j += i) { // i의 배수 제거
				primes[j] = 0; 
			}
		}
	}
	while (true) { 
		int n;
		// 입력
		cin >> n;
		if (n==0) break; // 0 입력 시 종료

		for (int i = 3; i <n; i += 2) {
			// i와 n-i 모두 소수인 경우에 출력
			if (primes[i]==1 && primes[n-i]==1) { 
				cout << n << " = " << i << " + " << n-i << '\n';
				break;
			}
		}
	}
	return 0;
}
