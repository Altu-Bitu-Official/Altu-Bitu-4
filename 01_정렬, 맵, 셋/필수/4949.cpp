#include <iostream>
#include <stack>


using namespace std;

string checkBalance(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[') { //시작하는 괄호면 스택에 push
            st.push(s[i]);
        } else if (s[i] == ')') { //닫는 괄호면
            if (st.empty()) { //스택이 비어있을 경우 짝이 없으므로 균형X
                return "no";
            } else if (st.top() == '(') { //짝이 있는경우
                st.pop();
            } else {
                return "no";
            }

        } else if (s[i] == ']') {//닫는 괄호면
            if (st.empty()) {//스택이 비어있을 경우 짝이 없으므로 균형X
                return "no";
            } else if (st.top() == '[') { //짝이 있는경우
                st.pop();
            } else {
                return "no";
            }
        }

    }
    if (st.empty()) {
        return "yes";
    } else {
        return "no";
    }


}

int main() {
    string s;
    while (1) {
        getline(cin, s); //띄어쓰기 포함해서 입력받기

        if (s == ".") {  //.입력시 종료
            break;
        }
        cout << checkBalance(s) << "\n";

    }


    return 0;
}