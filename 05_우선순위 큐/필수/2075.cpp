#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, final;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin >> num;
            q.push(num);
            if(q.size()>n){
                q.pop();
            }
        }
    }

    cout << q.top();
}