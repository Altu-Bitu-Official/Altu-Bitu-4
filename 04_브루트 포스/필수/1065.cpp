#include <iostream>
#include <string>

using namespace std;

int solution(int& n){
    int ans = 99;
    //1~99는 한수
    if(n < 100){
        return n;
    }
    //100 이하는 검사할 필요 없음
    while(n >= 100){
        string t = to_string(n);
        bool check = 1;
        //등차수열 검사
        for(int i=0; i<=t.length()-3; i++){
            //등차수열이 한 번이라도 깨지면 false
            if(t[i]-t[i+1] != t[i+1]-t[i+2]){
                check = 0;
            }
        }
        //등차수열일 경우에만 +1
        if(check){
            ans++;
        }
        n--;
    }
    return ans;   
}

int main()
{   
    int n; 
    //입력
    cin >> n;
    //한수 구하기
    int ans = solution(n);
    //출력
    cout << ans;
}