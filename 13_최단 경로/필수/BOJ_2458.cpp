#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 500;    //정점 간 거리를 1이라고 했을 때 모든 정점을 거친 거리 : 499.

//정점의 개수와 그래프를 받고 정점 간 최단거리(연결되는지 여부)를 계산하는 함수
void floydWarshall(int n, vector<vector<int>>& graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

//특정 정점과 정점의 개수, 그래프를 받고 그 정점의 학생이 키를 알 수 있는지 여부를 리턴하는 함수
bool checkKnowHeight(int node, int n, vector<vector<int>>& graph) {
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == INF) {    //연결되어 있지 않는 노드일 때
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        if (graph[q.front()][node] == INF) {    //반대로도 연결되어 있지 않을 때 -> 키 순서 파악 불가.
            return false;
        }
        q.pop();
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b, cnt = 0;
    vector<vector<int>> graph;

    cin >> n >> m;
    graph.assign(n+1, vector<int> (n+1, INF));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    while (m--) {
        cin >> a >> b;
        graph[a][b] = 1;
    }

    floydWarshall (n, graph);   //그래프 간 연결 여부를 플로이드-워셜로 계산

    //모든 정점에 대해 자신의 키가 몇 번째인지 알 수 있는지 계산
    for (int i = 1; i <= n; i++) {  
        if (checkKnowHeight(i, n, graph)) {
            cnt++;
        }
    }
    //출력
    cout << cnt;
}