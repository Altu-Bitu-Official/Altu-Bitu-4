#include <iostream>
#include <queue>

using namespace std;

vector<int> josephus(int n, int k) { // 요세푸스 순열 반환
    vector<int> result; // 요세푸스 순열
    queue<int> q; // 원

    for(int i = 1; i <= n; i++) { // 원 초기화
        q.push(i);
    }

    while(!q.empty()) {
        for(int i = 0; i < k-1; i++) { // k-1번 pop & push
            q.push(q.front());
            q.pop();
        }

        // k번째 사람 pop 후 순열에 추가
        result.push_back(q.front());
        q.pop();
    }
    return result;
}

/*
 * 원을 따라 k번째 사람을 제거한다.
 * 1. k번째 사람이 아닌 사람은 원의 맨 뒤로 보낸다.
 * 2. k번째 사람은 원에서 제거한다.
*/

int main() {
    int n, k;
    queue<int> q;

    // 입력
    cin >> n >> k;

    // 연산
    vector<int> result = josephus(n, k);

    // 출력
    cout << "<" << result[0];
    for(int i = 1; i < n; i++) {
        cout << ", " << result[i];
    }
    cout << ">";
    return 0;
}