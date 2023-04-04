#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long checkSpeed(int &n, vector<long> &v){
    long ans = 0;

    //출발할 때 속도가 최고여야 하니까 뒤에서부터 검사
    for(int i=n-1; i>=0; i--){
        //속도가 크면 큰 속도로 설정 & 속도가 같으면 유지
        if(v[i] >= ans){
            ans = v[i];
        }
        //속도가 작다면 해당 속도의 배수로 설정
        else{
            long tmp = ceil((double)ans/(double)v[i]); //몇 배수할 건지 계산 (올림 함수)
            ans = v[i]*tmp; 
        }
    }
    return ans;
}

int main()
{
    int n;
    long speed;
    vector<long> v;

    //입력
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> speed;
        v.push_back(speed);
    }
    
    //계산
    long ans = checkSpeed(n, v);

    //출력
    cout << ans;
}