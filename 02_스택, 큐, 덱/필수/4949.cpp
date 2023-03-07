#include <iostream>
#include <stack>

using namespace std;

bool checkStack(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[')
            st.push(ch);
        else if (ch == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                return false;
            }
        } else if (ch == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    while (true) {
        string s;
        getline(cin, s);

        if (s == ".")
            break;

        if (checkStack(s)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}
