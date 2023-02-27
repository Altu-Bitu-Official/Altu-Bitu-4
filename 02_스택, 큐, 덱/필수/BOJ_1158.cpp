#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;

    int n, k;

    cin >> n >> k;

    for(int i=1; i<n+1; i++){
        q.push(i);
    }

    cout << "<";

    for(int i=0; i<n; i++){
        for(int j=0; j<k-1; j++){ //k번째 사람이 front에 오도록 함
            q.push(q.front()); q.pop();
        }
        cout << q.front(); q.pop();
        if(i==(n-1)){
            cout << ">";
        }
        else {
            cout << ", ";
        }
    }

    return 0;
       
}
