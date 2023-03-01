#include <iostream>
#include <queue>

using namespace std;

// 요세푸스 순열을 리턴하는 함수
queue<int> josep(static queue<int>& q, int n, int k) {
    queue<int> answer;
    for (int i = 0; i < n; i++) { // i번째 사람 -> i-1번 앞사람 뒤로 보내기
        for (int j = 0; j < k - 1; j++) {
            q.push(q.front());
            q.pop();
        }
        answer.push(q.front());
        q.pop();
    }
    return answer;
}

int main() {
    queue<int> q, answer;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    answer = josep(q, n, k);
    
    // 정답 출력
    cout << '<';

    for (int i = 0; i < n; i++) {
        cout << answer.front();
        answer.pop();
        if (i < n-1) {
            cout << ", ";
        } else {
            cout << '>';
        }
    }
}