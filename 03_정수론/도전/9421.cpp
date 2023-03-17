#include <iostream>
#include <vector>
#include <set>

using namespace std;

void isPrime(int n, vector<bool>& is_prime){
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

void isSanggeun(int n, vector<bool>& is_prime) {
	is_prime[2] = is_prime[3] = is_prime[5] = false; // 초반 상근수가 아닌 것들 지우기

	for (int i = 7; i <= n; i++) {
		if (is_prime[i]) { //소수이면 상근수인지 확인
			set <int> s; //상근수 계산결과를 저장할 set
			int num = i; //계산할 값
			while (true) {
				int sum = 0; //계산 결과
				while (true) { // 한 자릿수씩 계산해서 더하기 
					//cout << num << "\n";
					sum += ((num % 10) * (num % 10));
					if (num >= 10) {
						num /= 10;
					}
					else {
						break;
					}
				}

				//sum의 결과로 소수 상근수인지 판단
				if (s.find(sum) != s.end()) { // 이미 한 번 계산한 결과라면 
					is_prime[i] = false;
					break;
				}
				else if (sum == 1) { //소수상근수
					break;
				}
				else { //계속 계산
					s.insert(sum);
					num = sum; //num 갱신
				}
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<bool>is_prime;

	//입력
	cin >> n;

	//연산
	//미리 n까지의 소수 구하기
	is_prime.assign(n + 1, true);
	isPrime(n, is_prime);
	//n까지의 소수 상근수 구하기
	isSanggeun(n, is_prime);

	//출력
	for (int i = 7; i <= n; i++) {
		if (is_prime[i]) {
			cout << i << "\n";
		}
	}
	

}