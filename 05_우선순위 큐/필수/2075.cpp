#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int input;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n * n; i++) {
        cin >> input;
        pq.push(input);
        if (pq.size() > n) {
            pq.pop();
        }
    }
    cout << pq.top();

}