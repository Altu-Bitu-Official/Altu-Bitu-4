#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5; // V * (가중치의 최대값) 
// X번 마을에 왕복하는 데 가장 오래 걸리는 학생의 시간 출력

// 다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장
    priority_queue<ci, vector<ci>, greater<ci>> pq; // first: 시작점으로부터의 거리, second: 정점

    // 시작 정점 초기화
    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int node = pq.top().second; // 현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) { // 이미 더 작은 값으로 기록된 정점
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; // 연결된 정점
            // 시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) { // 최단 경로 값이 갱신된다면
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, X; // 학생 수, 단방향 도로 수, 모이는 마을 번호
    int start, end, T; // 시작점, 끝점, 소요시간 (=가중치)
    cin >> N >> M >> X;
    vector<vector<ci>> graph(N + 1, vector<ci>(0));

    while (M--) {
        cin >> start >> end >> T;
        graph[start].push_back({ end, T });
    }
    vector<int> dist_X = dijkstra(X, N, graph); // ( X -> 모든 정점) 최단 시간 저장

    int max_time = 0; // 최대 소요시간 초기화
    for (int i = 1; i <= N; i++) {
        if (i == X) continue; // 모이는 마을은 제외
        vector<int> dist_i = dijkstra(i, N, graph); // (학생 위치 i -> X) 최단 시간 
        max_time = max(max_time, dist_X[i] + dist_i[X]);
        // 왕복 시간 = ( X -> 학생 위치 i ) + ( 학생 위치 i -> X ) 
    }
    cout << max_time;
    return 0;
}
