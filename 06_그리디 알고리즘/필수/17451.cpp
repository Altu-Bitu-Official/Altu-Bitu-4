#include <iostream>
#include <vector>

using namespace std;

long long findVelocity(vector<int> planet) {
	long long v = 0;
	// 거꾸로 검사
	for (int i = planet.size() - 1; i >= 0; i--) {
		if (v < planet[i]) {
			v = planet[i];
		}
		else if (v >= planet[i] && v % planet[i] != 0) {
			// 기존의 v보다 크거나 같은 planet[i]의 정수 배로 업데이트
			v = 1ll * (v / planet[i] + 1) * planet[i];
		}
		// cout << v;
	}
	return v;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int n, v;
	vector <int> planet;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		//cout << v;
		planet.push_back(v);
	}

	cout << findVelocity(planet) << "\n";

	return 0;
}