#include <iostream>
#include <vector>

using namespace std;

long long getVelocity(vector<int>& v) {
	long long velocity = v[v.size() - 1];
	long long k;

	//거꾸로 탐색
	for (int i = v.size() - 2; i >= 0; i--) {
		//필요한 속도가 감소하는 경우
		if (v[i] >= velocity) {
			velocity = v[i];
			continue;
		}
		//필요한 속도가 증가하는 경우
		//velocity가 v[i]의 양의 배수가 되도록 함
		if (velocity % v[i] != 0) {
			k = velocity / v[i] + 1;
			velocity = v[i] * k;
		}
	}
	return velocity;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//연산 & 출력 
	cout << getVelocity(v);

	return 0;
}