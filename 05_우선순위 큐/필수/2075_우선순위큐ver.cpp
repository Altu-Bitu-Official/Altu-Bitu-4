// N번째 큰 수 - 우선순위 큐 이용

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> s; // 작은 값이 우선순위
    
    for(int i=0; i<n; i++)
        for (int j = 0; j<n; j++){
            cin >> x;
            s.push(x);
            if (s.size() > n) // 큐의 크기를 n으로 유지
                s.pop(); // 큐의 크기를 넘으면 작은 값이 제거됨
        }
        
    cout << s.top();
    return 0;
}