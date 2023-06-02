#include <iostream>
#include <vector>
#include <map>

using namespace std;

//트리를 만드는 함수
void makeTree(int cur, int parent, vector<vector<int>>& graph, vector<vector<int>>& tree) {
	//cur 노드와 연결된 노드 탐색
	for (int i = 0; i < graph[cur].size(); i++) {
		//부모 노드가 아닌 경우 cur 노드의 child 노드로 만듦
		if (graph[cur][i] != parent) {
			tree[cur].push_back(graph[cur][i]);
			makeTree(graph[cur][i], cur, graph, tree);
		}
	}
}

//서브트리의 노드 개수를 세는 함수
void countSubtreeNodes(int cur, vector<int>& size, vector<vector<int>>& tree) {
	size[cur] = 1; //자기 자신도 포함
	//cur 노드의 child 노드 탐색
	for (int i = 0; i < tree[cur].size(); i++) {
		countSubtreeNodes(tree[cur][i], size, tree);
		size[cur] += size[tree[cur][i]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, q, u, v, node1, node2;

	//입력
	cin >> n >> r >> q;

	vector<vector<int>> graph(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	
	//연산
	vector<vector<int>> tree(n + 1, vector<int>());
	makeTree(r, -1, graph, tree);
	
	vector<int> size(n + 1);
	countSubtreeNodes(r, size, tree);

	//출력
	while (q--) {
		cin >> u;

		cout << size[u] << "\n";
	}

	return 0;
}