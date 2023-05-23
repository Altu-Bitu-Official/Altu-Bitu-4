#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> tree;
vector<int> edge_v[100001];
int nodeSize[100001];

void makeTree(int current, int parent) {
	for (int node : edge_v[current]) {
		if (node != parent) {
			tree[current].push_back(node);
			makeTree(node, current);
		}
	}
	return;
}

void countNode(int node) {
	nodeSize[node] = 1;

	for (int child : tree[node]) {
		countNode(child);
		nodeSize[node] += nodeSize[child];
	}
	return;		
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력
	int n, r, q, root;
	cin >> n >> r >> q;

	int c = (n - 1);
	int i, j;
	while (c--) {
		cin >> i >> j;
		edge_v[i].push_back(j);
		edge_v[j].push_back(i);
	}

	// 연산
	makeTree(r, -1);
	countNode(r);

	// 출력
	for (int i = 0; i < q; i++) {
		cin >> root;
		cout << nodeSize[root] << '\n';
	}

	return 0;
}