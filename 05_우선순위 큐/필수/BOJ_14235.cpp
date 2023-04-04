#include <iostream>
#include <queue>

using namespace std;

int main(){
   int n;
   cin >> n;
    priority_queue<int> pq;
    int a;
   while(n--){
    cin >> a;
    if(a==0){
        if(pq.empty()){
            cout << -1 << '\n'; continue;
        }
        int pres=pq.top();
        cout << pres << '\n';
        pq.pop();
    }
    else{
        while(a--){
            int store;
            cin >> store;
            pq.push(store);
        }
    }
    
   } 
   return 0;
}