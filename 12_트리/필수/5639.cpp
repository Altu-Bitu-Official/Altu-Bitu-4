#include<iostream>
#include<vector>

using namespace std;

void postOrder(int left, int right, vector<int>& tree) {
	if (left > right) {
		return;
	}

	int root = tree[left];//이해하기 쉽게 루트 따로 저장해주자!

	//루트보다 처음으로 큰 노드 인덱스 찾기 -> left, right새로 설정하기 위해서!
	int tmp = left + 1;
	for (int i = left+1 ; i <= right ; i++) {
		if (tree[i] > root) {
			tmp = i;
			break;
		}
	}

	//후위 순회 순으로 다시 탐색
	postOrder(left + 1, tmp - 1,tree);//루트보다 작은 노드들
	postOrder(tmp, right, tree);//루트보다 큰 노드들

	//left, right 탐색 끝났으므로 root 출력
	cout << root << '\n';
}

/*
* 이진 검색 트리 : 루트의 왼쪽 
* 이진 검색 트리를 전위 순회환 결과 -> 후위 순회한 결과
* 전위 순회 : 루트 왼쪽 오른쪽 -> 후위 순회 : 왼쪽 오른쪽 루트
*  -> 탐색 결과 : 루트 -> 루트보다 작은 노드(왼쪽) -> 루트보다 큰 노드(오른쪽)
*  -> 루트를 기준으로 left, right 나눠서 후위 순회 순으로 다시 탐색
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//입력
	int num;
	vector<int> tree;
	while (cin >> num) {
		tree.push_back(num);
	}

	//연산 + 출력
	postOrder(0, tree.size() - 1, tree);
}