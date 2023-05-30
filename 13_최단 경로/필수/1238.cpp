// 1238 파티
// 다익스트라 알고리즘
/*
문제 해석:
(1번 학생 집-> 파티장소)+(파티장소->1번 학생 집) vs ... vs(i번째 학생 집->파티장소)+(파티장소->i번째 학생 집) 거리 중 최댓값을 구하는 것
파티장소를 출발점으로 다익스트라 돌리고(step1), 뒤집은 그래프로도 출발점을 돌리면 (step2)--> step1+step2=complete
*/ 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e5; 

vector<int> dijkstra(int start, int N, vector<vector<pi>> &adj) {
    vector<int> dist(N + 1, INF); //dist 배열을 INF로 초기화 
    priority_queue<pi, vector<pi>, greater<pi>> pq; // pq 선언

    dist[start] = 0;
    pq.push({0, start});  

    while (!pq.empty()) { 
        int cur_cost = pq.top().first; // 현재까지의 cost값
        int cur = pq.top().second; // cur := 현재 정점
        pq.pop();

        if (cur_cost > dist[cur]) { //이미 더 작은 값으로 기록된 정점이 있다면 
            continue;
        }
        for (int i = 0; i < adj[cur].size(); i++) { // 현재 값과 연결된 모든 정점들을 탐색해본다.
            int nxt = adj[cur][i].first;
            int nxt_cost = cur_cost + adj[cur][i].second; 
            if (nxt_cost < dist[nxt]) { 
                dist[nxt] = nxt_cost;
                pq.push({nxt_cost, nxt}); 
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, X, a, b, c;
    cin >> N >> M >> X;
    vector<vector<pi>> adj(N + 1, vector<pi>(0));
    while(M--){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    vector<int> vr1 = dijkstra(X, N, adj); 

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> vr2 = dijkstra(i, N, adj); // i 부터 X의의 최단 시간 
        ans = max(ans, vr1[i] + vr2[X]); 
    }
 
    cout << ans << "\n";

    return 0;
}