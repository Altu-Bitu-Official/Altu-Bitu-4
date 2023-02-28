#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> stack;

    while(1) {

        string s;
        getline(cin, s);
        if(s=="."){
            break;
        }


        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                stack.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
                else {
                    cout << "no\n";
                    break;
                }
            }
            else if (s[i] == ']') {
                if (!stack.empty() && stack.top() == '[') {
                    stack.pop();
                }
                else {
                    cout << "no\n";
                    break;
                }
            }
            else {
                cout << "no\n";
                break;
            }

        }
        if (stack.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}