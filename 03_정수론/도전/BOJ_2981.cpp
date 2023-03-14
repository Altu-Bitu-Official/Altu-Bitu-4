#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//최대공약수 반환 함수
int gcd(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

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

//m인지의 여부를 담은 벡터 반환 함수
set<int> findM(vector<int>& num) {
	//n이 담긴 벡터 num 정렬
	sort(num.begin(), num.end());

	//n들의 차가 담긴 벡터
	vector<int> diff(num.size() - 1);
	for (int i = 0; i < num.size() - 1; i++) {
		diff[i] = num[i + 1] - num[i];
	}

	//diff들의 최대 공약수 구하기
	int gcd_num = diff[0];
	for (int i = 1; i < diff.size(); i++) {
		gcd_num = gcd(gcd_num, diff[i]);
	}

	//m은 gcd_num의 약수
	set<int> m; //insert 과정에서 중복되는 숫자가 있을 수 있으므로 set으로 정의

	//i가 약수이면 gcd_num / i도 약수이므로 sqrt(gcd_num)까지만 실행
	for (int i = 2; i * i <= gcd_num; i++) {
		if (gcd_num % i == 0) {
			m.insert(i);
			m.insert(gcd_num / i);
		}
	}
	m.insert(gcd_num);

	return m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	//연산
	set<int> result = findM(num);

	//출력
	for (auto iter : result) {
		cout << iter << " ";
	}

	return 0;
}