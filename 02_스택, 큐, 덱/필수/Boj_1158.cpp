#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);   //연산 속도 증가를 위한 코드 
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n,k;  // 사람의수, 사람이 제거되는 순서 
    cin >>n >> k;

    queue<int> q;

    for(int i=1; i <=n; i++)  // 큐에 n명의 사람 넣어주기 
    {
        q.push(i); 
    }

    cout << "<" ;

    //연산
    while (q.size() > 1){
        for (int i =1; i < k; i++ ){
            int tmp = q.front(); // tmp변수에 큐의 맨 앞 숫자를 저장
            q.pop();      //앞에서 빼서
            q.push(tmp); //뒤에 넣는다 
        }
        cout << q.front() << ", " ; //k 번이 끝나면 큐의 첫번째 요소 출력 
        q.pop() ;                  // 출력 후 큐에서 제거 
    }

    cout << q.front() << ">\n" ;  // 마지막 원소 출력 후 ">" 출력 



    return 0;
}