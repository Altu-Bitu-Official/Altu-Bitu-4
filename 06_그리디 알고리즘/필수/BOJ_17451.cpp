#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	double v[300000];

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//연산
	double raised_v = v[n - 1];
	for (int i = n - 2; i >= 0; i--) { //오른쪽부터 거슬러 계산
		raised_v = ceil(raised_v / v[i]) * v[i];
	}

	//출력
	cout << (long long)raised_v;
	return 0;
}