#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, k;
    int tmp;
    cin >> n >> k;

    queue<int> q;
    for(int i=0; i< n; i++){
        q.push(i+1);
    }
    cout << "<";

    for(int i=0; i<n-1; i++){
        for(int j=0; j<k-1; j++){
           tmp = q.front();
           q.pop();
           q.push(tmp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";


    return 0;
}
