#include <iostream>
#include <queue>
using namespace std;

void sol(int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    int tmp;
    for(int i=0; i<n*n; i++){
        cin >> tmp;
        pq.push(tmp); //입력받은 수를 우선순위큐에 넣기
        if(pq.size()>n){
            pq.pop();  //n개까지만 넣도록 했으므로 n+1번째 큰 수가 들어오면 pop해줌
        }
    }
    cout << pq.top();
}

int main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    sol(n);
}