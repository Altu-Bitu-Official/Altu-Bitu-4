#include <iostream>
#include <vector>

using namespace std;

int knapsack(int n, in k, vector<int> &w, vector<int> &v)
{
    // dp[i][j]: i번째 물건까지 고려했고, 배낭이 버틸 수 있는 무게가 j일때 얻을 수 있는 가치함의 최대값
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // dp[0][j]=0

    // i: 물건 번째
    // j : 버틸수 있는 배낭 무게
    for (int i = 1; i <= n; i++)
    {
        // 버틸수 있는 무게 < 물건 무게
        for (int j = 1; j <= w[i]; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }

        // 버틸 수 있는 무게 >= 물건 무게
        for (int j = w[i]; j <=)
    }
    return dp[n][k];
}
int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> w(n + 1, 0);
    vector<int> v(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    int ans = knapsack(n, k, w, v);
}