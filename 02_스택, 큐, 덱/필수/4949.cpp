#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isPair(string input) {
	bool is_pair=true;
	stack<char> s;

	for (int i = 0; i < input.length(); i++) {
		//왼쪽 괄호 만나면 푸시
		if (input[i] == '(' || input[i] == '[') {
			s.push(input[i]);
			continue;
		}
		//오른쪽 만나면, 탑이 짝인지 본다
		if (input[i] == ']') {
			//엠티인지 먼저확인!!!!!
			if (!s.empty() && s.top() == '[') {
				s.pop(); continue;
			}
			else {
				is_pair = false;
				break;
			}
		}
		if (input[i] == ')') {
			//엠티인지 먼저확인!!!!!
			if (!s.empty() && s.top() == '(') {
				s.pop(); continue;
			}
			else {
				is_pair = false;
				break;
			}
		}
	}
	//끝일때 한꺼번에 출력
	//스택 비었음=짝맞음, 안 비었음=>짝 안 맞음
	//스택 비었을 때도 false인 경우가 있다. 초기값을 true 로 주어서
	//false로 바뀌었는지 확인하자. 
	if (s.empty()&&is_pair!=false) {
		is_pair = true;
	}
	else {
		is_pair = false;
	}
	return is_pair;
}

int main() {
	string input;
	string answer = "";
	while (true) {
		//입력
		getline(cin, input);//한줄입력받기
		//종료조건
		if (input == ".")
			break;
		//계산&출력
		if (isPair(input) == true) answer += "yes\n";
		else answer += "no\n";
	}
	cout << answer;
	return 0;
}