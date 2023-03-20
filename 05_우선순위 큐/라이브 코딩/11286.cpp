#include <iostream>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(const int &x1, const int &x2){
    //x1이 부모, x2가 자식
    //절댓값이 다르면 절대값이 작은 수가 우선순위가 더 높다.
    if(abs(x1)!=abs(x2)){
        return abs(x2)<abs(x1);//부모노드 절댓값이 더 클 때 true를 반환
           }

    //절댓값이 같다면 값이 작은 수가 우선순위가 더 높다.
    return x2 < x1; //부모가 양수(더 큰 수)이면 true를 반환


    }
};

int main(){
    int n,x;
    priority_queue<int, vector<int>, cmp> pq;

   
    cin >> n;

    while(n--){
        cin >> x;
        if(x==0){
            //힙이 비었다면 0을 출력하고
            if(pq.empty()){
                cout << "0\n";
            }
            //아니라면 배열에서 가장 큰값을 pop한다.
            else{
                cout<<pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            //해당 자연수를 삽입.
            pq.push(x);
        }
    }
    return 0;
}