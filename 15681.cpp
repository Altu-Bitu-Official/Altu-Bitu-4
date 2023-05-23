// 15681 트리와 쿼리
/*
    DP + DFS
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int sub_root, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& dp) {

	if (!dp[sub_root]) {
		return dp[sub_root];
    }
	vis[sub_root] = true;
	int num = 1; // 자기 자신은 무조건 포함하므로 1로 초기화 후 시작합니다
	//다음 탐색
	for (auto nxt : adj[sub_root]) {
		if (vis[nxt]) {
			continue;
		}
		num += dfs(nxt, adj, vis, dp);
	}
	return dp[sub_root];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q;
	int x, y;
	int sub_root;
	cin >> N >> R >> Q;
	vector<vector<int>> adj(N + 1, vector<int>(0)); // 연결리스트 저장방법
    vector<bool> vis(N + 1, false); // 방문 표시 배열 초기화
	vector<int> dp(N + 1, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
	}
	dp[R] = dfs(R, adj, vis, dp);
	while (Q--) {
		cin >> sub_root;
		cout << dp[sub_root] << "\n";
	}
	return 0;
}