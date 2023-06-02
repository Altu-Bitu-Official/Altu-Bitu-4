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

void dfs(int cur, int prev, vector<vector<int>>& tree, vector<int>& dp) {

	for (int i = 0; i < tree[cur].size(); i++) { // 현재 정점의 자식 노드 탐색
		if (tree[cur][i] == prev) {//만약 현재 정점의 자식노드가 prev노드와 동일하다면
			continue;//다음 자식 노드 탐색
		}
		dfs(tree[cur][i], cur,tree, dp);//현재 정점의 자식노드가 prev노드와 동일하지 않으면 그 자식노드로부터 다시 dfs
		dp[cur] += dp[tree[cur][i]]; // 자식 노드의 dp값 더해주기
	}

	return;
}

int main() {

    //속도 향상 코드
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n, r, q, u, v;//정점의 수, 루트의 번호, 쿼리의 수, 간선의 정보를 저장할 변수 선언
	cin >> n >> r >> q;//값 입력
	
	vector<vector<int>>tree(n + 1, vector<int>(0));//트리 벡터 선언
	
	for (int i = 0; i < n - 1; i++) {//트리에 정점 넣기
		cin >> u >> v;//간선의 양 끝점 u, v
		tree[u].push_back(v);//트리벡터에 넣기
		tree[v].push_back(u);//트리벡터에 넣기
	}

	// 연산
	vector<int>dp(n + 1, 1); // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1로 dp 초기값 설정
	dfs(r, 0,tree, dp);//답 구하기

	// 출력
	while (q--) {
		cin >> u;
		cout <<dp[u] << '\n';
	}
}