// 트리의 지름
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ci;

/* weight가 더해지면서 탐색의 depth가 늘어나고 최종적으로 node와 가중치가 return된다
* return 될 때 cur 노드의 자식 노드 중에서 weight가 가장 큰 노드로 갱신
* 결국 root 에서 가장 먼 노드 번호와 weigth가 return됨!!
*/

ci dfs(int cur, int prev, vector<vector<ci>>& graph, int weight){
    int max_node = cur;
    int max_edge = weight;
    
    for (int i = 0; i < graph[cur].size(); i++){
        int next_node = graph[cur][i].first;
        int next_edge = graph[cur][i].second;
        
        if (next_node == prev){
            continue;
        }
        ci search = dfs(next_node, cur, graph, weight+next_edge); // 자식 노드에 대해서 dfs 탐색
        
        if (search.second > max_edge){
            max_node = search.first;
            max_edge = search.second;
        }
    }
    return {max_node, max_edge};
}
/*
 1. 지름을 이루는 두 점은 모두 리프 노드
 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 */
int main()
{
    int n, x, y, l;
    cin >> n;
    vector<vector<ci>> graph(n+1, vector<ci>(0));
    for (int i = 0; i < n-1; i++){
        cin >> x >> y >> l;
        graph[x].push_back({y,l}); 
        graph[y].push_back({x,l});
    }
    // 1. 루트에서 가장 먼 노드 찾기
    ci farmost = dfs(1,-1,graph,0);
    // 2. 1에서 찾은 노드에서 가장 먼 노드 찾기
    ci another_farmost = dfs(farmost.first, -1, graph, 0);
    
    cout << another_farmost.second;
    return 0;
}