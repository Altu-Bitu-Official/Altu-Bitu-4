#include <iostream>
#include <vector>

using namespace std;

int check(vector<int> &trees) {
	// flag 역할의 함수
	int sum = 0, two = 0;
	for (int i = 0; i < trees.size(); i++) {
		sum += trees[i]; // 전체 합산
		two += trees[i] / 2; // 2를 주는 횟수(그리디)
	}

	if (sum % 3 == 0 && (two >= sum - two * 2)) {
		return 1;
	}
	return 0;
}

int main() {
	// 입력
	int n, h;
	vector<int> trees;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		trees.push_back(h);
	}

	if (check(trees)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	
	return 0;
}