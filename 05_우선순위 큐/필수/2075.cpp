#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, input; 
    priority_queue<int, vector<int>, greater<>> pq; // 작은 수를 먼저 내보내는 우선순위 큐

    cin >> n;
    int size = n*n; // 표의 크기: n*n

    while(size--) {
        cin >> input;
        pq.push(input);
        if(pq.size() > n) { // 큐의 크기가 n을 넘어가면
            pq.pop();       // 큐의 가장 작은 수를 내보냄
        }
    }
    // 결과 출력
    cout << pq.top(); // pq의 top은 n번째로 큰 수
    return 0;
}