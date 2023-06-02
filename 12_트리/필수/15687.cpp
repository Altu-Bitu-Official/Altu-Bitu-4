#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt, visited;
vector<vector<int>> tree;

void dfs(int node) {
	visited[node] = 1;
	for (int child : tree[node]) {
		if (!visited[child]) {
			dfs(child);
			cnt[node] += cnt[child];
		}
	}
	cnt[node]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	int N, R, Q;
	cin >> N >> R >> Q;
	tree.resize(N + 1);
	cnt.resize(N + 1, 0);
	visited.resize(N + 1, 0);

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(R);

	int U;
	for (int j = 0; j < Q; j++) {
		cin >> U;
		cout << cnt[U] << "\n";
	}

	return 0;
}
