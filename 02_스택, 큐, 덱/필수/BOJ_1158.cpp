#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= k; i++) {
        q.push(i);
    }
    cout << '<';

    for (int i = 0; i < k; i++) { // i번째 사람 -> i-1번 앞사람 뒤로 보내기
        for (int j = 0; j < n - 1; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (i == k-1) {
            cout << '>';
        } else {
            cout << ", ";
        }
    }

}