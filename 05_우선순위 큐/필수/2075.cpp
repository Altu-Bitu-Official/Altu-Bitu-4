#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> square;//우리가 원하는 것은 오름차순이므로 greater사용

	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		square.push(num);

		if (square.size() > n) {// n만 저장하면 마지막에 top에는 원하는 n번째 수가 오게 됨
			square.pop();
		}
	}

	cout << square.top();
}