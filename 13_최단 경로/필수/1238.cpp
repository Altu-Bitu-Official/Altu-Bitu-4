#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5; // V * (가중치의 최대값) 

//다익스트라
vector<int> dijkstra(int s, int n, vector<vector<ci>> &graph) {
    vector<int> dist(n + 1, INF); //dist 배열을 INF로 초기화 
    priority_queue<ci, vector<ci>, greater<ci>> pq; //<시작점부터의 거리, 정점>
    
    //시작 정점 초기화 
    dist[s] = 0;
    pq.push({0, s}); //pq queue에 시작점 저장 
    while (!pq.empty()) { //갱신할 정점이 있을 때까지 
        int weight = pq.top().first; //현재 정점까지의 경로값
        int node = pq.top().second; //현재 탐색하려는 정점
                                    //탐색하지 않은 정점 중 시작점에서 가장 가까운 정점 
        pq.pop();

        if (weight > dist[node]) { //이미 더 작은 값으로 기록된 정점이 있다면 
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) { //node와 연결된 모든 정점에 대해 
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 현재 node를 거쳐 
                                                              //다음 정점까지 가는 경로값
            if (next_weight < dist[next_node]) { //최단 경로 값이 갱신된다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node}); 
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //입력
    int n, m, x, s, e, T;
    cin >> n >> m >> x;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    while(m--){
        cin >> s >> e >> T;
        graph[s].push_back({e, T});
    }
    //연산
    vector<int> dist_x = dijkstra(x, n, graph); //최단 시간 저장
    
    int max_T = 0; //최대 시간의 값 초기화 
    for (int i = 1; i <= n; i++) {
        vector<int> dist_i = dijkstra(i, n, graph); // i -> X의의 최단 시간 
        max_T = max(max_T, dist_x[i] + dist_i[x]); //max_T 갱신
    }
        
    //출력 
    cout << max_T;

    return 0;
}