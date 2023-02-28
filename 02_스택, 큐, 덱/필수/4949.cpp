#include <iostream>
#include <stack>

using namespace std;


int main()
{
	char str[500]; // 줄 입력 받을 문자 - 100자 이상이므로 101자보다 크게 설정 
	stack<char>s; // 괄호를 넣을 스택

	while (true) {
		cin.getline(str, 501); // 한 줄 입력 받기
		if (str[0] == '.') { // '.'이 들어오면 프로그램 종료
			break;
		}

		for (int i = 0; str[i] != '.'; i++) { //문장의 끝에 도달할 때 까지 반복
			switch (str[i])
			{
			case '(':
			case '[':
				s.push(str[i]); // 열린 괄호는 스택에 넣기
				break;
			case ')':
				if (!s.empty() && s.top() == '(') { // 닫히는 괄호의 경우, 스택이 비어 있지 않고, top의 짝이 맞으면 pop
					s.pop();
				}
				else {
					s.push(str[i]); // 그렇지 않으면 그냥 stack에 push
				}
				break;
			case ']':
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
				break;
			default:
				break;
			}
		}

		if (s.empty()) { // 최종 연산 후 스택이 비어있다면 균형이 잡힌 것
			cout << "yes\n";
		}
		else {
			cout << "no\n";
			}

		while (!s.empty()) { //다음 줄의 연산을 위해 스택을 비워줌.
			s.pop();
		}
	}

	return 0;


}