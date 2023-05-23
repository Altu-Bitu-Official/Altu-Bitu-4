#include<iostream>
#include<vector> //map사용해서 tree구현
using namespace std;

// 후위 순회 L - R - V
void postorder(vector<int>& tree, int start, int end) {
	if (start >= end) { //시작위치가 끝위치보다 같거나 뒤인 경우
		return;
	}
	int i;
	for (i = start + 1; i < end; i++) {
		if (tree[i] > tree[start]) {
			break;
		}
	}
	postorder(tree, start + 1, i);
	postorder(tree, i, end);
	cout << tree[start] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> tree;
	int input;
	int cnt = 0;
	while (cin >> input) {
		cnt++;
		tree.push_back(input);
	}
	postorder(tree, 0, cnt);
	return 0;
}