#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5; // n * 가중치의 최대값

vector<int> dijkstra(int start, int n, vector<vector<ci>> &graph) {
    vector<int> dist(n+1, INF);
    dist[start] = 0; // 시작점에서의 시간
    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({0, start}); // 시간, 시작점

    while(!pq.empty()) {
        int time = pq.top().first; // 지금 뽑힌 정점의 time
        int node = pq.top().second;
        pq.pop(); // 안하면 시간초과

        if(time > dist[node]) { // 이미 저장된 시간보다 길다 -> 업데이트할 필요 X 
            continue;
        }

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_time = graph[node][i].second + time;

            if(dist[next_node] > next_time) {
                dist[next_node] = next_time;
                pq.push({next_time, next_node});
            }
        }
    }
    return dist;
}

int findLongest(int x, int n,  vector<vector<ci>> &graph) {
    int ans = 0;
    vector<int> back = dijkstra(x, n, graph); // 오는 시간
    for(int i = 1; i <= n; i++) {
        int time = dijkstra(i, n, graph)[x] + back[i]; // 가는 시간 + 오는 시간
        ans = max(ans, time); // 최대값 구하기
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, x, a, b, t;

    // 입력
    cin >> n >> m >> x; // x: 파티 목적지
    vector<vector<ci>> graph(n+1, vector<ci>(0));

    while(m--) {
        cin >> a >> b >> t;
        graph[a].push_back({b, t}); // 단방향 도로
    }

    // 연산
    int ans = findLongest(x, n, graph);

    // 출력
    cout << ans << '\n';

    return 0;
}