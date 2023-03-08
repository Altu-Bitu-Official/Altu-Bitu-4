#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

//소수 여부를 담고 있는 벡터 반환 함수
vector<bool> isPrime() {
	vector<bool> is_prime(MAX + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i] == true) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}

	return is_prime;
}

//짝수의 합을 이루는 두 홀수 소수 중 작은 수를 담고 있는 벡터 반환 함수
vector<int> getGoldbach() {
	vector<int> goldbach(MAX + 1, 0);
	vector<bool> is_prime = isPrime();

	//6부터 MAX까지 모든 짝수에 대하여 탐색
	for (int i = 6; i <= MAX; i += 2) {
		//이미 소수가 저장되어 있으면 건너뜀
		if (goldbach[i] != 0) {
			continue;
		}
		//두 홀수 소수 중 작은 수 p는 3 이상 i/2이하의 홀수
		for (int p = 3; p <= i / 2; p += 2) {
			if (goldbach[p] != 0) {
				continue;
			}
			//p가 홀수면 i-p도 홀수인지 확인 후 맞다면 goldbach[i]에 p 저장
			if (is_prime[p]) {
				if (is_prime[i - p]) {
					goldbach[i] = p;
					break; //break를 통해서 가장 작은 소수가 저장된 이후에 끝나도록 함
				}
			}
		}
	}

	return goldbach;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//연산
	vector<int> result = getGoldbach();

	int n;
	while (true) {
		//입력
		cin >> n;
		if (n == 0) {
			break;
		}

		//출력
		if (result[n] == 0) { //두 홀수 소수의 합으로 n을 나타낼 수 없는 경우
			cout << "goldbach's conjecture is wrong.\n";
		}
		else {
			cout << n << " = " << result[n] << " + " << n - result[n] << "\n";
		}
	}

	return 0;
}