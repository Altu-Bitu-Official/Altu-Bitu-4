#include <iostream>
#include <vector>

using namespace std;

int getMinCost(int n, vector<vector<int>>& cost) {
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0] = cost[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int min_cost = 1000 * 1000;
	for (int i = 0; i < 3; i++) {
		min_cost = min(min_cost, dp[n - 1][i]);
	}
	return min_cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> cost(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	//연산 & 출력
	cout << getMinCost(n, cost);

	return 0;
}