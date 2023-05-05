#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 균형 잡힌 문자열인지 검사하는 함수
bool checkBalance(string str, stack<char> &s) {

	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '[': case '(':
			s.push(str[i]);
			break;

		case ']':
			if (s.empty() || s.top() != '[') {
				return false;				
			}
			s.pop();
			break;

		case ')':
			if (s.empty() || s.top() != '(') {
				return false;				
			}
			s.pop();
			break;
		}
	}
	
	if (s.empty()) {
		return true;
	}
	else return false;
}

int main() {

	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	stack<char> s;
	
	while (1) {	// 입력 종료 조건 들어오기 전까지 무한 반복
		// 입력
		getline(cin, str);

		if (!str.compare(".")) {	// 입력 종료 조건
			break;
		}
		
		// 연산 및 출력
		if (checkBalance(str, s)) {
			cout << "yes" << '\n';
		}
		else cout << "no" << '\n'; 

		while (!s.empty()) s.pop();	// 새 문자열 입력받기 전에 스택 비우기
	}
	
	return 0;
}