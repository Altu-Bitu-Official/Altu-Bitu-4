#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e5;    //최대 거리 : 1000 * 100 = 1e5

//시작 정점과 전체 정점의 개수, 그래프를 받아 시작 정점에 따른 모든 정점의 최단 경로를 리턴하는 함수
vector<int> dijkstra(int start, int v, vector<vector<pi>>& graph) {
    vector<int> dist(v+1, INF);  
    priority_queue<pi, vector<pi>, greater<pi>> pq; 

    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {  //뽑은 거리가 이미 저장된 거리보다 클 때 -> continue.
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, x, a, b, w, max_dist = -1;

    cin >> n >> m >> x;
    vector<vector<pi>> graph(n+1, vector<pi>(0));
    vector<vector<int>> dist (n+1, vector<int>(n+1, 0));

    while (m--) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    //정점 별로 모든 정점에 대한 최단경로를 구함.
    for (int i = 1; i <= n; i++) {
        dist[i] = dijkstra(i, n, graph);
    }

    vector<int> dist_sum = dijkstra(x, n, graph);   //파티장에서 모든 정점으로 돌아오는 최단 경로

    //파티장에서 돌아오는 정점에 정점에서 파티장으로 가는 최단경로의 합을 구함.
    for (int i = 1; i <= n; i++) {
        dist_sum[i] += dist[i][x];
        max_dist = max(max_dist, dist_sum[i]);  //최댓값 갱신
    }

    //출력
    cout << max_dist;

}