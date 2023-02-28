#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, k;
    queue<int> q;
    cin >> n >> k;
    
    for(int i=1; i<=n; i++)
        q.push(i);
    
    //연산 및 출력 
    printf("<");
    
    while(!q.empty()){
        for(int i=0; i<k-1; i++){
            q.push(q.front());
            q.pop();
        }
        if(q.size()==1){
            //마지막 숫자인 경우
            printf("%d>", q.front());
            q.pop();
        }
        else{
            //마지막 숫자가 아닌 경우
            printf("%d, ", q.front());
            q.pop();
        }
    }
    return 0;
}