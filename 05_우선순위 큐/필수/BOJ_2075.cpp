#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    // 크기 n인 배열에서 n번째로 큰 수 == 제일 작은 수. 따라서 오름차순으로 정렬.
    priority_queue<int, vector<int>, greater<int>> input;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push(a);
    }
    
    for (int i = 0; i < n*n - n; i++) {
        int a;
        cin >> a;
        if (a > input.top()) {  // n번째로 큰 수보다 더 큰 수가 있을 때, 원래 n-1번째로 큰 수가 n번째로 큰 수가 됨.
            input.push(a);
            input.pop();
        }
    }

    cout << input.top();
}