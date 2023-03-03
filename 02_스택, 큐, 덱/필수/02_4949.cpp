#include <iostream>
#include <stack>

using namespace std;

int main() {

    while (1) {

        string s;
        getline(cin, s);
        bool tmp = true;

        if (s == ".") {
            break;
        }
        stack<char> stack;

        for (int i = 0; i < s.length(); ++i) {

            if (s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            }

            else if (s[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
                else {
                    tmp = false;
                    break;
                }
            }

            else if (s[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                }
                else {
                    tmp = false;
                    break;
                }
            }
        }

        if (stack.empty() && tmp==true) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
