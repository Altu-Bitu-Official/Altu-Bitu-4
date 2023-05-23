#include <iostream>
#include <vector>
using namespace std;
// 정점 U를 루트로 하는 서브트리에 속한 정점의 수 출력

void CountSubTree(int cur, vector<vector<int>>& tree, vector<bool>& visited, vector<int>& cnt) {
    visited[cur] = true; // 방문 표시

    for (int neighbor : tree[cur]) {
        if (!visited[neighbor]) { // 방문 X 
            CountSubTree(neighbor, tree, visited, cnt); // 해당 노드 기준 서브트리 계산
            cnt[cur] += cnt[neighbor]; // 현재 노드에 neighbor의 서브트리 더해줌
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N, R, Q; // 정점 수, 루트 번호, 쿼리 수
    int v1, v2; // 양 끝점 
    int U; // 서브트리 수 구할 정점 

    cin >> N >> R >> Q;

    // 트리 생성 
    vector<vector<int>> tree(N + 1, vector<int>());
    for (int i = 0; i < N - 1; i++) {
        cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    vector<bool> visited(N + 1, false);
    vector<int> cnt(N + 1, 1);  // 각 노드의 초기 하위 트리 크기는 1로 설정
    CountSubTree(R, tree, visited, cnt);

    for (int i = 0; i < Q; i++) {
        cin >> U;
        cout << cnt[U] << "\n";
    }
    return 0;
}
