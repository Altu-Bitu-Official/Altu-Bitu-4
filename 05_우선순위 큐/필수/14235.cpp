#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, present; 
    priority_queue<int, vector<int>, less<int>> pq; // 내림차순

    cin >> n; // 입력받을 수의 개수
    while(n--) {
        cin >> a;
        if(!a) { // a가 0이면 선물을 꺼내서 나눠준다 (0이면 false, 0이 아니라면 true)
            if(pq.empty()) {            // 선물이 없으면 -1 출력
                cout << "-1\n"; 
                continue;
            }                          
            cout << pq.top() << '\n';   // 선물이 있으면 가장 높은 값 출력
            pq.pop();
            continue;
        }
        while(a--) { // a가 0이 아니면 선물을 입력받아 우선순위 큐에 넣는다
            cin >> present;          
            pq.push(present);
        }
    }
    return 0;
}