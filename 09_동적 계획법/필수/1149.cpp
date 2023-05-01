#include <iostream>
#include <vector>
using namespace std;
int cheapestRgbHouse(int n) {
	vector<vector<int>> cost(n + 1, vector<int>(3));
	for (int i = 1; i <= n; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2])+red;
		cost[i][1] = min(cost[i - 1][2], cost[i - 1][0])+green;
		cost[i][2] = min(cost[i - 1][1], cost[i - 1][0])+blue;
	}
	int answer = min(min(cost[n][0], cost[n][1]), cost[n][2]);
	return answer;
}
int main() {
	//입력
	int n;
	cin >> n;

	//계산
	int answer = cheapestRgbHouse(n);
	
	//출력
	cout << answer;
	return 0;
}