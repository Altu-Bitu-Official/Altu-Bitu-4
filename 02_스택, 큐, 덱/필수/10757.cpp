#include <iostream>
#include <stack>

using namespace std;

stack<int> setStack() {
    stack<int> q;
    char ch;

    while (scanf("%1c", &ch)) {
        if (!isdigit(ch)) {
            break;
        }
        q.push(ch - 48);
    }

    return q;
}

stack<int> add(stack<int> &a, stack<int> &b) {
    stack<int> res;

    int carry = 0;

    while (true) {

        int n1 = 0;
        int n2 = 0;

        if (!a.empty()) {
            n1 = a.top();
            a.pop();
        }
        if (!b.empty()) {
            n2 = b.top();
            b.pop();
        }

        int sum = n1 + n2 + carry;
        carry = (sum / 10);
        res.push(sum % 10);

        if (a.empty() && b.empty() && carry==0) {
            break;
        }
    }

    return res;
}

void print(stack<int> &a) {
    while (!a.empty()) {
        cout << a.top();
        a.pop();
    }
}

int main() {
    // 입력
    stack<int> a = setStack();
    stack<int> b = setStack();
    stack<int> res = add(a, b);
    print(res);
}
