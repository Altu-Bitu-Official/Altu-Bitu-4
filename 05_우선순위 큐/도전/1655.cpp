/* 중간값을 말해야 한다. 
만약, 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp1 {
    bool operator()(const int &x1, const int &x2) { // x1: 부모노드, x2: 자식노드. true일 때 swap
        return x1 > x2;  // 더 작은 수가 높은 우선순위
    }
};

struct cmp2 {
    bool operator()(const int &x1, const int &x2) { // x1: 부모노드, x2: 자식노드. true일 때 swap
        return x1 < x2;  // 더 큰 수가 높은 우선순위
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x; 
    priority_queue<int, vector<int>, cmp2> small; // 작은 수들을 저장할 우선순위 큐
    priority_queue<int, vector<int>, cmp1> big;   // 큰 수들을 저장할 우선순위 큐
    // 몇 개의 숫자를 받을지 입력
    cin >> n;   
    while(n--) {
        cin >> x;

        if(small.size() - big.size() < 1) { // 작은 수 개수는 항상 큰 수보다 같거나 1 커야 함
            small.push(x);
        }
        else { // 차이가 1 이상 난다면 big에 push
            big.push(x);
        }

        if(!big.empty()) { // big이 비어있지 않고
            if(small.top() > big.top()) { // small의 top이 big의 top보다 크면
                small.push(big.top()); // 두 수를 바꿔 큐에 넣고
                big.push(small.top());

                small.pop();           // 기존 큐에서 삭제
                big.pop();
            }
        }
        // 결과 출력
        cout << small.top() << '\n'; 
    }
    return 0;
}