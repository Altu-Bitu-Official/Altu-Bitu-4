#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> graph[MAX_N]; // 인접 리스트 각 노드마다 연결된 노드들을 리스트 형태로 저장!
vector<int> dp(MAX_N, 0); // 어떤 노드의 서브트리에 존재하는 노드 개수

int dfs(int root) 
{
    dp[root] = 1; //leaf node 도 서브트리는 1개

    for (int i = 0; i < graph[root].size(); i++) 
    {
        int child = graph[root][i];
        
        if (dp[child] == 0) //부모노드 말고 자식노드만 볼 수 있도록 
        {
            dp[root] += dfs(child); //재귀로 호출
        }
    }

    return dp[root];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    //인접리스트로 그래프 표현
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // DFS를 사용
    dfs(r);//5
    
    while (q--) {
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }
    
    return 0;
}
