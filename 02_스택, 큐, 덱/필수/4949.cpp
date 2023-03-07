#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string input) { // 괄호가 균형을 이루었는지 여부 반환
    stack<char> s; // 괄호 저장하는 스택

    for(int i = 0; i < input.length(); i++) {
        char ch = input[i];
        switch(ch) {
            case '(': case '[': // 여는 괄호는 무조건 push
                s.push(ch);
                break;
            case ')': // 닫는 소괄호
                if(s.empty() || s.top() != '(') {
                    return false;
                }
                s.pop();
                break;
            case ']': // 닫는 대괄호
                if(s.empty() || s.top() != '[') {
                    return false;
                }
                s.pop();
                break;
        }
    }
    return s.empty();
}

/*
 * [괄호 균형 확인하기]
 * 1. 여는 괄호는 바로 스택에 넣는다.
 * 2. 닫는 괄호가 나오면 가장 최근에 넣었던 여는 괄호와 비교한다.
 * 2-1. 닫는 괄호와 여는 괄호의 종류가 같다면 해당 닫는 괄호가 균형을 이룬다.
 * 2-2. 직전에 나온 여는 괄호가 없거나 그 종류가 다르다면 해당 닫는 괄호가 균형을 이루지 못한다.
 * 3. 모든 닫는 괄호가 여는 괄호와 짝을 이루었더라도 스택에 여는 괄호가 남아있다면 균형을 이루지 못한다.
*/


int main() {
    string input;

    while(true) {
        // 입력
        getline(cin, input);
        if(input == ".") {
            break;
        }

        // 연산 & 출력
        if(isBalanced(input)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}