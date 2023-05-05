#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> is_prime;
vector<bool> is_used;
vector<bool> is_visit;
int len_numbers;
int answer = 0;

//소수인지의 여부를 담은 vector 생성
void isPrime(int n) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i] == true) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

void backtracking(string num, string numbers) {
	//종료 조건: 만든 string의 길이가 원래 string의 길이보다 길어지는 경우
	if (num.size() > len_numbers + 1) {
		return;
	}
	
	//소수이면서 아직 확인하지 않은 숫자인 경우
	if (is_prime[stoi(num)] && !is_visit[stoi(num)]) {
		//cout << stoi(num) << "\n";
		is_visit[stoi(num)] = true;
		answer++;
	}

	for (int i = 0; i < len_numbers; i++) {
		if (is_used[i]) {
			continue;
		}

		//사용
		is_used[i] = true;

		//다음 숫자
		backtracking(num + numbers[i], numbers);

		//반납
		is_used[i] = false;
	}
}

int solution(string numbers) {
	sort(numbers.rbegin(), numbers.rend()); //내림차순으로 정렬

	//n: 가능한 수 중 가장 큰 수
	int n = stoi(numbers);
	is_prime.assign(n + 1, true);
	isPrime(n);

	len_numbers = numbers.size();

	is_used.assign(len_numbers, false); //해당 자리의 숫자를 사용했는지 여부
	is_visit.assign(n + 1, false); //만들어진 숫자인지 여부

	backtracking("0", numbers);

    return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string numbers;
	cin >> numbers;

	//연산 & 출력
	cout << solution(numbers);

	return 0;
}