#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int n,k,tmp;
    queue<int> q;
    vector<int> v; //결과값 저장할 벡터
    cin >>n>>k;
    for(int i=1;i<=n;i++){ //1~n까지 큐에 집어넣기
        q.push(i);
    }
    while(!q.empty()){ //큐가 빌 때까지 반복
        int i=k-1; //k번째 전까지 큐의 앞에서 뺀 숫자를 뒤에 넣기
        while(i--){
            tmp=q.front();
            q.pop();
            q.push(tmp);

        }
        tmp=q.front(); //n번째 숫자 빼서 벡터 v에 집어넣기
        q.pop();
        v.push_back(tmp);
    }
    cout <<"<";
    for(int i=0;i<v.size()-1;i++){ //결과 출력
        cout <<v[i]<<", ";
    }
    cout <<v[v.size()-1]<<">";


    return 0;
}