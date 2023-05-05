#include <iostream>
#include <vector>

using namespace std;

//dp를 매번 선언하면 메모리 초과가 발생하므로 한 번 선언해서 매번 초기화함
void initDp(vector<int>& dp) {
	for (int i = 0; i <= 10000; i++) {
		dp[i] = 0;
	}
}

int solution(int n, int m, vector<int>& coin, vector<int>& dp) {
	initDp(dp); //dp 초기화

	//동전의 종류만큼 반복
	for (int i = 0; i < n; i++) {
		//자기 자신 금액을 만들 수 있음
		dp[coin[i]]++;
		for (int j = coin[i] + 1; j <= m; j++) {
			//coin[i]가 없이 완성되었던 금액의 방법 수만큼 더 추가함
			dp[j] += dp[j - coin[i]];
		}
	}
	return dp[m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m;
	cin >> t;

	//dp[i]: i원을 만드는데 가능한 방법의 수
	vector<int> dp(10001);

	while (t--) {
		//입력
		cin >> n;
		vector<int> coin(n);
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cin >> m;

		//연산 & 출력
		cout << solution(n, m, coin, dp) << "\n";
	}

	return 0;
}