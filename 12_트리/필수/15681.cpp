#include <iostream>
#include <vector>

using namespace std;

int dfs(int n, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& count) {
	if (count[n] != 0){
        return count[n];
    }
	visited[n] = true;

	int cnt = 1;

	for (int next : graph[n]) {
		if (visited[next]){
            continue;
        }
		cnt += dfs(next, graph, visited, count);
	}
	count[n] = cnt;
	return cnt;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    
	int n, r, q, v1, v2;
	cin >> n >> r >> q;

    vector<vector<int>> graph(n+1, vector<int>(0)); 

	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

    vector<bool> visited(n + 1, false);
    vector<int> count(n + 1, 0);

	count[r] = dfs(r, graph, visited, count);

	for (int i = 0; i < q; i++) {
		cin >> v1;
		cout << count[v1] << '\n';
	}

	return 0;
}