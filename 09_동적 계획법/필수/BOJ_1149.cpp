#include <iostream>
#include <vector>

using namespace std;

//집의 개수 n과 집과 색깔 별 가격이 들은 cost 벡터를 받고 집을 채우는 최소 가격을 출력하는 함수
int minCost(int n, vector<vector<int>>& cost) {
    vector<vector<int>> dp (n+1, vector<int> (4, 0));

    //행 : n번째 집, 열 : 마지막으로 색칠할 때 사용한 색깔
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];
    dp[1][3] = cost[1][3];

    for (int i = 2; i <= n; i++) {  //색깔 별로 i번째 집에서의 최소합을 구함.
        dp[i][1] = cost[i][1] + min(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = cost[i][2] + min(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = cost[i][3] + min(dp[i-1][1], dp[i-1][2]);
    }

    int dp_min = min(dp[n][1], dp[n][2]);
    dp_min = min(dp_min, dp[n][3]);

    return dp_min;

}

int main() {
    int n;
    
    //입력
    cin >> n;
    vector<vector<int>> cost(n+1, vector<int> (4, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> cost[i][j];
        }
    }

    int answer = minCost(n, cost);
    
    //출력
    cout << answer;


}