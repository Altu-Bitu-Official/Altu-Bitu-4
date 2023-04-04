#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;

void dfs(vector<pair<int, int>> trust, vector<bool> &visited, int i, int &hacked) {
	visited[i] = true;
	hacked++;
	for (int k = 0; k < trust.size(); k++) {
		if (trust[k].second == i && !visited[trust[k].first]) {
			dfs(trust, visited, trust[k].first, hacked);
		}
	}
	return;
}

// A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다. --> 방향이 있는 그래프
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// 입력
	int n, m;
	int a, b;
	vector<pair<int, int>> trust; // 신뢰관계

	cin >> n >> m;
	vector<int> computer(n, 0); // 해킹할 수 있는 수 저장

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		trust.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++) {
		// 각 컴퓨터에 대해서 dfs
		int hacked = 0;
		vector<bool> visited(MAX, false); // 방문(해킹) 저장
		dfs(trust, visited, i, hacked);
		computer[i] = hacked;
	}

	// 최대값
	int ans = *max_element(computer.begin(), computer.end());
	for (int i = 0; i < n; i++) {
		if (computer[i] == ans) {
			cout << i << " ";
		}
	}
	return 0;
}