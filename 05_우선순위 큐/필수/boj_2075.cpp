#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);   //연산 속도 증가를 위한 코드 
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>>  pq;  //오름차순으로 정렬하는 우선순위 큐  선언 

    for (int i = 0; i < N; i++){
        for(int j =0; j < N; j++){
            int num;
            cin >> num;
            pq.push(num);

            if(pq.size() > N){
                pq.pop();
            }
        }
    }

    //출력 
    cout << pq.top();


    return 0;
}



