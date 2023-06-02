#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 1e7; // 정적의 개수 V * (가중치의 최대값)
using namespace std;

void foydWarshall(int n, vector<vector<int>> &graph)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
        }
    }
}

int main()
{

    int n, m, a, b, c; // 도시의 개수 n, 버스의 개수m ,이동 비용c
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    while (m--)
    {
        cin >> a >> b >> c;
    }
}