#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, value;
    cin >> n;

    priority_queue<int> pq;

    while(n--) {
        cin >> a;

        if(a==0) {
            //비었으면 -1
            if(pq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            for(int i=0; i<a; i++) {
                cin >> value;
                pq.push(value);
            }
        }
    }

    return 0;
}