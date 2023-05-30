#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5; // v * 가중치와 최대값 이유는 나중에

int main()
{
    int v, e, k, a, b, w;

    cin >> v >> e >> k; // 정점의 개수v, 간선의 개수e, 간선의 가중치 w
    vector<vector<ci>> graph(v + 1, vector<ci>(0));
}