#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상 정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {
    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { 
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int node = pq.top(); // 가장 쉬운 문제부터
        pq.pop();

        result.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; 
            if (!indegree[next_node]) {
                pq.push(next_node);
            }
        }
    }
    return result;
}

/*
 * 조건 1, 2까지는 기본적인 위상정렬
 * 조건 3 "가능하면 쉬운 문제부터 풀어야 한다." -> 위상정렬 시, 정점이 작은 순서부터
 * 조건 3을 만족시키기 위해, 진입 차수가 0인 정점을 담는 컨테이너로 큐 대신 우선순위 큐 사용
 */

int main() {
    int n, m, a, b;

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); // 각 정점의 진입차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); // 인접 리스트 그래프
    while (m--) {
        cin >> a >> b; // a -> b
        graph[a].push_back(b);
        indegree[b]++;
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}