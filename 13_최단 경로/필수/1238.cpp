#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

const int INF = 1000000;

typedef pair<int, int> ci;

int dijkstra(vector<vector<ci>> &nodes, int start, int dest, int n){
    vector<int> dist(n+1, INF);

    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작정점 초기화
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int node = pq.top().second; // 현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) { // 이미 더 작은 값으로 기록된 정점
            continue;
        }
        for (int i = 0; i < nodes[node].size(); i++) {
            int next_node = nodes[node][i].first; // 연결된 정점
            // 시작점으로부터 현재 node를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + nodes[node][i].second;
            if (next_weight < dist[next_node]) { // 최단 경로 값이 갱신된다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist[dest];
}

int result(vector<vector<ci>> &nodes, int dest, int n){
    int tmp, result = 0;
    // 모든 학생의 파티까지의 왕복 거리에 대해서 dijkstra알고리즘 실행
    for(int i=1; i<=n; i++){
        // tmp는 시작점에서 파티장소까지 갈 떄의 거리와 파티장소에서 시작점으로 돌아올 떄의 거리 합
        tmp = dijkstra(nodes, i, dest, n) + dijkstra(nodes, dest, i, n);
        // result와 tmp중 값이 더 큰 것으로 result를 갱신
        result = max(result, tmp);
    }
    return result;
}

int main(){
    int n, m, x;
    int start, end, time;
    cin >> n >> m >> x;

    // 연결리스트
    vector<vector<ci>> nodes(n+1, vector<ci>(0));

    // 입력
    for(int i=0; i<m; i++){
        cin >> start >> end >> time;
        nodes[start].push_back({end, time});
    }
    // 연산과 출력
    cout << result(nodes, x, n);
}