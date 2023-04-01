#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,tmp; //입력받을 숫자들

    cin >>n;
    int k=n*n;

    priority_queue<int,vector<int>,greater<int>> table; //상위 5개의 숫자 저장할 우선순위 큐, 내림차순으로 정렬하여 top이 5번째로 큰 수가 되도록

    while(k--){ //n*n번 반복
        cin >>tmp;
        if(table.size()<n){ //n-1개 까지는 그냥 push
            table.push(tmp);
        }else{
           if(table.top() <=tmp){ //tmp가 table에 들어있는 숫자들 중 가장 작은 숫자(top에 있는 숫자)보다 작을 경우
               table.push(tmp); //table에 push
               table.pop(); //table내의 숫자 5개로 맞춰주기위해 pop

           }
        }

    }

    cout <<table.top();


    return 0;
}