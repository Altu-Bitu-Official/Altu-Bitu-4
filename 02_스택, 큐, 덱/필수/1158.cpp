#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void kill(queue<int>& q, const int k){
	while(!q.empty()){
        //kill 대상이 아닌 사람을 큐의 마지막에 다시 추가
		for(int i=0; i<k-1; i++){
			q.push(q.front());
			q.pop();
		}
        //출력 포맷 맞추기용
        if(q.size() == 1){
            cout << q.front() << ">";
        }
        else{
            cout << q.front() << ", ";
        }
        //kill
		q.pop();
	}
}

int main()
{
    int n, k;
    queue<int> q;

    //입력
    cin >> n >> k;
    
    //출력 포맷 맞추기용
    cout << "<";
    
    //queue 채우기
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    //요세푸스 순열
	kill(q, k);
}