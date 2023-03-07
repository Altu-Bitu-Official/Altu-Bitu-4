#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBalance (const string& str) {
        int i, len;
        stack<char> stack;
        len = str.length();
        for (i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[') {
                stack.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    return false; // ) 전이 (이 아니면 바로 반복 종료, 불균형 판정
                }
            }
            else if (str[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    return false; // ) 전이 (이 아니면 바로 반복 종료, 불균형 판정
                }
            }
        }
        return stack.empty(); //중간에 멈추지 않고 반복이 끝까지 돌아갔을 때
        
}

int main() {
    int len, i;
    string str;
    while (1) {
        // 문자열 읽어오기
        getline(cin, str);
        if (str[0] == '.') {
            return 0;
        } //.이면 프로그램 종료
        
        // 괄호열 체크하는 함수 호출 후 결과 출력
        cout << (checkBalance(str) ? "yes" : "no") << '\n';
    }
}