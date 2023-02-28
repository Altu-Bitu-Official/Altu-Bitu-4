#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int len, i;
    string str;
    stack<char> stack;
    while (1) {
        getline(cin, str);
        if (str[0] == '.') {
            return 0;
        } //.이면 프로그램 종료

        len = str.length();
        for (i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[') {
                stack.push(str[i]);
            }
            else if (str[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                } else {
                    cout << "no" << '\n';
                    break; // ) 전이 (이 아니면 바로 반복 종료, 불균형 판정
                }
            }
            else if (str[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                } else {
                    cout << "no" << '\n';
                    break; // ) 전이 (이 아니면 바로 반복 종료, 불균형 판정
                }
            }
        }
        if (i == len) { //중간에 멈추지 않고 반복이 끝까지 돌아갔을 때
            if (stack.empty()) {
                cout << "yes" << '\n';
            } else {
                cout << "no" << '\n';
            }
        }
        while (!stack.empty()) {
            stack.pop();
        }
    }
}