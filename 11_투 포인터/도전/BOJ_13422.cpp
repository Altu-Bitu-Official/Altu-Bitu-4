#include <iostream>
#include <vector>

using namespace std;

int getCount(int n, int m, int k, vector<int>& money) {
	int cnt = 0; //돈을 훔치는 방법의 가짓수

	vector<int> sum_money(n);
	//sum_money[0] 초기화
	for (int i = 1; i <= m; i++) {
		int idx = (n - m + i) % n;
		sum_money[0] += money[idx];
	}

	//n == m인 경우, sum_money가 계속 중복되므로 따로 처리함
	if ((n == m) && (sum_money[0] < k)) {
		return 1;
	}

	if (sum_money[0] < k) {
		cnt++;
	}

	for (int i = 1; i < n; i++) {
		int idx = (i + n - m) % n;
		sum_money[i] = sum_money[i - 1] + money[i] - money[idx];

		//훔친 돈이 k원 미만인 경우에 cnt 증가
		if (sum_money[i] < k) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int t, n, m, k;
	cin >> t;

	while (t--) {
		cin >> n >> m >> k;

		vector<int> money(n);
		for (int i = 0; i < n; i++) {
			cin >> money[i];
		}

		//연산 & 출력
		cout << getCount(n, m, k, money) << "\n";
	}

	return 0;
}