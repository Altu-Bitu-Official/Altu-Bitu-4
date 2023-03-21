#include <iostream>
#include <queue>

using namespace std;

int usePq(int n) {
	int ans;
	priority_queue<int, vector<int>, greater<int>> pq; // ���� ���� top�� ���� �켱����ť
	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		pq.push(num);
		// ũ�⸦ n���� �����ϸ� top���� n��°�� ū ���� �����Ѵ�.
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