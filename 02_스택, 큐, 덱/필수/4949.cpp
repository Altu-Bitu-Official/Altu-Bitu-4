#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
void removeStack(stack<char> *s) {
	
	while (true) {
		if ((*s).empty())
			break;
		(*s).pop();
	}
	
}

int main() {
	stack<char> s;
	string input;
	string answer="";
	/*int debug=0;
	int debug2 = 0;*/
	while (true) {
		removeStack(&s);
		getline(cin, input); /*debug++;*/
		//종료조건
		if (input==".")
			break;
		
		for (int i = 0; i < input.length(); i++) {			
			//디버그
			//if (debug == 6) {
			//	debug2++;//여기
			//}
			//왼쪽 괄호 만나면 푸시
			if (input.at(i) == '(' || input.at(i) == '[') {
				s.push(input.at(i));
				continue;
			}
			//오른쪽 만나면, 탑이 짝인지 본다
			//string, index, char, &s 
			if (input.at(i) == ']') {
				//엠티인지 먼저확인!!!!!
				if (!s.empty()&& s.top() == '[') {
					s.pop(); continue;	
				}
				else {
					answer += "no\n"; 
					break;
				}					
			}
			if (input.at(i) == ')') {
				//엠티인지 먼저확인!!!!!
				if (!s.empty() && s.top() == '(') {
					s.pop(); continue;
				}					
				else {
					answer += "no\n";		
					break;
				}					
			}
			
			//끝일때
			if (i == input.length() - 1) {
				// 스택 비었음=짝맞음, 안 비었음=>짝 안 맞음
				if (s.empty()) {
					answer += "yes\n";
				}
				else {
					answer += "no\n";
					//스택 비운다. 
					removeStack(&s);
				}
			}
		}
	}
	
	std::cout << answer;

	return 0;
}