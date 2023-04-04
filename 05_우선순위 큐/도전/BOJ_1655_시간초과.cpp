#include <iostream>
#include <queue>

using namespace std;
struct cmp{
    bool operator()(const int& x, const int& y){
        return x>y;//큐에 오름차순으로 넣는다. 
        //x가 y보다 더 크면 true를 반환해 큐 내에서 swap.
    }
};
int middlenum(priority_queue<int,vector<int>,cmp> &pq){
    priority_queue<int,vector<int>, cmp> copy;//사본
    copy=pq;
    int pq_size=copy.size();

    //중간값이 나올 때 까지 pop
   if(pq_size%2==0){
    for(int i=0;i<pq_size/2-1;i++){
        copy.pop();
    }
    //중간값을 출력
    return copy.top();
   }
   else{
    for(int i=0;i<pq_size/2;i++){
        copy.pop();
    }
    //충간값을 출력
    return copy.top();
   } 
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;

    while(n--){
        int input;
        cin >> input;

        pq.push(input);
        cout << middlenum(pq) << '\n';

    }
    return 0;
}