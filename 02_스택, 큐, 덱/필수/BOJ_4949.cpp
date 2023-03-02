#include <iostream>
#include <string>
#include <stack>

using namespace std;

string check(string& input, stack<char>& s) {
	for (int i = 0; i < input.length(); i++) {
		char w = input[i];
		switch (w) {
			case '(': case '['://왼쪽 괄호는 stack에 넣기
				s.push(w);
				break;
			case ')':
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					return "no";
				}
				break;
			case ']':
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					return "no";
				}
				break;
		}
	}

	if (s.empty()) { //모든 문자를 검사하고 stack이 비어있다면 균형을 이룸
		return "yes";
	}
	return "no";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;

	while (true) {
		//입력
		getline(cin, input);
		stack<char> s;
		if (input == ".") {
			break;
		}

		//연산 & 출력
		cout << check(input, s) << "\n";
	}

	return 0;
}