#include <iostream>
#include <algorithm>

using namespace std;

int minCost(int n, int color[][4]) {
	int ans = 0;
	int sum[1010][4];
	for (int i = 1; i <= n; i++) {
		color[i][2] += min(color[i - 1][0], color[i - 1][1]);
		color[i][0] += min(color[i - 1][1], color[i - 1][2]);
		color[i][1] += min(color[i - 1][0], color[i - 1][2]);
	}

	ans = min(color[n][0], min(color[n][1], color[n][2]));
	return ans;
}

int main() {
	int n;
	cin >> n;
	int color[1010][4];
	for (int i = 0; i < n; i++) {
		cin >> color[i][0]; //red
		cin >> color[i][1]; //blue
		cin >> color[i][2]; //green

	}
	int ans = minCost(n, color);
	cout << ans;
}