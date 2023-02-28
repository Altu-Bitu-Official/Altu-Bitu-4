#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void kill(queue<int>& first, queue<int>& second, int& t, const int k){
    //해당 큐가 빌 때까지 루프 돌리기
    while(!first.empty()){
        while(t--)
        {
            //k번째 사람 kill
            if(k == 0){
                cout << first.front();
                first.pop();
                //큐 둘 다 빈 게 아니라면(계산이 끝난 게 아니라면) 출력 포맷 맞추기
                if(!(first.empty() && second.empty())){
                    cout << ", ";
                }
            }
            //k번째 사람이 아니라면 (kill하지 않는다면)
            else{
                //남은 사람을 두 번째 큐로 옮기기
                second.push(first.front());
                first.pop();
                //옮기던 도중 큐가 비면 (두번째 큐에서 동작 이어가기 위해) 함수 멈추기 
                if(first.empty()){
                    return;
                }
            }
        }
        //큐가 비지 않았으면 다음 kill을 위해 kill 횟수 초기화
        t = k;
    }
}

int main()
{
    int n, k;
    queue<int> first, second;

    //입력
    cin >> n >> k;
    
    //출력 포맷 맞추기용
    cout << "<";
    
    //queue 채우기
    for(int i=1; i<=n; i++){
        first.push(i);
    }

    int t = k;      //kill 횟수 초기화
    
    //큐 2개가 빌 때까지 계산, 큐 2개가 모두 비면 제거할 사람이 없다는 뜻
    while(!first.empty() || !second.empty()){
        //첫 번째 큐에 있는 사람 kill
        if(!first.empty()){
            kill(first, second, t, k);     
        }
        //두 번째 큐에 있는 사람 kill
        else{
            kill(second, first, t, k);     
        }
    }
    //출력 포맷 맞추기
    cout << ">";

}