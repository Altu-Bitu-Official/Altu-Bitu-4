#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, k;
    queue<int> q;

    cin >> n >> k;

    //큐에 숫자(사람) 넣기
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    cout << "<";
    //pop
    while(q.size()>1){
        for(int i=0;i<k-1;i++){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        cout << q.front() << ", ";
        q.pop();
        
    }

   
        cout << q.front() << ">";
    
    
}