#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//소수 여부를 담고 있는 벡터 반환 함수
vector<bool> isPrime(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i] == true) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	return is_prime;
}

//상근수인지 판단하는 함수
bool isSangeun(int n) {
	queue<int> q;
	int iter_num = 10;

	while (iter_num--) {
		int num_digits = 0, digits = 1; //자릿수 계산
		while (n / digits != 0) {
			digits *= 10;
			num_digits++;
		}

		vector<int> num; //각 자리수를 담은 벡터
		while (num_digits--) {
			digits /= 10;
			num.push_back(n / digits);
			n = n % digits;
		}

		int sum_num = 0; //각 자리수의 제곱의 합
		for (int i = 0; i < num.size(); i++) {
			sum_num += pow(num[i], 2);
		}

		//1인 경우 n은 상근수
		if (sum_num == 1) {
			return true;
			break;
		}

		//1이 나오지 않고 반복되기 시작한다면 n은 상근수 아님
		if (!q.empty() && sum_num == q.front()) {
			return false;
			break;
		}

		//반복여부를 확인하기 위하여 큐에 넣기
		q.push(sum_num);

		n = sum_num; //n을 새로 구한 수로 바꾸기
	}

	return false;
}

//소수상근수 여부를 담고 있는 벡터 반환 함수
vector<bool> find(int n) {
	vector<bool> is_prime = isPrime(n);
	vector<bool> num(n + 1, false);

	for (int i = 2; i <= n; i++) {
		//소수면서 상근수인 경우
		if (is_prime[i] && isSangeun(i)) {
			num[i] = true;
		}
	}

	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산
	vector<bool> result = find(n);

	//출력
	for (int i = 2; i <= n; i++) {
		if (result[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}