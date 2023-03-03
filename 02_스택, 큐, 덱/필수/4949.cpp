#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool cmpBalance(char str[500]) {
	stack<char>s; // 괄호를 넣을 스택
	map<char, char> m;
	m[')'] = '(';
	m[']'] = '[';

	for (int i = 0; str[i] != '.'; i++) { //문장의 끝에 도달할 때 까지 반복
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']') {
			if (!s.empty() && s.top() == m[str[i]]) { // 닫히는 괄호의 경우, 스택이 비어 있지 않고, top의 짝이 맞으면 pop
				s.pop();
			}
			else {
				return false; //아니면 균형이 맞지 않음 
			}
		}
	}

	return s.empty(); // 최종 연산 후 스택이 비어있다면 균형이 잡힌 것
}


int main()
{
	char str[500]; // 줄 입력 받을 문자 - 100자 이상이므로 101자보다 크게 설정 


	while (true) {
		cin.getline(str, 501); // 한 줄 입력 받기
		if (str[0] == '.') { // '.'이 들어오면 프로그램 종료
			break;
		}

		//연산 및 출력
		if (cmpBalance(str)) {
			cout << "yes";
		}
		else {
			cout << "no";
		}

	}

	return 0;


}