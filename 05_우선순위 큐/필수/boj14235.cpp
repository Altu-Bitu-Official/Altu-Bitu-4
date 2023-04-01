#include<iostream>
#include<queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> pq;
	int n, x;
	cin >> n;
	int a;
	while (n--) {
		cin >> a;
		if (a != 0) {
			while (a--) {
				cin >> x;
				pq.push(x);
			}
		}
		else if (a == 0) {
			if (pq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}