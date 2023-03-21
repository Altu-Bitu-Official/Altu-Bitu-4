#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;  //산타가 거점지와 아이들을 방문한 횟수
    int a;
    int temp;
    priority_queue<int> presents;   //산타가 거점지에서 충전한 선물

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        
        //a가 0이면 즉, 아이에게 선물을 줘야하면
        if (a==0){   
            //줄 선물이 없으면 -1을, 있으면 선물의 가치중 가장 큰것을 출력함
            if (!presents.empty()) {
                cout << presents.top() <<'\n';
                presents.pop();
                }
            else    {cout << -1 <<'\n';}
        }
        //a가 0이 아니면 즉, 거점지이면 
        else{   
            //선물을 a개 충전한다.
            while (a--){
                cin >> temp;
                presents.push(temp);
            }
        }
    }

    return 0;
}