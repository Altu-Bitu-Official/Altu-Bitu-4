#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> distance(graph.size(), INF);
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (distance[node] < dist) {
            continue;
        }

        for (const auto& edge : graph[node]) {
            int next_node = edge.first;
            int next_dist = edge.second;
            int cost = dist + next_dist;

            if (cost < distance[next_node]) {
                distance[next_node] = cost;
                pq.push(make_pair(cost, next_node));
            }
        }
    }

    return distance;
}

int solution(int N, int M, int X, const vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reverse_graph(N + 1);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        graph[u].push_back(make_pair(v, w));
        reverse_graph[v].push_back(make_pair(u, w));
    }

    vector<int> forward_distance = dijkstra(graph, X);
    vector<int> backward_distance = dijkstra(reverse_graph, X);

    int max_distance = 0;
    for (int i = 1; i <= N; i++) {
        int distance = forward_distance[i] + backward_distance[i];
        max_distance = max(max_distance, distance);
    }

    return max_distance;
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int>> edges(M, vector<int>(3));

    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int answer = solution(N, M, X, edges);
    cout << answer << "\n";

    return 0;
}
