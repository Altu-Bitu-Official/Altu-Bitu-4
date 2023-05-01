#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std;
// 2 x n 직사각형을  1x2, 2x1로 채우는 방법의 수

int count(int n) {
	vector <int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	// n이 1씩 증가할 때마다 -> 1 x 2 직사각형 더해짐 
	// 점화식 사용
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i-2];
		dp[i] %= 10007;
	}
	return dp[n] ;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout<<count(n);
	return 0;
}