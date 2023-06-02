#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321; 

vector<int> dijkstra(int start, int N, const vector<vector<pair<int, int>>>& graph) 
{
    vector<int> distance(N + 1, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) 
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist > distance[cur])
            continue;

        for (int i = 0; i < graph[cur].size(); i++) 
        {
            int next = graph[cur][i].first;
            int weight = graph[cur][i].second;

            if (distance[next] > dist + weight) 
            {
                distance[next] = dist + weight;
                pq.push({distance[next], next});
            }
        }

    }

    return distance;
}

int main() 
{
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) 
    {

        int start, end, time;
        cin >> start >> end >> time;
        graph[start].push_back({end, time});
    }

    vector<int> a = dijkstra(X, N, graph);

    int maxTime = 0;

    for (int i = 1; i <= N; i++) 
    {
        if (i == X)
        {
            continue;
        }
        vector<int> b = dijkstra(i, N, graph);
        maxTime = max(maxTime, a[i] + b[X]);
    }

    cout << maxTime;

    return 0;
}