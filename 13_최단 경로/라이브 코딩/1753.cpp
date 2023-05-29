// 최단경로
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5; // V*가중치의 최댓값

vector<int>dijkstra(int start, int v, vector<vector<ci>> &graph){
    vector<int> dist(v+1, INF); // 각 정점까지의 최단 경로 저장
    priority_queue<ci, vector<ci>, greater<>> pq; // first: 시작점으로부터의 거리, second: 정점
    
    dist[start] = 0; // 출발 지점의 최단경로는 0
    pq.push({0,start});
    
    while (!pq.empty()){
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int node = pq.top().second; // 현재 탐색하려는 정점
        pq.pop();
        
        if (weight > dist[node]){ // 업데이트를 할 필요가 없을 때
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++){
            int next_node = graph[node][i].first; // 연결된 정점
            // 시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]){
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
        
    }
    return dist;
}

int main()
{
    int v, e, k, a, b, w;
    
    cin >> v >> e >> k;
    vector<vector<ci>> graph(v+1, vector<ci>(0));
    while (e--){
        cin >> a >> b >> w; // 출발, 도착, 가중치
        graph[a].push_back({b,w});
    }
    // 연산
    vector<int> dist = dijkstra(k, v, graph);
    //출력
    for (int i = 1; i<=v; i++){
        if (dist[i] == INF){
            cout << "INF";
        }
        else{
            cout << dist[i];
        }
        cout << '\n';
    }
    return 0;
}