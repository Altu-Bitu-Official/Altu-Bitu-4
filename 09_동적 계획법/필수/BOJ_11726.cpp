#include <iostream>
#include <vector>

using namespace std;

int getNum(int n) {
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	
	//연산 & 출력
	cout << getNum(n);

	return 0;
}