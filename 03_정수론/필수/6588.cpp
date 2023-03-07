#include <iostream>
#include <vector>
#include <string>//string 함수추가 주의
using namespace std;
void isPrime(int n, vector<bool>& is_prime);
string GoldbachConjecture(vector<bool>& is_prime, int input);

int main() {
	vector<bool> is_prime(100000 + 1, true);
	vector<string> answers;
	isPrime(100000, is_prime);
	int input = 0;
	string input_string;
	while (true) {
		//입력(라인으로받기)
		getline(cin, input_string);//한줄입력받기
		input = stoi(input_string);
		if (input == 0) {
			break;
		}
		//검사&저장
		answers.push_back(GoldbachConjecture(is_prime, input));
	}
	//출력
	//질문: 출력이 이상해요. 왜 그러나요?  return형식이라 두 답이 한꺼번에 나올 리 없는데.. 
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i];
	}
	return 0;
}
string GoldbachConjecture(vector<bool>& is_prime, int input) {	
	string answer;
	for (int i = 0; i <= input; i++) {
		if (is_prime[i] == false) {
			continue;
		}
		for (int j = input; j > 0; j--) {//is_prime[i]가 소수이고
			if (is_prime[j] == true) {//is_prime[j]가 소수이면
				if (i + j == input) {//둘이 더해서 input 되는지 보기
					answer= (input + " = " + to_string(i) + " + " + to_string(j) + "\n");
					return answer;
				}
			}
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