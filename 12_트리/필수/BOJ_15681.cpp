#include<iostream>
#include<vector>
#include<map>

using namespace std;

/*
 * 트리의 정점의 수 구하기 응용 문제
 *
 * 1. 루트에서 DFS를 사용하여 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 벡터에 저장
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열을 1로 초기화
 * - 탐색 시 현재 정점의 자식 노드만 탐색해서 현재 정점의 dp 값에 더해줌
 * 3. 쿼리로 주어지는 정점의 서브트리의 정점의 개수를 dp에서 찾아서 출력
 */

//탐색할 노드, 방금 탐색한 노드, 트리 벡터, dp 배열을 인자로 받고 dfs 탐색을 수행하면서 dp 배열을 구하는 함수
void dfs(int cur, int prev, vector<vector<int>>& tree, vector<int>& dp) {

	for (int i = 0; i < tree[cur].size(); i++) { // 현재 정점의 자식 노드 탐색
		if (tree[cur][i] == prev) { //탐색한 노드가 방금 전 탐색한 노드와 같을 때 == 부모 노드
			continue;
		}
		dfs(tree[cur][i], cur,tree, dp);    //자식 노드로 다시 dp 돌리기
		dp[cur] += dp[tree[cur][i]]; // 자식 노드의 dp값 더해주기
	}

	return;
}

int main() {

    // 입출력 향상
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n, r, q, u, v;
	cin >> n >> r >> q;
	
	vector<vector<int>>tree(n + 1, vector<int>(0));     //트리 벡터로 정의
	
    //입력
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	// 연산
	vector<int>dp(n + 1, 1); // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1로 dp 초기값 설정
	dfs(r, 0,tree, dp);     //dfs로 순회하면서 서브트리의 정점 개수를 저장하는 dp 배열 갱신하기

	// 출력
	while (q--) {
		cin >> u;
		cout <<dp[u] << '\n';
	}
}