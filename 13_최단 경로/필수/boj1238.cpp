#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e9; // 무한대 값

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }

    return dist;
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<vector<ci>> reverse_graph(n + 1, vector<ci>(0)); // 역방향 그래프 생성

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({ b, t });
        reverse_graph[b].push_back({ a, t }); // 역방향 그래프에 추가
    }

    vector<int> forward_dist = dijkstra(x, n, graph); // X에서 각 마을로 가는 최단 시간
    vector<int> reverse_dist = dijkstra(x, n, reverse_graph); // 각 마을에서 X로 돌아오는 최단 시간

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        int total_time = forward_dist[i] + reverse_dist[i]; // 왕복시간 계산
        max_time = max(max_time, total_time);
    }

    cout << max_time << endl;

    return 0;
}
/*hi*/