#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		q.push(i+1);
	}

	vector<int> arr;
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) { // front로부터 k-1번째까지의 요소는 삭제하고 다시 뒤로 보냄
			int cur = q.front();
			q.pop();
			q.push(cur);
		}
		arr.push_back(q.front()); // k번째의 요소는 배열에 넣은 후 삭제
		q.pop();
	}

	// 배열 순서대로 출력
	cout << "<" << arr[0];
	for (int i = 1; i < n; i++) {
		cout << ", " << arr[i];
	}
	cout << ">";

	return 0;
}