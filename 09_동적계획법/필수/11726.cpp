#include <iostream>
#include <vector>

using namespace std;

//점화식을 세우면 dp[i] = dp[i-1] + dp[i-2]
//2*i의 직사각형을 채울 수 있는 방법의 수 = 2*(i-1) + 2*(i-2)

int solution(int n){    //답 = dp[i] = dp[i-1] + dp[i-2]
    vector<int> dp(n+1, 0); //dp[i] = 2*i의 직사각형을 채울 수 있는 방법의 수
    
    //초기값 설정
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;    //답이 10007로 나눈 나머지이므로
    }
    return dp[n];
}

int main(){
    int n;
    //입력
    cin >> n;
    
    int ans = solution(n);

    //출력
    cout << ans;
}