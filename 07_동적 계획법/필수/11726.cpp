// 2×n 타일링

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, 0); // 직사각형을 채우는 방법 수
    
    dp[1] = 1; dp[2] = 2;
    
    for (int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }
    
    cout << dp[n];
    return 0;
}