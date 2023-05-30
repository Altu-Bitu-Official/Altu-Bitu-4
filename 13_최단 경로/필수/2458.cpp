#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

void floydWarshall(int n, vector<vector<int>> &graph)
{
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (graph[i][j] > graph[i][k] + graph[k][j]) 
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    int ans = 0;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) 
    {
        graph[i][i] = 0; 
    }

    while(m--) 
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1; 
    }

    floydWarshall(n, graph);

    for (int i = 1; i <= n; i++) 
    {
        bool flag = true;

        for (int j = 1; j <= n; j++) 
        {
            if (graph[i][j] == INF && graph[j][i] == INF) 
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
