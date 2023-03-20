#include <iostream>
#include <stack>

using namespace std;

//string으로 입력받은 숫자를 하나씩 stack에 넣어주는 함수
void pushStack(string& n, stack<int>& s) { 
	for (int i = 0; i < n.length(); i++) {
		s.push(n[i] - '0'); //char형을 int형으로 변환
	}
}

//2개의 stack을 합쳐서 하나의 stack으로 만드는 함수
void sumStack(stack<int>& s1, stack<int>& s2, stack<int>& result) {
	int sum_num = 0;
	while (!s1.empty() && !s2.empty()) { //두 stack에 값이 존재하는동안 반복
		sum_num += s1.top() + s2.top(); //가장 위의 두 수 (마지막 자리수부터)
		result.push(sum_num % 10); //10으로 나눈 나머지로 한자리수만 넣어줌
		if (sum_num >= 10) { //만약 10보다 크면 다음 숫자에 1을 더해주고 시작
			sum_num = 1;
		}
		else {
			sum_num = 0;
		}
		s1.pop(); s2.pop(); //더한 숫자 2개 삭제
	}

	while (!s1.empty()) { //s1에 남은 숫자 넣기
		sum_num += s1.top();
		result.push(sum_num % 10);
		if (sum_num >= 10) {
			sum_num = 1;
		}
		else {
			sum_num = 0;
		}
		s1.pop();
	}

	while (!s2.empty()) { //s2에 남은 숫자 넣기
		sum_num += s2.top();
		result.push(sum_num % 10);
		if (sum_num >= 10) {
			sum_num = 1;
		}
		else {
			sum_num = 0;
		}
		s2.pop();
	}

	if (sum_num == 1) { //마지막에 더한 수가 10보다 커서 sum_num이 1인 상태면 따로 넣어주기
		result.push(1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string a, b;
	cin >> a >> b;

	//연산
	stack<int> s1;
	stack<int> s2;
	stack<int> result;

	pushStack(a, s1);
	pushStack(b, s2);
	sumStack(s1, s2, result);

	//출력
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}