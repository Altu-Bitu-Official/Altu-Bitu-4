#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N,num;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    cin>>N;

    for( int i=0; i<N*N; i++){
        cin>>num;
        max_heap.push(num);
        if(max_heap.size()>N){
            max_heap.pop();
        }
    }

    cout<<max_heap.top();
    return 0;
}