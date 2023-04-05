
#include <iostream>
#include <queue>

using namespace std;

int usePq(int n) {
	int ans;
	priority_queue<int, vector<int>, greater<int>> pq; // 작은 수가 top에 오는 우선순위큐
	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		pq.push(num);
		// 크기를 n으로 유지하면 top에는 n번째로 큰 수가 존재한다.
		if (pq.size() > n) {
			pq.pop();
		}
	}


	ans = pq.top();

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	cout << usePq(n);
	return 0;
}