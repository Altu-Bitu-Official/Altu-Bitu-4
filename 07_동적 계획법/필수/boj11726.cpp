#include <iostream>
#include <vector>

using namespace std;

int maxCount(int n) {
    //dp[i] = 2xi 최대 경우의 수
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << maxCount(n);
}