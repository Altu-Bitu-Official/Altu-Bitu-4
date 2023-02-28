#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

int rankNum(const char& c) {
	if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '(') {
		return 0;
	}
}

void postfix(string input, stack<char>& s, queue<char>& q) {
	for (int i = 0; i < input.length(); i++) {
		if (isalpha(input[i])) { //알파벳인 경우
			q.push(input[i]);
		}

		else if (input[i] == '(') { //'('는 무조건 삽입
			s.push(input[i]);
		}
		else if (input[i] == ')') {//'('가 나올 때까지 스택에 있는 연산자 큐에 옮기기
			while (s.top() != '(') {
				q.push(s.top());
				s.pop();
			}
			s.pop(); //'(' 제거
		}

		else { //연산자인 경우
			if (s.empty()) { //스택이 비어있으면 삽입
				s.push(input[i]);
			}
			else { //스택이 비어있지 않은 경우
				while (!s.empty()) { //우선순위 고려해서 스택에 있는 연산자 큐에 옮기기
					if (rankNum(input[i]) <= rankNum(s.top())) { //우선순위 비교
						q.push(s.top());
						s.pop();
					}
					else {
						break;
					}
				}
				s.push(input[i]); //현재 연산자 스택에 삽입
			}
		}
	}

	while (!s.empty()) { //스택에 남은 연산자 큐에 삽입
		q.push(s.top());
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string input;
	getline(cin, input);

	//연산
	stack<char> s;
	queue<char> q;
	postfix(input, s, q);
	
	//출력
	while(!q.empty()) {
		cout << q.front();
		q.pop();
	}

	return 0;
}