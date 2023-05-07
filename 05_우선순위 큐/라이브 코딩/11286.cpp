// 절댓값 힙

#include <iostream>
#include <queue>

using namespace std;

/*
* 우선순위 기준
* 1. 절댓값 작은 수
* 2. 값이 작은 수
*/
struct cmp{ // true이면 swap
    bool operator()(const int& x1, const int& x2){
        if (abs(x2) != abs(x1)) // 절댓값이 다르다면 절댓값 작은 수를 앞으로
            return abs(x2) < abs(x1);
        return x2 < x1; // 절댓값이 동일하다면 같이 작은 수를 앞으로
    }
};

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;
    while (n--){
        cin >> x;
        if (x == 0) // 출력 + 삭제
            if (pq.empty())
                cout << "0\n";
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        else
            pq.push(x);
    }
    return 0;
}