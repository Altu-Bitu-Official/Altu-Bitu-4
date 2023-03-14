#include <iostream>
#include <queue>

using namespace std;

int solution(int num) {
	int cnt = 99; // 100미만의 숫자는 그 자체로 등차수열이다
	for (int i = 100; i <= num; i++) {
		int hun = i / 100;       // 백의 자릿수
		int ten = (i / 10) % 10; // 십의 자릿수
		int one = i % 10;

		if ((hun - ten) == (ten - one)) { // 각 자릿수가 수열을 이루면
			cnt++;
		}
	}
	return cnt;
}

int main() 
{
	int n;
	//입력
	cin >> n;
	//연산 & 출력
	if (n <= 99) {
		cout << n;
	}
	else {
		cout << solution(n);
	}
	return 0;
}