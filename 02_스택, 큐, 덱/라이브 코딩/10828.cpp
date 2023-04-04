#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    stack<int> s;
    string cmd;

    cin >> n;
    while(n--) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> x;
            s.push(x);
        }
        else if(cmd == "pop") {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(cmd == "size") {
            cout << s.size() << '\n';
        }
        else if(cmd == "empty") {
            cout << s.empty() << '\n';
        }
        else if(cmd == "top") {
            if(s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
            }
        }
    }
    return 0;
}