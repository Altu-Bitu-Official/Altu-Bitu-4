#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x;
	cin >> n;

	priority_queue<int, vector<int>, greater<>> pq; //n개의 큰 수 저장

	//연산
	for (int i = 0; i < n * n; i++) {
		cin >> x;

		//pq의 사이즈를 n개가 되도록 저장
		if (pq.size() < n) {
			pq.push(x);
		}
		else {
			//pq의 원소들이 새로 입력된 x보다 크도록 균형을 맞춤
			if (!pq.empty() && x > pq.top()) {
				pq.pop();
				pq.push(x);
			}
		}
	}

	//출력
	cout << pq.top();

	return 0;
}