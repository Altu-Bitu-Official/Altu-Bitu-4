#include <iostream>
#include <vector>
#include <cmath>
#include <string>//string 함수추가 주의
using namespace std;
void isPrime(int n, vector<bool>& is_prime);
string GoldbachConjecture(vector<bool>& is_prime, int input);

int main() {
	//입출력 속도 향상
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> is_prime(1000000 + 1, true);
	vector<string> answers;
	isPrime(1000000, is_prime);
	int input = 0;
	while (true) {
		//입력(라인으로받기)
		cin >> input;
		if (input == 0) {
			break;
		}
		//검사&저장
		answers.push_back(GoldbachConjecture(is_prime, input));
	}
	//출력
	//질문: 출력이 이상해요. 왜 그러나요?  return형식이라 두 답이 한꺼번에 나올 리 없는데..
    //->  c++에서는 정수+string 형태로 출력이 불가능해서 일어난 문제 같습니다! 
	for (long unsigned int i = 0; i < answers.size(); i++) {
		cout << answers[i];
	}
	return 0;

}

string GoldbachConjecture(vector<bool>& is_prime, int n) {
	for (int i = 3; i <= (n / 2); i += 2) {
		if (is_prime[i] && is_prime[n - i]) {
			return to_string(n) + " = " + to_string(i) + " + " + to_string(n - i) + "\n";
		}
	}
	return "Goldbach's conjecture is wrong.\n";
}

void isPrime(int n, vector<bool>& is_prime) {
	//0과 1은 소수가 아니므로 먼저 제거
	is_prime[0] = is_prime[1] = false;
	//2~제곱근 n까지 검사
	for (int i = 2; i <= sqrt(n); i++) {//제곱: 제곱부터 지워지게 되어있음(이전소수배수에서 이미 지워서 제곱부터 시작하게됨), j+=i: 배수를 나타냄
		if (is_prime[i]) {//i가 소수라면
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;//i의 배수를 제거
			}
		}
	}
}