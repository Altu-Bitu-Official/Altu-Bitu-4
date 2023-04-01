#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	int x;
	cin >> n;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			cin >> x;
			pq.push(x);
			if (pq.size() > n) {
				pq.pop();
			}
		}
	}
	cout << pq.top();
}