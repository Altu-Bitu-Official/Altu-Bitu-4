#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	//우선순위 queue(내림차순) 정의
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n * n; i++) {
		cin >> x;
		pq.push(x);
		//n개만 저장 - queue size가 n보다 커질 경우 하나 pop
		//queue에는 최대~n번째로 큰 수까지만 들어감
		if (pq.size() > n) {
			pq.pop();
		}
	}
	//n번째 큰 수가 queue의 top
	cout << pq.top();
	
	return 0;
}