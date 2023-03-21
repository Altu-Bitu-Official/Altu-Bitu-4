#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, a;
	cin >> n;
	priority_queue<int> pq;

	while (n--) {
		cin >> a;
		if (a == 0) {
			//a=0 (거점지가 아닌 아이들)
			if (pq.empty()) {
				//비었으면 -1
				cout << -1 << endl;
			}
			else {
				//비지 않은 경우 가장 가치가 큰 선물
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			//(거점지)
			while (a--) {
				int x;
				cin >> x;
				pq.push(x);
			}
		}
	}


    return 0;
}