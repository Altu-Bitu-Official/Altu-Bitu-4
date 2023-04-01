#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char ch) { // 연산자 우선순위 반환
    switch(ch) {
        case '+': case '-': return 2;
        case '*': case '/': return 1;
        case '(': return 0;
    }
}

string postfix(string input) {
    string result = "";
    stack<char> op;

    for(int i = 0; i < input.length(); i++) {
        char curr = input[i];
        switch(curr) {
            case '(':
                op.push(curr);
                break;

            case ')': // 여는 괄호가 나오기 전까지 스택의 연산자 결과에 추가
                while(!op.empty() && op.top() != '(') {
                    result += op.top();
                    op.pop();
                }
                op.pop();
                break;
            
            case '+': case '-': case '*': case '/':
                // 연산자 우선순위 비교
                // curr 연산자를 넣으려면 curr보다 높은 우선순위를 가지는 연산자를 pop해야 함
                while(!op.empty() && priority(curr) >= priority(op.top())) {
                    result += op.top();
                    op.pop();
                }
                op.push(curr); // 현재 연산자 집어넣기
                break;

            default: // 피연산자
                result += curr;
        }
    }
    while(!op.empty()) {
        result += op.top();
        op.pop();
    }
    return result;
}

int main() {
    string input;
    cin >> input;

    cout << postfix(input);
    return 0;
}


