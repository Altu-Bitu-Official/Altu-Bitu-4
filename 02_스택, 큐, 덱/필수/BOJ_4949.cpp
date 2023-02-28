#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        // 각 줄에 대해서
        string input;
        bool out = 1;
        stack<char> s;

        getline(cin, input);

        if (input == ".") {
            break;
        }
        for (int i=0; i < input.length(); i++) {
            if (input[i] == '(' || input[i] == '[') {
                s.push(input[i]);
            }
            else if (input[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    out = 0;
                    break;
                }
            }
            else if (input[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    out = 0;
                    break;
                }
            }
        }
        if (out==1 && s.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}