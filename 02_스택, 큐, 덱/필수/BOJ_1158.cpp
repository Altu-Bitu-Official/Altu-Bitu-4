#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	queue<int> q;
	vector<int> v;

	// 입력
	cin >> n >> k;
	
	// 연산
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}	

	while (n--) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}

		v.push_back(q.front());
		q.pop();
		
	}	

	// 출력
	cout << "<";

	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	
	cout << v[v.size() - 1] << ">";
	
	return 0;
}