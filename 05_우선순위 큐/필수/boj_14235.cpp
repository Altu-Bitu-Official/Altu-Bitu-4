#include <iostream> 
#include <queue> 
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, input,t; 
    priority_queue<int> pq;
    //입력 
    cin >> n;
    
    //연산 및 출력 

    while(n--){
        cin >> input;
        if (input == 0){   // 0일때 아이들에게 준 선물의 가치 출력 
            if(pq.empty()){ //선물이 없으면 -1 출력 
                cout << -1 << '\n';
            }
            //비어있지 않으면 
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
           
        }
        //선물이 들어왔으면 
        else {
            for (int i =0; i < input; i++){
                cin >> t; 
                pq.push(t);
            }
            }
        }

        //메인함수 종료 
        return 0;
    }


