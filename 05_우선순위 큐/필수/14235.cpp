#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n,a,tmp,value;
    cin >>n; //방문 횟수
    priority_queue<int> gifts; //선물들의 가치를 저장할 우선순위 큐
    for(int i=0;i<n;i++){
        cin >>a;
        if(a == 0){ //선물 가치 출력
            if(gifts.empty()){ //선물이 없을 경우
                value=-1;
                cout<<value<<"\n";
            }else{
                value = gifts.top(); //top이 가장 가치가 큰 선물
                gifts.pop();
                cout <<value<<"\n";
            }

        }
        else{ //선물 충전
            while (a--) {
                    cin >> tmp;
                    gifts.push(tmp);
                }

        }

    }

    return 0;
}