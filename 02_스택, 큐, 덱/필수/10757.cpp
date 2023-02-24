#include <iostream>
#include <stack>

using namespace std;

stack<int> setStack() {
    stack<int> q;
    char ch;

    // 한 글자씩 읽어서 스택에 저장
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

        // 런타임에러를 피하기 위해 스택이 비어있지 않을 때에만 top, pop 수행
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
    // 연산
    stack<int> res = add(a, b);
    // 출력
    /* 함수의 결과값은 reference로 넘겨줄 수 없나요?
     * print(add(a, b)); 로 작성했더니 코드에서 에러가 발생하더라구요ㅠ.ㅠ
    */
    print(res);
}
