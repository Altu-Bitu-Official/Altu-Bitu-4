#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> square;//greater를 써야하는데 정확하게 어떻게 써야하는지 모르겠어요...

	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		square.push(num);

		if (square.size() > n) {// n만 저장하면 마지막에 top에는 원하는 n번째 수가 오게 됨
			square.pop();
		}
	}

	cout << square.top();
}