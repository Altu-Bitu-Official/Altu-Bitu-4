#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) { // 연산자 우선순위 반환
    switch(ch) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2; // 연산자 순위 가장 높음 (먼저 계산되어야 함)
    }
}

string postfix(string input) { // 중위 표기식 -> 후위 표기식
    string result = ""; // 후위 표기식
    stack<char> op; // 연산자 저장하는 스택

    for(int i = 0; i < input.size(); i++) {
        char ch = input[i];
        switch(ch) {
            // 여는 괄호는 무조건 push
            case '(':
                op.push(ch);
                break;

            // 닫는 괄호는 여는 괄호를 만날 때까지 pop
            case ')':
                while(!op.empty() && op.top() != '(') {
                    result += op.top();
                    op.pop();
                }
                op.pop(); // 여는 괄호 제거
                break;

            // 연산자의 경우, 스택에 들어있는 연산자와 우선순위 비교
            case '+': case '-': case '*': case '/':
                // 스택에 현재 연산자보다 우선순위가 높은 (=먼저 계산되어야 하는) 연산자가 있는 경우 pop
                while(!op.empty() && priority(op.top()) >= priority(ch)) {
                    result += op.top();
                    op.pop();
                }
                op.push(ch); // 현재 연산자 push
                break;

            // 피연산자는 바로 결과에 추가
            default:
                result += ch;
        }
    }

    // 스택에 남아있는 연산자 결과에 추가
    while(!op.empty()) {
        result += op.top();
        op.pop();
    }
    return result;
}

/*
 * [중위 표기식 -> 후위 표기식]
 * 1. 피연산자는 순서가 변하지 않으므로 바로 결과에 추가한다.
 * 2. 연산자는 우선순위에 따라 순서가 변하므로 스택에 잠시 저장한다.
 * 3. 스택의 top에 있는 연산자는 우선순위가 제일 높아야 한다.
 * 4. 스택의 top에 있는 연산자가 현재 연산자보다 우선순위가 같거나 높으면 스택에서 값을 꺼내야 한다.
 * 5. 여는 괄호는 무조건 스택에 넣는다.
 * 6. 닫는 괄호가 들어오면 여는 괄호가 나올 때까지 스택에 있는 연산자를 결과에 추가한다.
*/

int main() {
    string input; // 입력값 (중위 표기식)

    // 입력
    cin >> input;

    // 연산 & 출력
    cout << postfix(input);
    return 0;
}