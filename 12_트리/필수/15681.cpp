#include<iostream>
#include<vector>
#include<map>//?

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

void dfs(int cur, int prev, vector<vector<int>>& tree, vector<int>& dp) {//cur: root, prev: 재귀 전 루트. 

	for (int i = 0; i < tree[cur].size(); i++) { // 현재 정점의 "자식 노드" 탐색
		if (tree[cur][i] == prev) {//중력없는 트리다보니까(루트없는)->자식이었던 애가 부모이기도 한 상황 발생. 그래서 그런 상황 continue
			continue;//다시 for문
		}
		dfs(tree[cur][i], cur, tree, dp);//지금의 cur가 재귀타고 내려가면 prev가 됨. 또 그 노드(지금 시점 자식인 애)의 깊이를 본다.
		dp[cur] += dp[tree[cur][i]]; // 자식 노드의 dp값 더해주기(dp값: 서브트리 정점갯수. 본인포함)
	}

	return;//깊이 다 재면 리턴
}

int main() {
	//속도향상
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int n, r, q, u, v;//n: 트리 정점의 수, r: 루트 번호, 쿼리수: q
	cin >> n >> r >> q;//트리 정점의 수, 루트의 번호, 쿼리의 수


	vector<vector<int>>tree(n + 1, vector<int>(0));//트리. 이차배열(행: 해당 노드의 번호. 열: 해당 노드의 자식들)

	for (int i = 0; i < n - 1; i++) {//n-1줄에 걸쳐(문제에서 일케말함. 간선이니까 그런듯)
		cin >> u >> v;//u v형태로 트리에 속한 간선의 정보가 주어진다. 
		tree[u].push_back(v);//트리에 넣는다. u와 연결된 v라는 뜻. 따라서 u인덱스에 v를 넣는다. 
		tree[v].push_back(u);//트리에 넣는다. 
	}

	// 연산
	//dp는 서브트리의 노드의 갯수를 저장하는 배열이다.
	vector<int>dp(n + 1, 1); // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1로 dp 초기값 설정
	dfs(r, 0, tree, dp);//깊이탐색. r: 루트번호

	// 출력
	while (q--) {//q: 해당 수만큼 답하라했음
		cin >> u;//해당 정점의 서브트리 수를 묻는 것임
		cout << dp[u] << '\n';//해당 정점의 서브트리 수 뱉음
	}
}