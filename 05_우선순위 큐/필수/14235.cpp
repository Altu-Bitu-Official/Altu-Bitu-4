#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);

    //거점에 들를 경우 가져오는 선물들을 우선순위 큐에 넣는다.
    //아이들을 만나면 우선순위 큐의 top에 있는 선물들을 꺼내서 준다.
    //선물이 없으면 -1을 출력한다.

    int n, charge;
    cin >> n;

    priority_queue<int> pq;
    while(n--){
        cin >> charge;
        if(charge==0){
            if(pq.empty()){
                cout << -1 << "\n";
                continue;
            }
            int top = pq.top();
            pq.pop();
            cout << top << "\n";
        }
        else{
            while(charge--){
                int top;
                cin >> top;
                pq.push(top);
            }
        }

    }
    return 0;
}