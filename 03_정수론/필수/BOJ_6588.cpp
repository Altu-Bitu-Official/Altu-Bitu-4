#include <iostream>
using namespace std;

const int MAX_NUM = 1000000;
const int MAX_TEST = 100000;

int is_prime[MAX_NUM] = {0};

//에라토스테네스의 체(0,1 제외)
void eratos() {
	//2~제곱근 MAX_NUM까지
	for (int i = 2; i * i <= MAX_NUM; i++) {
		if (is_prime[i] == 0) { //i가 소수라면
			for (int j = i * i; j <= MAX_NUM; j += i) {
				is_prime[j] = 1; //i의 배수를 제거
			}
		}
	}
}

int goldbach(int n) { 
	for (int i = 3; i <= n; i += 2) { //3이상 n이하의 홀수 i에 대해서
		if (is_prime[i] == 0 && is_prime[n - i] == 0) { //i와 n-i가 모두 소수이면
			return i; //그 수를 출력
		}
	}
	return 0; //골드바흐의 추측을 만족하지 않음
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input;
	eratos();

	for(int i=0; i<MAX_TEST; i++) {
		cin >> input;
		if (input == 0) {
			break;
		}
		int div = goldbach(input);
		if (div == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		else {
			cout << input << " = " << div << " + " << input-div << "\n";
		}
	}
	return 0;
}