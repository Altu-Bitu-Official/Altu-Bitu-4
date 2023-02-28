#include <iostream>
#include <string>
#include <stack>

using namespace std;

string check(string& input, stack<char>& s) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' || input[i] == '[') { //왼쪽 괄호는 stack에 넣기
			s.push(input[i]);
		}
		else if (input[i] == ')') { //오른쪽 괄호인 경우
			if (s.empty()) { //stack이 비어있지 검사
				return "no";
			}
			else {
				if (s.top() == '(') { //가장 마지막의 왼쪽 괄호랑 짝이 맞는지 비교
					s.pop(); //맞다면 왼쪽 괄호도 같이 없애기
				}
				else {
					return "no";
				}
			}
		}
		else if (input[i] == ']') {
			if (s.empty()) {
				return "no";
			}
			else {
				if (s.top() == '[') {
					s.pop();
				}
				else {
					return "no";
				}
			}
		}
	}

	if (s.empty()) { //모든 문자를 검사하고 stack이 비어있다면 균형을 이룸
		return "yes";
	}
	else {
		return "no";
	}
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