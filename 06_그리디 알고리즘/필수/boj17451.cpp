#include<iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; //첫째 주에 n(1 ≤ n ≤ 3·10^5
	cin >> n;
	int new_arr;
	int arr[300000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long speed = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (speed % arr[i] != 0) {
			speed = ((speed / arr[i]) + 1) * arr[i];
		}
	}
	cout << speed;

}