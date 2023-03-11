#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, k;
    vector<int> vec;
    queue<int> que;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        que.push(i);
    }

    while(!que.empty()){
        for (int i = 0; i < k-1; i++){
            que.push(que.front()); 
            que.pop();
        }
        vec.push_back(que.front());
        que.pop();
    }
    cout << "<";
    for (int i = 0; i < n-1;i++){
        cout << vec[i] << ", ";
    }
    cout << vec[n - 1] << ">";
	
    return 0;
}