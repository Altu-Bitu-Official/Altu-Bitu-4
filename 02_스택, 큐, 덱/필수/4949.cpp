#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBracket(string str) {
    stack<int> st;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '[' || c == '(') {   // 여는 괄호면 스택에 저장
                st.push(c);
        }
        else if (c == ']') {  // 닫는 괄호면 스택에서 요소 제거
            if (st.empty() || st.top() != '[') { // 만약 스택이 비어 있거나 괄호가 맞지 않으면 false
                return false;
            }
            else {
                st.pop();
            }
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            else {
                st.pop();
            }
        }
        else { // 그 외 공백이나 알파벳은 다음 문자로 넘어감
            continue;
        }        
    }
    if (!st.empty()) { // 스택에 여는 괄호가 남아있으면 닫는 괄호가 부족한 것 -> false
        return false;
    }
    return true;
}

int main() {
    while (true) {
        string input;
        getline(cin, input);  // 입력을 줄 단위로 받음
        if (input == ".") { // 입력이 .이면 반복 종료
            break;
        }

        bool result = checkBracket(input);

        string print = result ? "yes" : "no";
        cout << print << endl;
    }
    return 0;
}
