#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int, vector<int>, greater<int>> pq; //min heap

	//입력
	cin >> n;

	//연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);
			if (pq.size() > n) { //n개의 수만 pq에 가지고 있음
				pq.pop();
			}
		}
	}

	//출력
	cout << pq.top();

	return 0;
}