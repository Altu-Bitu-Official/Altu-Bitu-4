#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001
#define INF 1e9
using namespace std;

int N, M, X;
vector<pair<int, int>> graph[MAX];
int dist[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<graph[here].size(); i++) {
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> X;
    for(int i=0; i<M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back(make_pair(b, t));
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        fill(dist, dist+MAX, INF);
        dijkstra(i);
        int temp = dist[X];
        fill(dist, dist+MAX, INF);
        dijkstra(X);
        temp += dist[i];
        result = max(result, temp);
    }
    cout << result;
    return 0;
}
