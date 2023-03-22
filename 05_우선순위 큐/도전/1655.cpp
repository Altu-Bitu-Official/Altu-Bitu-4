#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    bool flag=false;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > up;
    priority_queue<int> down;

    for(int i=0; i<n; i++) {
        cin >> tmp;

        if(flag) {
            up.push(tmp);
        } else {
            down.push(tmp);
        }

        if(!up.empty() && !down.empty() && up.top()<down.top()) {
            down.push(up.top());
            up.pop();
            up.push(down.top());
            down.pop();
        }

        cout << down.top() << "\n";
        flag=!flag;
    }

    return 0;
}