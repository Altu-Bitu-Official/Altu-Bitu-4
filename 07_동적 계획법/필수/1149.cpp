// RGB거리

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPrice(vector<vector<int>> &color, int n){
    vector<vector<int>> dp(n+1, vector<int> (3,0));
    // dp[i]: i 번째 집까지 칠하는데 최소 비용
    for (int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0]; // i번째 집을 빨간 색으로 칠하는 경우
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1]; // i번째 집을 초록 색으로 칠하는 경우
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2]; // i번째 집을 파란 색으로 칠하는 경우
    }
    return min({dp[n][0], dp[n][1], dp[n][2]});
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> color(n+1, vector<int>(3,0));
    
    for (int i=1; i<=n; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    cout << minPrice(color, n);
    return 0;
}