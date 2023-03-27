#include <iostream>
#include <vector>

using namespace std;

bool isAvailable(vector<int>& tree) {
	int sum_height = 0; //나무 높이의 총합
	int two_cnt = 0; //2만큼 성장시킬 수 있는 횟수
	for (int i = 0; i < tree.size(); i++) {
		sum_height += tree[i];
		two_cnt += tree[i] / 2;
	}

	//나무 높이의 합이 3의 배수가 아니라면 만들 수 없으므로 false
	if (sum_height % 3 != 0) {
		return false;
	}
	
	int total_cnt = sum_height / 3; //총 물을 뿌린 횟수
	//총 n번 물을 뿌린다면 1만큼 n번, 2만큼 n번 뿌림
	//2만큼 뿌릴 수 있는 개수가 n보다 크다면 n번 뿌릴 수 있는 것이므로 true
	if (two_cnt >= total_cnt) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	//연산 & 출력
	if (isAvailable(tree)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}