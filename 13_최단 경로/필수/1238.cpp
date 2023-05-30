// 파티
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5;

// 목적지에서 집(각 정점)까지 돌아가는 최단경로
vector<int> dijkstraCome(int start, int n, vector<vector<ci>> &way){
    vector<int> dist(n+1, INF); 
    priority_queue<ci, vector<ci>> pq;
    
    dist[start] = 0;
    pq.push({start, 0});
    
    while (!pq.empty()){
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if (dist[node] < weight){
            continue;
        }
        
        for (int i = 0; i < way[node].size(); i++){
            int next_node = way[node][i].first;
            int next_weight = weight + way[node][i].second;
            if (dist[next_node] > next_weight){
                dist[next_node] = next_weight;
                pq.push({next_node, next_weight});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, x, start, end, t, max_cost = 0;
    cin >> n >> m >> x;
    vector<vector<ci>> way_go(n+1, vector<ci>(0)); // i가 출발지일 때 목적지와 시간 저장
    vector<vector<ci>> way_come(n+1, vector<ci>(0)); // i가 목적지일 때 출발지와 시간 저장
    
    for (int i = 2; i <= m+1; i++){
        cin >> start >> end >> t;
        way_go[start].push_back({end, t}); 
        way_come[end].push_back({start, t});
    }
    
    vector<int> dist_go = dijkstraCome(x, n, way_go); // 목적지에서 집(각 정점)까지 돌아가는 최단 경로
    vector<int> dist_come = dijkstraCome(x, n, way_come); // 각 정점에서 목적지까지 가는 최단경로 (목적지에 도착하도록 하는 경로로 거꾸로 탐색)
    
    // 오고 가는데 가장 오래 걸리는 시간
    for (int i = 1; i<=n; i++){
       max_cost = max(max_cost, dist_go[i] + dist_come[i]); 
    }
    cout << max_cost;
    return 0;
}