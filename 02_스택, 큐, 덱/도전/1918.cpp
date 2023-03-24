#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main()
{
	char str[500]; // 문자열 받을 배열
	stack<char>s;

	//각 기호에 대한 우선순위 매핑
	map<char, int> m;
	m['('] = m[')'] = 0;
	m['*'] = m['/'] = 1;
	m['+'] = m['-'] = 2;


	//입력
	cin.getline(str, 501);

	for (int i = 0; str[i] != '\0'; i++) { //문장의 끝에 도달할 때까지 반복
		if (str[i] == '(' || str[i] == ')' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
			//기호라면

			if (s.empty()|| m[s.top()] > m[str[i]]) {
				//스택이 비어있거나 우선순위가 높은 애들이 들어올 경우
				if (str[i] != ')') { //닫힌 괄호가 아닌 경우만 삽입
					s.push(str[i]);
				}
				else {
					//닫힌 괄호라면 ( 만날때 까지 출력
					while (s.top() != '(') {
						cout << s.top();
						s.pop();
					}
					s.pop(); // ( 도 제거
				}
			}
			else {
				//스택이 비어있지 않고 우선순위가 같거나 낮은 애들이 들어올 경우
				
				if (str[i] == ')') { // 닫힌 괄호일 경우 무조건 우선순위가 같은 ( 일 수 밖에 없으므로 
					s.pop(); // ( 제거
				}
				else {
					//닫힌 괄호가 아닐 경우 우선순위가 스택의 top 원소보다 높아지거나 스택이 빌 때까지 출력
					while (!s.empty() && (m[s.top()] <= m[str[i]])) {
						if (s.top() == '(') { // ( 그냥 무시 
							break;
						}
						cout << s.top();
						s.pop();
					}
					s.push(str[i]); // 새로 들어온 기호 스택에 삽입
				}
			}
		}
		else { //문자라면 그냥 출력
			cout<<str[i];
		}
	}

	while (!s.empty()) { // 스택에 남아있는 기호 출력
		cout << s.top();
		s.pop();
	}
	return 0;

}