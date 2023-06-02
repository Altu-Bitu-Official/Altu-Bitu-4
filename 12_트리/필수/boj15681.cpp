#include<iostream>
#include<vector> 
using namespace std;

int dfs(int cur, vector<vector<int>>& g, vector<bool>& v, vector<int>& cnt) {

	if (cnt[cur] != 0) {
		return cnt[cur];
	}
	//방문표시
	v[cur] = true;
	int num = 1;
	//다음 탐색
	for (int next : g[cur]) {
		if (v[next]) {
			continue;
		}
		num += dfs(next, g, v, cnt);
	}
	cnt[cur] = num;
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q; //트리 정점 수, 루트 번호, 쿼리 수
	int v1, v2;
	int vq;
	cin >> n >> r >> q;
	vector<vector<int>> g(n + 1, vector<int>(0));
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	vector<bool> v(n + 1, false);
	vector<int> cnt(n + 1, 0);
	cnt[r] = dfs(r, g, v, cnt);
	while (q--) {
		cin >> vq;
		cout << cnt[vq] << "\n";
	}
	return 0;
}