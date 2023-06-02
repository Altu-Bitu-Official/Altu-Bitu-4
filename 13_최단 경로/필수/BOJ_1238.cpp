#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e6;
vector<vector<ci>> graph, rev_graph; // 이중벡터 순방향 그래프, 역방향 그래프 선언

vector<int> dijkstra(int start, int n, vector<vector<ci>> g)
{
    vector<int> time(n + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // 시작 지점 초기화
    time[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > time[node])
            continue; // 이미 방문한 노드는  pass

        for (int i = 0; i < g[node].size(); i++)
        {
            int new_node = g[node][i].first;
            int new_weight = weight + g[node][i].second;

            if (time[new_node] > new_weight)
            { // 더 짧은 경로 발견시에
                time[new_node] = new_weight;
                pq.push({new_weight, new_node});
            }
        }
    }
    return time;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x; // n명의 학생 , m개의 단방향 도로, 할당시간 x

    // 단방향과 역방향을 모두 0으로 init
    graph.assign(n + 1, vector<ci>(0));
    rev_graph.assign(n + 1, vector<ci>(0));

    while (m--)
    { // m개의 간선
        int a, b, tm;
        cin >> a >> b >> tm;

        // a에서 b로 가는데의 가중치 : tm
        graph[a].push_back({b, tm});
        rev_graph[b].push_back({a, tm});
    }

    vector<int> go = dijkstra(x, n, rev_graph); // 모든 정점에서 x로 가는 최단 경로
    vector<int> back = dijkstra(x, n, graph);   // x에서 모든 정점까지 가는 최단 경로

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, go[i] + back[i]); // 가장 오래걸리는 시간
    }

    // 출력
    cout << ans;
    return 0;
}
