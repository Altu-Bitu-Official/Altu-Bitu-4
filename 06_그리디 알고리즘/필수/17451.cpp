#include <iostream>
#include <vector>
using namespace std;


long long calVelocity(vector<long long> v){ //속도 구하는 함수
    long long velocity=v[v.size()-1]; //뒤에서 부터 속도 비교하기 위해서 마지막 행성의 속도 변수에 저장
    for(int i=v.size()-2;i>=0;i--) //행성수(마지막 행성 제외) 만큼 반복
    {
        if(velocity%v[i]!=0){ //나누어지지 않는다면 배수가 아님
                 velocity=v[i]*(velocity/v[i]+1); // 배수 만들어줌
             }else{
                 continue; //나누어지면 그대로
             }
    }
    return velocity;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long ans,tmp;
    vector<long long> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>tmp;
        v.push_back(tmp);
    }

   ans = calVelocity(v);
    cout << ans;

    return 0;
}
